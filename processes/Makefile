all: getpids fork1 fork2 fork3 wait1 wait2 wait3 waitpid exec1 exec2 fds1 fds2 fds3 redirection

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

exec1: exec1.o
	gcc -Wall -g -o exec1 exec1.o

exec1.o: exec1.c
	gcc -Wall -g -c exec1.c

exec2: exec2.o
	gcc -Wall -g -o exec2 exec2.o

exec2.o: exec2.c
	gcc -Wall -g -c exec2.c

fds1: fds1.o
	gcc -Wall -g -o fds1 fds1.o

fds1.o: fds1.c
	gcc -Wall -g -c fds1.c

fds2: fds2.o
	gcc -Wall -g -o fds2 fds2.o

fds2.o: fds2.c
	gcc -Wall -g -c fds2.c

fds3: fds3.o
	gcc -Wall -g -o fds3 fds3.o

fds3.o: fds3.c
	gcc -Wall -g -c fds3.c

redirection: redirection.o
	gcc -Wall -g -o redirection redirection.o

redirection.o: redirection.c
	gcc -Wall -g -c redirection.c

clean:
	rm -rf getpids getpids.o fork1 fork1.o fork2 fork2.o fork3 fork3.o wait1 wait1.o wait2 wait2.o wait3 wait3.o waitpid waitpid.o exec1 exec1.o exec2 exec2.o fds1 fds1.o fds2 fds2.o fds3 fds3.o redirection
