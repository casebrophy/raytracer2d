CC=gcc
CFLAGS=-g -Wall -std=gnu99 

default: build

build:
	$(CC) $(CFLAGS) main.c -o ray1 -lm 

clean:
	rm ray1