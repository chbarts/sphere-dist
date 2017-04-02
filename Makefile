CC=gcc
CFLAGS=-O3 -march=native
DEPS=versine.h haversine.h dist.h
OBJ=versine.o haversine.o dist.o distance.o

all: distance
neon: distance-neon

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%-neon.o: %.c $(DEPS)
	$(CC) -c -o $@ $< -mfpu=neon -funsafe-math-optimizations $(CFLAGS)

distance: distance.o versine.o haversine.o dist.o
	$(CC) -o distance distance.o versine.o haversine.o dist.o -lm

distance-neon: distance-neon.o versine-neon.o haversine-neon.o dist-neon.o
	$(CC) -o distance-neon distance-neon.o versine-neon.o haversine-neon.o dist-neon.o -lm

clean:
	rm distance *.o

clean-neon:
	rm distance-neon *-neon.o
