CC=gcc
CFLAGS=-Wall -Werror
LDFLAGS=-L. -Wl,-rpath=.

.PHONY: all clean

all: main

lib: hijack.o
	$(CC) -shared -o libhijack.so $<

hijack.o: hijack.c
	$(CC) $(CFLAGS) -fpic -c $< -o $@

main: lib
	$(CC) $(LDFLAGS) $(CFLAGS) -o main main.c -lhijack -ldl
clean:
	rm -f main
	rm -f libhijack.so
	rm -f *.o
