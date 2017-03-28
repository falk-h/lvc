CC=gcc
CFLAGS= -Wall -O3 -march=native
lvc: lvc.c
	$(CC) $(CFLAGS) -o lvc lvc.c
lvc-lite: lvc-lite.c
	$(CC) $(CFLAGS) -o lvc-lite lvc-lite.c
clean:
	rm lvc lvc-lite
