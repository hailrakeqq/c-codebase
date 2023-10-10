CC = clang

SRC_DIR = src
BUILD_DIR = build
OUTPUT_TEST = test
OUTPUT_DEBUG = libDebug

all:

test:
	rm -rf $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$(OUTPUT_TEST) $(SRC_DIR)/main.c $(SRC_DIR)/linkedList.c

debug:
	gcc -g -o $(BUILD_DIR)/$(OUTPUT_DEBUG) $(SRC_DIR)/main.c $(SRC_DIR)/linkedList.c
clear:
	rm -rf $(BUILD_DIR)
