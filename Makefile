OBJS = *.cpp
CC = g++
COMPILER_FLAGS = -Wall -Wextra -Werror
OBJ_NAME = dungeon

all : $(OBJS)
	$(CC) $(COMPILER_FLAGS) $(OBJS) -o $(OBJ_NAME)