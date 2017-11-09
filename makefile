all: signals.c
	gcc -o test signals.c
clean:
	rm *.o
run: all
	./test
