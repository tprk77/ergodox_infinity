#!/bin/bash

# Copyright (c) 2018 Tim Perkins

set -o errexit
set -o nounset
set -o pipefail

LEFT_ERGODOX_INFINITY_FIRMWARE="build/ergodox_infinity_tprk77__LEFT.bin"
RIGHT_ERGODOX_INFINITY_FIRMWARE="build/ergodox_infinity_tprk77__RIGHT.bin"
ERGODOX_INFINITY_DEVICE="1c11:b007"
DEBUG_FLAG="" # "--verbose"

function press_enter {
    echo "Press Enter to continue"
    read -p ""
}

if ! command -v dfu-util &>/dev/null; then
    echo "Missing dfu-util! On Ubuntu, try:" 1>&2
    echo "sudo apt install dfu-util" 1>&2
    exit 1
fi

echo "Ready to flash the LEFT side!"
press_enter

sudo dfu-util ${DEBUG_FLAG} -d ${ERGODOX_INFINITY_DEVICE} -D "${LEFT_ERGODOX_INFINITY_FIRMWARE}"

echo "Ready to flash the RIGHT side!"
press_enter

sudo dfu-util ${DEBUG_FLAG} -d ${ERGODOX_INFINITY_DEVICE} -D "${RIGHT_ERGODOX_INFINITY_FIRMWARE}"

exit 0
