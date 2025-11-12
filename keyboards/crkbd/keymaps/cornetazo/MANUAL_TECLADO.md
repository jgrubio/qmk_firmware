# 📘 Manual del Teclado Corne - Cornetazo

**Teclado**: Corne (CRKBD) 42 teclas split
**Layout**: Español (QWERTY)
**Firmware**: QMK con acento inteligente integrado

---

## 📐 Disposición de Capas

### 🔷 Capa Base (QWERTY)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐                 ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ TAB │  Q  │  W  │  E  │  R  │  T  │                 │  Y  │  U  │  I  │  O  │  P  │ DEL │
├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
│ ALT*│  A  │  S  │  D  │  F  │  G  │                 │  H  │  J  │  K  │  L  │  -  │  ´  │
├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
│SHFT*│  Z  │  X  │  C  │  V  │  B  │                 │  N  │  M  │  ,  │  .  │  :  │FUNC*│
└─────┴─────┴─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │CTRL*│ ENT │ TAB │                 │BKSP │ SPC │SHFT*│
                  │     │ GUI │LOWER│                 │RAISE│     │     │
                  └─────┴─────┴─────┘                 └─────┴─────┴─────┘
```

**Leyenda**:
- `*` = OSM (One Shot Modifier) - presiona una vez, activo hasta siguiente tecla
- `´` = Activador del acento inteligente
- `LOWER` = Hold TAB para capa Lower, tap para TAB
- `RAISE` = Hold BKSP para capa Raise, tap para Backspace
- `FUNC*` = One Shot Layer - presiona para activar capa Func una vez

---

### 🔶 Capa LOWER (Números y Símbolos)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐                 ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │  ¨  │  [  │  ]  │  ¿  │  ?  │                 │  7  │  8  │  9  │  0  │  %  │     │
├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │  ¡  │  !  │  (  │  )  │                 │  4  │  5  │  6  │  '  │  `  │ALTGR│
├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │  ~  │  &  │  ^  │  $  │                 │  1  │  2  │  3  │  #  │  @  │     │
└─────┴─────┴─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │▓▓▓▓▓│                 │     │     │  .  │
                  └─────┴─────┴─────┘                 └─────┴─────┴─────┘
```

**Uso**: Mantener TAB presionado o activar con combo

---

### 🔴 Capa RAISE (Navegación y Símbolos)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐                 ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │  _  │  +  │PG UP│                 │  *  │     │     │  /  │  |  │     │
├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │HOME │ END │  \  │  =  │PG DN│                 │  ←  │  ↓  │  ↑  │  →  │ APP │ALTGR│
├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  <  │  >  │     │     │  ;  │                 │PLAY │PREV │NEXT │VOL- │VOL+ │     │
└─────┴─────┴─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │CTRL │     │     │                 │▓▓▓▓▓│     │     │
                  │ ESC │     │     │                 │     │     │     │
                  └─────┴─────┴─────┘                 └─────┴─────┴─────┘
```

**Uso**: Mantener BKSP presionado

---

### ⚫ Capa FUNC (Funciones)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐                 ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │ F1  │ F2  │ F3  │ F4  │ F5  │                 │ F6  │ F7  │ F8  │ F9  │ F10 │     │
├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ F11 │ F12 │     │     │     │                 │     │     │     │     │     │ALTGR│
├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │                 │PRTSC│     │     │RESET│     │     │
└─────┴─────┴─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │     │                 │     │     │     │
                  └─────┴─────┴─────┘                 └─────┴─────┴─────┘
```

**Uso**: Presionar tecla `:` en capa base (activa una vez)

---

## ✨ Acento Inteligente

El teclado incluye un sistema de acento inteligente que permite escribir acentos, diéresis y apóstrofes de forma rápida.

### 🎯 Activación

Presiona la tecla **´** (ubicada donde normalmente estaría `;` en QWERTY).

### 📝 Funcionalidades

#### Vocales Acentuadas

| Secuencia | Resultado | Con Shift | Resultado |
|-----------|-----------|-----------|-----------|
| `´` + `a` | á | `´` + `Shift+A` | Á |
| `´` + `e` | é | `´` + `Shift+E` | É |
| `´` + `i` | í | `´` + `Shift+I` | Í |
| `´` + `o` | ó | `´` + `Shift+O` | Ó |
| `´` + `u` | ú | `´` + `Shift+U` | Ú |

**Ejemplos**:
- `José` → `Shift+J` `o` `´` `s` `´` `e`
- `café` → `c` `a` `f` `´` `e`

#### Letra Ñ

| Secuencia | Resultado | Con Shift | Resultado |
|-----------|-----------|-----------|-----------|
| `´` + `n` | ñ | `´` + `Shift+N` | Ñ |

**Ejemplos**:
- `España` → `Shift+E` `s` `p` `a` `´` `n` `a`
- `año` → `a` `´` `n` `o`

#### Diéresis (ü)

| Secuencia | Resultado | Con Shift | Resultado |
|-----------|-----------|-----------|-----------|
| `´` + `g` + `u` | gü | `´` + `Shift+G` + `u` | GÜ |

**Ejemplos**:
- `cigüeña` → `c` `i` `´` `g` `u` `e` `´` `n` `a`
- `pingüino` → `p` `i` `n` `´` `g` `u` `i` `n` `o`

#### Apóstrofes (para inglés)

| Secuencia | Resultado | Uso |
|-----------|-----------|-----|
| `´` + `m` | 'm | I'm, I'll... |
| `´` + `l` | 'l | We'll... |
| `´` + `d` | 'd | I'd, you'd... |
| `´` + `s` | 's | it's, that's... |
| `´` + `r` | 'r | you're... |
| `´` + `t` | 't | don't, can't... |
| `´` + `v` | 'v | I've... |
| `´` + `c` | 'c | - |

**Ejemplos**:
- `I'm` → `Shift+I` `´` `m`
- `don't` → `d` `o` `n` `´` `t`

#### Símbolos Especiales

| Secuencia | Resultado | Uso |
|-----------|-----------|-----|
| `´` + `Space` | $ | Variables, precios |

#### Modo Borrar Palabras

| Secuencia | Resultado |
|-----------|-----------|
| `´` + `´` | Borra una palabra hacia atrás (Ctrl+Backspace) |

**Funcionamiento**:
- Primera pulsación de `´`: activa el modo acento
- Segunda pulsación de `´`: borra una palabra inmediatamente
- Mantener presionado `´`: sigue borrando palabras
- Presionar cualquier otra tecla: desactiva el modo borrado

**Ejemplo**:
```
Texto: "Hola mundo cruel"
         ↓ cursor aquí
1. Presionar: ´ + ´ (borra "cruel")
2. Mantener ´ o presionar de nuevo (borra "mundo")
Resultado: "Hola "
```

---

## 🎮 Combos

Los combos son combinaciones de dos teclas presionadas simultáneamente que producen un resultado especial.

| Combo | Resultado | Descripción |
|-------|-----------|-------------|
| `D` + `F` | `"` | Comillas dobles |
| `J` + `K` | `ESC` | Escape rápido |

---

## 🚀 Atajos de Vim

### Salir de Vim (doble Ctrl+Q)

**Secuencia**: `Ctrl+Q` `Ctrl+Q` (dos veces en menos de 500ms)

**Efecto**: Ejecuta `:q!` en Vim
- Escapa del modo actual
- Ejecuta el comando quit sin guardar
- Útil para salir rápidamente

### Cancelar operación (doble Ctrl+G)

**Secuencia**: `Ctrl+G` `Ctrl+G` (dos veces en menos de 500ms)

**Efecto**: Ejecuta `:x!` en Vim
- Escapa del modo actual
- Ejecuta guardar y salir
- Útil para salir guardando rápidamente

### Notas sobre los atajos de Vim

- ⏱️ **Timing**: Las dos pulsaciones deben ocurrir en menos de 500ms
- 🎯 **Context-aware**: Detecta automáticamente si Ctrl está presionado
- 🔄 **Restaura mods**: Los modificadores se restauran después del comando
- ⚠️ **Uso**: Estos atajos envían comandos de Vim reales, asegúrate de estar en un editor compatible

---

## 🎹 Teclas Especiales

### One Shot Modifiers (OSM)

Las teclas marcadas con `*` son One Shot Modifiers. Funcionan de dos formas:

1. **Tap (presión corta)**: Activa el modificador para la **siguiente tecla solamente**
   - Ejemplo: `OSM_SFT` + `a` → `A`

2. **Hold (mantener presionado)**: Funciona como modificador normal mientras se mantiene
   - Ejemplo: mantener `OSM_SFT` + `a` `b` `c` → `ABC`

**Ventaja**: No necesitas mantener Shift para una sola mayúscula.

### Layer Taps (LT)

Algunas teclas tienen doble función:

| Tecla | Tap (presión corta) | Hold (mantener) |
|-------|---------------------|-----------------|
| TAB (thumb) | TAB | Activa capa LOWER |
| BKSP (thumb) | Backspace | Activa capa RAISE |
| ENT (thumb) | Enter | GUI/Super |
| ESC (RAISE) | Escape | Ctrl |

### One Shot Layer (OSL)

| Tecla | Función |
|-------|---------|
| `:` (FUNC) | Activa capa FUNC para la siguiente tecla |

---

## 🔧 Configuración Técnica

### Tapping Term

- **Teclas normales**: 200ms
- **Teclas de pulgar** (LOWER/RAISE): Tiempo personalizado para mayor comodidad

### Firmware

- **QMK**: Versión actual con soporte para Helios
- **Compilación**: `qmk compile -kb crkbd/rev1 -km cornetazo -e CONVERT_TO=helios`
- **Flash**: Usar script `./flash.sh` (flashea ambos lados automáticamente)

### Características Activadas

- ✅ Combo keys
- ✅ Extrakeys (multimedia)
- ✅ Acento inteligente
- ✅ One Shot Modifiers
- ✅ Layer Taps
- ✅ Atajos de Vim

---

## 📚 Créditos

- **Keymap base**: Mark Stosberg (@markstos)
- **Acento inteligente**: Álvaro Prieto Lauroba ([proyecto corne/](https://github.com/alvaro-prieto/corne))
- **Adaptación**: Jorge (cornetazo)

---

## 🆘 Troubleshooting

### El acento no funciona
- Verifica que hayas compilado con `SRC += acento_corne.c` en rules.mk
- Asegúrate de presionar `´` (no es la tecla de acento muerto del sistema)

### OSM Shift no funciona con acentos
- El firmware detecta tanto Shift normal como OSM Shift
- Prueba: `´` + `OSM_SFT` + `I` → debería producir `Í`

### Los atajos de Vim no funcionan
- Verifica que estés en un editor compatible con comandos de Vim
- El timing debe ser menor a 500ms entre las dos pulsaciones de Ctrl+tecla

### Reset del teclado
- Accede a capa FUNC (presiona `:`)
- Presiona la tecla `RESET` (posición de `Q` en esa capa)
- El teclado entrará en modo bootloader

---

## 📖 Recursos

- [QMK Documentation](https://docs.qmk.fm/)
- [Proyecto corne/ original](https://github.com/alvaro-prieto/corne)
- Script de flash: `./flash.sh` (en este directorio)
- Layout visual: Usa [QMK Configurator](https://config.qmk.fm/) para visualización interactiva

---

**Versión del manual**: 1.0
**Última actualización**: 2025-11-10
