ls1: ls1.o
	gcc -Wall -g -o ls1 ls1.o

ls1.o: ls1.c
	gcc -Wall -g -c ls1.c

ls2: ls2.o
	gcc -Wall -g -o ls2 ls2.o

ls2.o: ls2.c
	gcc -Wall -g -c ls2.c

ls3: ls3.o sorted_list.o
	gcc -Wall -g -o ls3 sorted_list.o ls3.o

ls3.o: ls3.c
	gcc -Wall -g -c ls3.c

ls4: ls4.o sorted_list.o
	gcc -Wall -g -o ls4 sorted_list.o ls4.o

ls4.o: ls4.c
	gcc -Wall -g -c ls4.c

sorted_list.o: sorted_list.c sorted_list.h
	gcc -Wall -g -c sorted_list.c

du1: du1.o
	gcc -Wall -g -o du1 du1.o

du1.o: du1.c
	gcc -Wall -g -c du1.c

du2: du2.o
	gcc -Wall -g -o du2 du2.o

du2.o: du2.c
	gcc -Wall -g -c du2.c

du3: du3.o
	gcc -Wall -g -o du3 du3.o

du3.o: du3.c
	gcc -Wall -g -c du3.c

du4: du4.o
	gcc -Wall -g -o du4 du4.o

du4.o: du4.c
	gcc -Wall -g -c du4.c

du5: du5.o
	gcc -Wall -g -o du5 du5.o

du5.o: du5.c
	gcc -Wall -g -c du5.c

clean:
	rm -rf ls1 ls1.o ls2 ls2.o ls3 ls3.o ls4 ls4.o sorted_list.o du1 du1.o du2 du2.o du3 du3.o du4 du4.o du5 du5.o
