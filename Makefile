
BINARIES= main bsort bsort++ absmin horner

OBJECTS= main.o bsort.o bsort++.o


CFLAGS+=-Wall
CXXFLAGS+=-Wall -std=c++11

CXXLIBS=-lstdc++

all: main bsort bsort++ absmin horner


main: main.o
	${CC} -o main main.o

bsort: bsort.o
	${CC} -o bsort bsort.o

bsort++: bsort++.o
	${CC} -o bsort++ bsort++.o ${CXXLIBS}
	
absmin: absmin.o
	${CC} -o absmin absmin.o
	
horner: horner.o
	${CC} -o horner horner.o

clean:
	rm -f $(OBJECTS) $(BINARIES)
