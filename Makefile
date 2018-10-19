CC=gcc
ODIR=./build
LINKERFLAG=-lSDL2

.PHONY: all 

all: clean space-fighters

space-fighters: 
	${CC} main.c -o $@ ${LINKERFLAG}

clean:
	rm space-fighters
