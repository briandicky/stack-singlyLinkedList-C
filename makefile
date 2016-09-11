CC = gcc
CFLAGS = -ggdb

all: test1 test2

test1: stack.o main.o
	$(CC) $(CFLAGS) -o test1 stack.o main.o

test2: stack.o main2.o
	$(CC) $(CFLAGS) -o test2 stack.o main2.o

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

main2.o: main2.c
	$(CC) $(CFLAGS) -c main2.c

dep:
	$(CC) -M *.c > .depend

clean:
	rm -f test1 test2 *.o

debug:
	@echo "Debugger mode"

help:
	@echo "This is makefile command information:"
	@echo "==============================================="
	@echo "all = compile all the file."
	@echo "DEBUG = enable the debugger mode."
	@echo "clean = remove executable and object file."
	@echo "==============================================="
	@echo 'Just use "make (FLAG)" then pass argument to make command.'
	@echo ""
