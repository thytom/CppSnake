CC = g++
CFLAGS = -std=c++17 -O2 -g -Wall -lncurses
DEP = main.h \
	  snake.h \
	  node.h \
	  game.h

OBJ = main.o \
	  snake.o \
	  node.o \
	  game.o

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
