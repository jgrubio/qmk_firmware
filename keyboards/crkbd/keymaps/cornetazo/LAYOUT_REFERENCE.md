# Referencia de Capas del Teclado Corne (Cornetazo)

Este documento muestra las teclas finales que se envían en cada capa, con los caracteres reales en lugar de los códigos QMK.

## Capa 0: QWERTY (Capa Base)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ Tab │  Q  │  W  │  E  │  R  │  T  │              │  Y  │  U  │  I  │  O  │  P  │ Del │
├─────┼─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┼─────┤
│ Alt │  A  │  S  │  D  │  F  │  G  │              │  H  │  J  │  K  │  L  │  -  │  ´  │
├─────┼─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┼─────┤
│Shift│  Z  │  X  │  C  │  V  │  B  │              │  N  │  M  │  ,  │  .  │  :  │Func │
└─────┴─────┴─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │Ctrl │Enter│Lower│              │Raise│Space│Shift│
                  │     │(Win)│(Tab)│              │(Bksp│     │     │
                  └─────┴─────┴─────┘              └─────┴─────┴─────┘
```

### Modificadores especiales:
- **Alt**: One-Shot Modifier (se activa para la siguiente tecla)
- **Ctrl**: One-Shot Modifier (se activa para la siguiente tecla)
- **Shift**: One-Shot Modifier (se activa para la siguiente tecla)
- **Enter (Win)**: Enter normal, Win al mantener
- **Lower (Tab)**: Tab normal, cambia a capa Lower al mantener
- **Raise (Bksp)**: Backspace normal, cambia a capa Raise al mantener
- **Func**: One-Shot Layer (activa capa Func para una tecla)

### Combos disponibles:
- **D + F**: Produce comillas dobles `"`
- **J + K**: Produce Escape
- **N + ´**: Produce `ñ`

---

## Capa 1: LOWER (Números y Símbolos)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │  ¨  │  [  │  ]  │  ¿  │  ?  │              │  7  │  8  │  9  │  0  │  %  │     │
├─────┼─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  €  │  ¡  │  !  │  (  │  )  │              │  4  │  5  │  6  │  '  │  `  │AltGr│
├─────┼─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │  ~  │  &  │  ^  │  $  │              │  1  │  2  │  3  │  #  │  @  │     │
└─────┴─────┴─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │█████│              │     │     │  .  │
                  └─────┴─────┴─────┘              └─────┴─────┴─────┘
```

### Notas:
- Esta capa se activa manteniendo Tab (Lower)
- La tecla Lower (█████) mantiene la capa activa
- AltGr: One-Shot Modifier para teclas muertas

---

## Capa 2: RAISE (Navegación y Operadores)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │ Del │     │  _  │  +  │PgUp │              │  *  │     │     │  /  │  |  │     │
├─────┼─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │Home │ End │  \  │  =  │PgDn │              │  ←  │  ↓  │  ↑  │  →  │Menu │AltGr│
├─────┼─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  <  │  >  │Copy │Paste│  ;  │              │Play │Prev │Next │Vol- │Vol+ │     │
└─────┴─────┴─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │Ctrl │     │     │              │█████│     │     │
                  │(Esc)│     │     │              └─────┴─────┴─────┘
                  └─────┴─────┴─────┘
```

### Notas:
- Esta capa se activa manteniendo Backspace (Raise)
- La tecla Raise (█████) mantiene la capa activa
- Ctrl (Esc): Escape normal, Ctrl al mantener
- Incluye teclas de navegación (flechas, Home, End, PgUp, PgDn)
- Incluye controles multimedia (Play, Prev, Next, Vol+, Vol-)
- Menu: Tecla de menú contextual (equivalente a clic derecho)

---

## Capa 3: FUNC (Funciones y Sistema)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │ F1  │ F2  │ F3  │ F4  │ F5  │              │ F6  │ F7  │ F8  │ F9  │ F10 │     │
├─────┼─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ F11 │ F12 │     │     │     │              │     │     │     │     │     │AltGr│
├─────┼─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │              │PrtSc│     │     │Reset│     │     │
└─────┴─────┴─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │     │              │     │     │     │
                  └─────┴─────┴─────┘              └─────┴─────┴─────┘
```

### Notas:
- Esta capa se activa pulsando la tecla Func (One-Shot Layer)
- PrtSc: Captura de pantalla
- Reset: Reinicia el teclado al modo bootloader para flashear nuevo firmware

---

## Funciones Vim Especiales

El keymap incluye atajos especiales para Vim:

- **Ctrl+Q (doble pulsación)**: Ejecuta `:q!` (salir sin guardar)
- **Ctrl+G (doble pulsación)**: Ejecuta `:x!` (guardar y salir)

Estos atajos detectan cuando presionas Ctrl+Q o Ctrl+G dos veces seguidas en menos de 500ms y automáticamente:
1. Envían ESC para salir del modo insert
2. Ejecutan el comando Vim correspondiente

---

## Configuración de Tapping Term

Las teclas Lower (Tab) y Raise (Backspace) tienen un tiempo de pulsación configurado especialmente para facilitar el cambio rápido entre capas y el uso normal de Tab/Backspace.
