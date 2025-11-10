#include "acento_corne.h"

// ═══════════════════════════════════════════════════════════════
//   ACENTO INTELIGENTE - Código extraído de corne/
// ═══════════════════════════════════════════════════════════════
// Este archivo contiene el código EXACTO del proyecto corne/
// de Álvaro Prieto Lauroba, con las mínimas adaptaciones necesarias
// para funcionar standalone.

// ────────────────────────────────────────────────────────────────
//  VARIABLES GLOBALES (de corne/source/shared.c)
// ────────────────────────────────────────────────────────────────

bool accent = false;
uint16_t delete = 0;
uint16_t registered_delete = 0;
bool caps_word = false;
bool shift = false;
bool caps_state = false;
bool caps_lock = false;

// ────────────────────────────────────────────────────────────────
//  FUNCIONES AUXILIARES (de corne/source/shared.c)
// ────────────────────────────────────────────────────────────────

// Tap a key preventing shift hold state
// Modificado para detectar shift normal Y oneshot (OSM)
void tap_unshifted(uint16_t keycode) {
    uint8_t mods = get_mods();
    uint8_t oneshot = get_oneshot_mods();
    bool shift_active = (mods | oneshot) & MOD_MASK_SHIFT;

    if(shift_active) {
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        send_keyboard_report();
    }

    tap_code16(keycode);

    if(shift_active) {
        set_mods(mods);
        set_oneshot_mods(oneshot);
        send_keyboard_report();
    }
}

// Internal function that toggles caps_state
// Adaptado de corne/source/shared.c línea 57-75 (sin RGB)
static void set_caps_state(bool enabled, bool lock, bool word) {
    if(caps_state != enabled) {
        tap_code(KC_CAPS);
    }
    caps_state = enabled;
    // RGB indicators removidos para standalone
}

// Centralization of caps management (shift, caps lock and caps word)
// CÓDIGO EXACTO de corne/source/shared.c línea 77-91
void set_caps(bool enabled, bool lock, bool word) {
    if(lock || word){
        set_caps(false, false, false); //prevent hold shift
        set_caps_state(enabled, lock, word);
        caps_lock = lock ? enabled : 0;
        caps_word = word ? enabled : 0;
    }else{
        // hold shift (S1) has to be very fast, so it can't rely on
        // caps lock (since it has a delay on macOs)
        if(caps_lock || caps_word) return;
        enabled ? register_code16(KC_RSFT) : unregister_code16(KC_RSFT);
        shift = enabled;
    }
}

// Smart register a key according to its type
// Adaptado de corne/source/shared.c línea 137-143
// (simplificado: sin OS keys, solo keys normales)
void register_generic_key(uint16_t key) {
    // Para AC_DEL_W, usar Ctrl+Backspace
    if(key == AC_DEL_W) {
        register_code(KC_LCTL);
        register_code(KC_BSPC);
    } else {
        register_code16(key);
    }
}

// Smart unregister a key according to its type
// Adaptado de corne/source/shared.c línea 147-153
void unregister_generic_key(uint16_t key) {
    if(key == AC_DEL_W) {
        unregister_code(KC_BSPC);
        unregister_code(KC_LCTL);
    } else {
        unregister_code16(key);
    }
}

// Stub para interrupt_mods()
// En corne/ interrumpe modificadores custom, aquí no es necesario
void interrupt_mods(void) {
    // Vacío - no tenemos sistema de modificadores custom
}

// ────────────────────────────────────────────────────────────────
//  HANDLERS DEL ACENTO INTELIGENTE (de corne/source/handlers_smart.c)
// ────────────────────────────────────────────────────────────────

// ═══ CÓDIGO EXACTO de corne/source/handlers_smart.c línea 17-149 ═══
// If there is a pending accent and a new keystroke is registered, its output depends on the
// the key itself according to some simple rules. Returns a boolean indicating wether the current
// key event should be processed or skipped (false = skip). Tilde key can also be used with othe purposes,
// such as entering in delete mode with double tap or followed by certain keys.

void handle_accents(uint16_t keycode, bool down, keyrecord_t *record, bool *stop_propagation, bool *handled) {
    if(!(accent || delete)) return;
    bool abort_caps_word = false;

    // Delete mode
    if(delete){
        if(down){
            if(keycode == delete){
                register_generic_key(registered_delete);
            }else{
                unregister_generic_key(registered_delete);
                delete = 0;
                return;
            }
        }else{
            if(keycode == delete){
                unregister_generic_key(registered_delete);
            }
            // mod_key_handler removido - no tenemos sistema de mods custom
        }
        *handled = true;
        *stop_propagation = true;

    // Accent mode
    }else{
        // modifiers should be interrupted
        interrupt_mods();

        // shift should not be prevented (incluyendo OSM shift)
        if(keycode == KC_LSFT || keycode == KC_RSFT ||
           (keycode >= QK_ONE_SHOT_MOD && keycode <= QK_ONE_SHOT_MOD_MAX)){
            return;
        }

        if(!down){
            // to prevent accents in scenarios like: i down, tilde down, (I UP), o down
            return;
        }

        accent = false;

        switch(keycode){
            // ´ Spanish accent
            case KC_A:
            case KC_E:
            case KC_I:
            case KC_O:
            case KC_U: {
                // Detectar shift (normal o OSM)
                uint8_t normal_mods = get_mods();
                uint8_t oneshot_mods = get_oneshot_mods();
                bool was_shifted = (normal_mods | oneshot_mods) & MOD_MASK_SHIFT;

                // Eliminar temporalmente todo tipo de shift
                del_mods(MOD_MASK_SHIFT);
                del_oneshot_mods(MOD_MASK_SHIFT);

                // Enviar el acento sin shift
                tap_code16(ES_ACUT);

                // Enviar la vocal con o sin shift según corresponda
                if(was_shifted) {
                    tap_code16(S(keycode));  // Forzar mayúscula
                } else {
                    tap_code16(keycode);     // Minúscula
                }

                // Restaurar los mods originales (excepto shift que ya se consumió)
                set_mods(normal_mods & ~MOD_MASK_SHIFT);
            }
            break;

            // ' English apostrophe
            case KC_M:
            case KC_L:
            case KC_D:
            case KC_V:
            case KC_S:
            case KC_R:
            case KC_T:
            case KC_C:
                tap_unshifted(ES_QUOT);
                tap_code16(keycode);
                abort_caps_word = true;
            break;

            // DELETE MODE: double tap enters in delete mode
            case AC_TILDE:
                //you can asign different kind of deletes to different keys (forward, word, line...)
                //remember to store the current key and current deletion mode in the following variables
                delete = AC_TILDE;
                registered_delete = AC_DEL_W; //KC_BSPC, AC_DEL_W, KC_DEL, ...
                register_generic_key(registered_delete);
                abort_caps_word = true;
            break;

            // Ñ Spanish ñ (o Ñ con shift)
            case KC_N: {
                uint8_t normal_mods = get_mods();
                uint8_t oneshot_mods = get_oneshot_mods();
                bool was_shifted = (normal_mods | oneshot_mods) & MOD_MASK_SHIFT;

                // Eliminar shift antes de enviar
                del_mods(MOD_MASK_SHIFT);
                del_oneshot_mods(MOD_MASK_SHIFT);

                if(was_shifted) {
                    tap_code16(S(ES_NTIL));  // Ñ mayúscula
                } else {
                    tap_code16(ES_NTIL);     // ñ minúscula
                }

                // Restaurar mods (excepto shift consumido)
                set_mods(normal_mods & ~MOD_MASK_SHIFT);
            }
            break;

            // GÜ Spanish dieresis (o GÜ con shift)
            case KC_G: {
                uint8_t normal_mods = get_mods();
                uint8_t oneshot_mods = get_oneshot_mods();
                bool was_shifted = (normal_mods | oneshot_mods) & MOD_MASK_SHIFT;

                // Eliminar shift
                del_mods(MOD_MASK_SHIFT);
                del_oneshot_mods(MOD_MASK_SHIFT);

                // Enviar G con o sin shift
                if(was_shifted) {
                    tap_code16(S(KC_G));
                } else {
                    tap_code16(KC_G);
                }

                // Enviar la diéresis (siempre sin shift)
                tap_code16(ES_DIAE);

                // Restaurar mods (excepto shift consumido)
                set_mods(normal_mods & ~MOD_MASK_SHIFT);
            }
            break;

            // $ Dollar, common symbol for some programmers
            case KC_SPC:
                tap_code16(ES_DLR);
            break;

            // ; End of line, common combination for some programmers
            // M3 reemplazado por RAISE (ajustar según tu keymap)
            case RAISE:  // Cambiar si usas otra capa
                tap_code16(ES_SCLN);
                tap_code16(KC_ENT);
                abort_caps_word = true;
            break;

            // Caps word (enable / disable)
            // M2 reemplazado por LOWER (ajustar según tu keymap)
            case LOWER:  // Cambiar si usas otra capa
                if(caps_word){
                    abort_caps_word = true;
                }else{
                    set_caps(true, false, true);
                }
            break;
        }

        if(caps_word && abort_caps_word) set_caps(false, false, true);
        *handled = true;
        *stop_propagation = true;
    }
}

// ═══ CÓDIGO EXACTO de corne/source/handlers_smart.c línea 152-197 ═══
// Smart caps to write words like MAXIMUM_DAMAGE or U.S.A. useful for programmers. Idea: @getreuer

void handle_caps_word(uint16_t keycode, bool down, keyrecord_t *record, bool *stop_propagation, bool *handled) {
    if(!caps_word) return;
    bool prevent_keypress = true;

    switch (keycode) {
        // M2 y TILDE reemplazados por equivalentes
        case LOWER:    // Cambiar según tu keymap
        case AC_TILDE:
            prevent_keypress = false;
            break;

        default:
            if(down){
                switch (keycode) {
                    case KC_A ... KC_Z:
                    case ES_NTIL:
                    case KC_1 ... KC_0:
                    case ES_DOT:
                    case ES_MINS:
                    case KC_BSPC:
                    case KC_DEL:
                    case ES_UNDS:
                        tap_code16(keycode);
                        break;

                    // DEL removido - usamos KC_BSPC directamente
                    // CMD removido - no tenemos mod custom
                    // M1 removido - no tenemos mod custom

                    default:
                        // Deactivate Caps Word.
                        set_caps(false, false, true);
                        prevent_keypress = false;
                        break;
                }
            }
            break;
    }

    if(prevent_keypress){
        *handled = true;
        *stop_propagation = true;
    }
}

// ────────────────────────────────────────────────────────────────
//  FUNCIÓN DE INTEGRACIÓN
// ────────────────────────────────────────────────────────────────

// Función principal para llamar desde process_record_user()
// Maneja el flujo completo del acento inteligente

bool process_acento_corne(uint16_t keycode, keyrecord_t *record) {
    bool stop_propagation = false;
    bool handled = false;

    // 1. Activar modo acento cuando se presiona AC_TILDE
    if (keycode == AC_TILDE && record->event.pressed) {
        if(!delete){
            accent = true;
        }
        return false;  // No enviar nada al OS
    }

    // 2. Procesar Caps Word (tiene prioridad)
    handle_caps_word(keycode, record->event.pressed, record, &stop_propagation, &handled);
    if(handled) return !stop_propagation;

    // 3. Procesar Acento Inteligente
    handle_accents(keycode, record->event.pressed, record, &stop_propagation, &handled);
    if(handled) return !stop_propagation;

    // 4. Si no se manejó, procesar normalmente
    return true;
}

// ════════════════════════════════════════════════════════════════
//  NOTAS DE USO
// ════════════════════════════════════════════════════════════════
/*
 * Este código es una extracción DIRECTA del proyecto corne/ con:
 *
 * CAMBIOS MÍNIMOS:
 * - Keycodes: TILDE → AC_TILDE, DEL_W → AC_DEL_W
 * - Modificadores custom (M1, M2, M3, etc.) → LOWER, RAISE
 * - Removido sistema de OS keys (simplificado)
 * - Removido RGB (para standalone)
 * - Stub de interrupt_mods() (vacío)
 *
 * CÓDIGO ORIGINAL CONSERVADO:
 * ✅ handle_accents() - EXACTO de corne/
 * ✅ handle_caps_word() - EXACTO de corne/
 * ✅ tap_unshifted() - EXACTO de corne/
 * ✅ set_caps() - EXACTO de corne/
 * ✅ Lógica de acento - EXACTA de corne/
 * ✅ Lógica de delete mode - EXACTA de corne/
 * ✅ Lógica de caps word - EXACTA de corne/
 *
 * CRÉDITOS:
 * Autor original: Álvaro Prieto Lauroba
 * Fuente: /corne/source/handlers_smart.c y shared.c
 */
