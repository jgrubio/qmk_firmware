#!/bin/bash

# Script para compilar y flashear el firmware del teclado Corne (split - 2 partes)
# Uso: ./flash.sh

# Colores para output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
QMK_DIR="/home/jorge/repo_personal/qmk_firmware"
VENV_PATH="$SCRIPT_DIR/teclado/bin/activate"
FIRMWARE_FILE="$QMK_DIR/.build/crkbd_rev1_cornetazo_helios.uf2"
MOUNT_POINT="/run/media/jorge/RPI-RP2"

# Función para flashear una mitad del teclado
flash_side() {
    local SIDE=$1

    echo -e "${BLUE}═══════════════════════════════════════════════════${NC}"
    echo -e "${BLUE}  Flasheando ${SIDE}${NC}"
    echo -e "${BLUE}═══════════════════════════════════════════════════${NC}"
    echo
    echo -e "${YELLOW}→ Pon el ${SIDE} en modo bootloader (doble reset)${NC}"
    echo -e "${YELLOW}→ Esperando que se monte en: $MOUNT_POINT${NC}"
    echo

    # Loop para esperar el dispositivo
    while [ ! -d "$MOUNT_POINT" ]; do
        sleep 0.5
    done

    echo -e "${GREEN}✓ Dispositivo detectado!${NC}"
    echo -e "${YELLOW}→ Esperando 2 segundos para que se monte completamente...${NC}"
    sleep 2
    echo

    # Copiar firmware
    echo -e "${YELLOW}→ Copiando firmware...${NC}"
    cp "$FIRMWARE_FILE" "$MOUNT_POINT/"

    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✓ Firmware copiado exitosamente${NC}"
        echo

        # Esperar a que se desmonte
        echo -e "${YELLOW}→ Esperando a que se desmonte el dispositivo...${NC}"
        while [ -d "$MOUNT_POINT" ]; do
            sleep 0.5
        done
        echo -e "${GREEN}✓ ${SIDE} flasheado correctamente!${NC}"
        echo
    else
        echo -e "${RED}✗ Error al copiar el firmware${NC}"
        exit 1
    fi
}

echo -e "${BLUE}═══════════════════════════════════════════════════${NC}"
echo -e "${BLUE}  Compilando firmware del teclado Corne${NC}"
echo -e "${BLUE}═══════════════════════════════════════════════════${NC}"
echo

# Activar entorno virtual y compilar
cd "$QMK_DIR"
source "$VENV_PATH"

echo -e "${YELLOW}→ Compilando...${NC}"
qmk compile -kb crkbd/rev1 -km cornetazo -e CONVERT_TO=helios

if [ $? -eq 0 ]; then
    echo
    echo -e "${GREEN}✓ Compilación exitosa${NC}"
    echo -e "${GREEN}✓ Firmware: $FIRMWARE_FILE${NC}"
    echo
else
    echo -e "${RED}✗ Error en la compilación${NC}"
    exit 1
fi

# Flashear primera mitad
flash_side "LADO IZQUIERDO"

# Flashear segunda mitad
flash_side "LADO DERECHO"

# Mensaje final
echo -e "${BLUE}═══════════════════════════════════════════════════${NC}"
echo -e "${GREEN}  ¡Flash completado en ambos lados!${NC}"
echo -e "${BLUE}═══════════════════════════════════════════════════${NC}"
echo
