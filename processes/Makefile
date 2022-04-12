all: getpids fork1 fork2 fork3 wait1 wait2 wait3 waitpid

getpids: getpids.o
	gcc -Wall -g -o getpids getpids.o

getpids.o: getpids.c
	gcc -Wall -g -c getpids.c

fork1: fork1.o
	gcc -Wall -g -o fork1 fork1.o

fork1.o: fork1.c
	gcc -Wall -g -c fork1.c

fork2: fork2.o
	gcc -Wall -g -o fork2 fork2.o

fork2.o: fork2.c
	gcc -Wall -g -c fork2.c

fork3: fork3.o
	gcc -Wall -g -o fork3 fork3.o

fork3.o: fork3.c
	gcc -Wall -g -c fork3.c

wait1: wait1.o
	gcc -Wall -g -o wait1 wait1.o

wait1.o: wait1.c
	gcc -Wall -g -c wait1.c

wait2: wait2.o
	gcc -Wall -g -o wait2 wait2.o

wait2.o: wait2.c
	gcc -Wall -g -c wait2.c

wait3: wait3.o
	gcc -Wall -g -o wait3 wait3.o

wait3.o: wait3.c
	gcc -Wall -g -c wait3.c

waitpid: waitpid.o
	gcc -Wall -g -o waitpid waitpid.o

waitpid.o: waitpid.c
	gcc -Wall -g -c waitpid.c

clean:
	rm -rf getpids getpids.o fork1 fork1.o fork2 fork2.o fork3 fork3.o wait1 wait1.o wait2 wait2.o wait3 wait3.o waitpid waitpid.o
