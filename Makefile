CC = g++
CFLAGS = -O2 -g -Wall -lncurses

SRC_DIR := ./src
OBJ_DIR := ./build
BIN_DIR := ./bin
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

EXECUTABLE=$(BIN_DIR)/CppSnake

.phony: all run clean build dirs

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp 
	$(CC) $(CFLAGS) -c -o $@ $< 

all: run clean

dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(EXECUTABLE): dirs $(OBJ_FILES)
	$(CC) $(CFLAGS) -s -o $@ $(OBJ_FILES)

build: $(EXECUTABLE)

run: build
	$(EXECUTABLE)

clean:
	rm -r $(OBJ_DIR) $(BIN_DIR)
