all: main.o
	$(CC) -o prog.out main.o

main.o: main.c
	$(CC) -c main.c

run:
	./prog.out not-pron
	make clean

clean:
	rm *.o prog.out
