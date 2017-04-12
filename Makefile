OBJS = src/*.cpp
CC = g++
COMPILER_FLAGS = -Wall -Wextra -Werror
OBJ_NAME = bin/dungeon

all : $(OBJS)
	$(CC) $(COMPILER_FLAGS) $(OBJS) -o $(OBJ_NAME)
