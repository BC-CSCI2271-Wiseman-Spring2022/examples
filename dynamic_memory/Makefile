all: sizeof sbrk page_size malloc_test1 malloc_test2 simple_malloc_test

sizeof: sizeof.o
	gcc -Wall -g -o sizeof sizeof.o

sizeof.o: sizeof.c
	gcc -Wall -g -c sizeof.c

sbrk: sbrk.o
	gcc -Wall -g -o sbrk sbrk.o

sbrk.o: sbrk.c
	gcc -Wall -g -c sbrk.c

page_size: page_size.o
	gcc -Wall -g -o page_size page_size.o

page_size.o: page_size.c
	gcc -Wall -g -c page_size.c

malloc_test1: malloc_test1.o
	gcc -Wall -g -o malloc_test1 malloc_test1.o

malloc_test1.o: malloc_test1.c
	gcc -Wall -g -c malloc_test1.c

malloc_test2: malloc_test2.o
	gcc -Wall -g -o malloc_test2 malloc_test2.o

malloc_test2.o: malloc_test2.c
	gcc -Wall -g -c malloc_test2.c

simple_malloc_test: simple_malloc.o simple_malloc_test.o
	gcc -Wall -g -o simple_malloc_test simple_malloc.o simple_malloc_test.o

simple_malloc_test.o: simple_malloc_test.c simple_malloc.h
	gcc -Wall -g -c simple_malloc_test.c

simple_malloc.o: simple_malloc.c simple_malloc.h
	gcc -Wall -g -c simple_malloc.c

clean:
	rm -rf sizeof sizeof.o sbrk sbrk.o page_size page_size.o malloc_test1 malloc_test1.o malloc_test2 malloc_test2.o simple_malloc_test simple_malloc_test.o simple_malloc.o
