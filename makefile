CC = g++ -g
SRC_DIR = ./src
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj
TARGET = $(BUILD_DIR)/main.exe

OBJS = $(OBJ_DIR)/main.obj $(OBJ_DIR)/gui/output.obj $(OBJ_DIR)/gui/input.obj $(OBJ_DIR)/game/main.obj $(OBJ_DIR)/game/brick.obj

$(TARGET): $(OBJS)
	-@md "$(@D)"
	$(CC) $^ -o $@

$(OBJ_DIR)/main.obj: $(SRC_DIR)/main.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@

$(OBJ_DIR)/gui/output.obj: $(SRC_DIR)/gui/output.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@

$(OBJ_DIR)/gui/input.obj: $(SRC_DIR)/gui/input.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@

$(OBJ_DIR)/game/main.obj: $(SRC_DIR)/game/main.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@

$(OBJ_DIR)/game/brick.obj: $(SRC_DIR)/game/brick.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@