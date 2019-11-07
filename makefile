CC = g++
SRC_DIR = ./src
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj
TARGET = $(BUILD_DIR)/tetris.exe

OBJS = $(OBJ_DIR)/main.obj $(OBJ_DIR)/gameio.obj $(OBJ_DIR)/game/game.obj $(OBJ_DIR)/game/brick.obj

$(TARGET): $(OBJS)
	-@md "$(@D)"
	$(CC) $^ -o $@

$(OBJ_DIR)/main.obj: $(SRC_DIR)/main.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@

$(OBJ_DIR)/gameio.obj: $(SRC_DIR)/gameio.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@

$(OBJ_DIR)/game/game.obj: $(SRC_DIR)/game/game.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@

$(OBJ_DIR)/game/brick.obj: $(SRC_DIR)/game/brick.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@