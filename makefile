CC = gcc

CFLAGS = -Wall -Wextra -g -o Stack.x

all:
	$(CC) $(CFLAGS) main.c stackfunc.c UIfunc.c