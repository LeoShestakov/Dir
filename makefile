all: main.o
	gcc -o dirAssignment main.c 

main.o: main.c
	gcc -c main.c

run:
	./dirAssignment

clean:
	rm *.o
	
debug: main.c
	gcc -g main.c

gdb: a.out
	gdb a.out