ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

ifeq ($(ARGV),)
	ARGC = 0
else
	ARGC = 1
endif

all: main.o
	$(CC) -o prog.out main.o

run:
	./prog.out $(ARGC) $(ARGV)
	make clean

main.o: main.c
	$(CC) -c main.c

clean:
	rm *.o prog.out

memtest:
	valgrind --leak-check=yes ./prog.out
