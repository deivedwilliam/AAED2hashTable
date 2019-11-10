OBJS = src/Exception.c src/ArrayList.c src/main.c src/Employee.c src/HashOnFile.c
CC = gcc
OBJ_NAME = main

all: $(OBJS)
	$(CC) $(OBJS)  -o $(OBJ_NAME) -lm 