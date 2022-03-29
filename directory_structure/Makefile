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

clean:
	rm -rf ls1 ls1.o ls2 ls2.o ls3 ls3.o sorted_list.o
