
BINARIES= main

OBJECTS= main.o


CFLAGS+=-Wall
CXXFLAGS+=-Wall

all: main


main: main.o
	${CC} -o main main.o


clean:
	rm -f *.o $(BINARIES)
