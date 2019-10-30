CC = g++ -g
SRC_DIR = ./src
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj
TARGET = $(BUILD_DIR)/main.exe

SRCS = $(SRC_DIR)/display/main.cpp $(SRC_DIR)/game/main.cpp $(SRC_DIR)/main.cpp
OBJS = $(OBJ_DIR)/display/main.obj $(OBJ_DIR)/game/main.obj $(OBJ_DIR)/main.obj

$(TARGET): $(OBJS)
	-@md "$(@D)"
	$(CC) $^ -o $@

$(OBJ_DIR)/main.obj: $(SRC_DIR)/main.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@

$(OBJ_DIR)/display/main.obj: $(SRC_DIR)/display/main.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@

$(OBJ_DIR)/game/main.obj: $(SRC_DIR)/game/main.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@

$(OBJ_DIR)/game/brick.obj: $(SRC_DIR)/game/brick.cpp
	-@md "$(@D)"
	$(CC) -c $^ -o $@