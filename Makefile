CC = g++
CFLAGS = -std=c++17 -O2 -g -Wall -lncurses
DEP = main.h \
	  game.h \
	  node.h \
	  apple.h \
	  snake.h

OBJ = main.o \
	  game.o \
	  node.o \
	  apple.o \
	  snake.o

EXECUTABLE=CppSnake

.phony: all make run clean

%.o : %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: make run clean

make: $(OBJ)
	$(CC) -s -o $(EXECUTABLE) $^ $(CFLAGS)

run: make
	./$(EXECUTABLE)

clean:
	rm $(OBJ) $(EXECUTABLE)
