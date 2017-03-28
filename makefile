CC=gcc
CFLAGS= -Wall -O3 -march=native
lvc: lvc.c
	$(CC) $(CFLAGS) -o lvc lvc.c
clean:
	rm lvc
