CC=gcc
CFLAGS=-O3 -march=native
DEPS=versine.h haversine.h dist.h
OBJ=versine.o haversine.o dist.o distance.o

all: distance

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

distance: distance.o versine.o haversine.o dist.o
	$(CC) -o distance distance.o versine.o haversine.o dist.o -lm

clean:
	rm distance *.o
