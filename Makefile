# Copyright (c) 2018 Tim Perkins

QMK_DIR := qmk_firmware
QMK_TMP_DIR := build/qmk_tmp
BUILD_DIR := build

all:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(QMK_TMP_DIR)
	mkdir -p $(QMK_TMP_DIR)/keyboards
	cp -R -f -t $(QMK_TMP_DIR) $(QMK_DIR)/Makefile
	cp -R -f -t $(QMK_TMP_DIR) $(QMK_DIR)/*.mk
	cp -R -f -t $(QMK_TMP_DIR) $(QMK_DIR)/lib
	cp -R -f -t $(QMK_TMP_DIR) $(QMK_DIR)/drivers
	cp -R -f -t $(QMK_TMP_DIR) $(QMK_DIR)/quantum
	cp -R -f -t $(QMK_TMP_DIR) $(QMK_DIR)/tmk_core
	cp -R -f -t $(QMK_TMP_DIR)/keyboards $(QMK_DIR)/keyboards/ergodox_infinity
	ln -r -f -T -s . $(QMK_TMP_DIR)/keyboards/ergodox_infinity/keymaps/tprk77
	make -C $(QMK_TMP_DIR) ergodox_infinity:tprk77
	cp $(QMK_TMP_DIR)/.build/ergodox_infinity_tprk77.bin \
	    $(BUILD_DIR)/ergodox_infinity_tprk77__LEFT.bin
	make -C $(QMK_TMP_DIR) ergodox_infinity:tprk77 MASTER=right
	cp $(QMK_TMP_DIR)/.build/ergodox_infinity_tprk77.bin \
	    $(BUILD_DIR)/ergodox_infinity_tprk77__RIGHT.bin

clean:
	-rm -rf build
