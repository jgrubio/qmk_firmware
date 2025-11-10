#pragma once
#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

// ═══════════════════════════════════════════════════════════════
//   ACENTO INTELIGENTE - Extraído directamente de corne/
// ═══════════════════════════════════════════════════════════════
// Este es el código EXACTO del proyecto corne/ de Álvaro Prieto
// Solo se han extraído las partes mínimas necesarias

// ────────────── Keycodes Custom ──────────────
// Definidos aquí para que sean visibles tanto en keymap.c como en acento_corne.c

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    VIM_QUIT,
    VIM_SAVE,
    AC_TILDE,   // Acento inteligente
    AC_DEL_W,   // Borrar palabra (para modo delete)
};

// ────────────── Variables Globales ──────────────
// Extraídas de corne/source/shared.h/c
extern bool accent;            // Modo acento activo
extern uint16_t delete;        // Modo delete activo (0 = desactivado)
extern uint16_t registered_delete;  // Tipo de delete registrado
extern bool caps_word;         // Caps Word activo
extern bool shift;             // Shift presionado
extern bool caps_state;        // Estado de Caps Lock
extern bool caps_lock;         // Caps Lock activo

// ────────────── Funciones Auxiliares ──────────────
// Extraídas de corne/source/shared.c

// Presiona una tecla sin shift (para acentos)
void tap_unshifted(uint16_t keycode);

// Manejo de mayúsculas (shift, caps lock, caps word)
void set_caps(bool enabled, bool lock, bool word);

// Registrar/des-registrar teclas genéricas
void register_generic_key(uint16_t key);
void unregister_generic_key(uint16_t key);

// Interrumpir modificadores (stub para compatibilidad)
void interrupt_mods(void);

// ────────────── Handlers del Acento Inteligente ──────────────
// Extraídos de corne/source/handlers_smart.c

// Handler principal del acento inteligente
// CÓDIGO EXACTO de handle_accents() en corne/source/handlers_smart.c
void handle_accents(uint16_t keycode, bool down, keyrecord_t *record, bool *stop_propagation, bool *handled);

// Handler de Caps Word
// CÓDIGO EXACTO de handle_caps_word() en corne/source/handlers_smart.c
void handle_caps_word(uint16_t keycode, bool down, keyrecord_t *record, bool *stop_propagation, bool *handled);

// ────────────── Función de Integración ──────────────
// Llamar desde process_record_user()
bool process_acento_corne(uint16_t keycode, keyrecord_t *record);
