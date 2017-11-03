all: directories.c
	gcc -o main directories.c

run: all
	./main
