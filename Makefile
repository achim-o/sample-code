
BINARIES= main bsort bsort++

OBJECTS= main.o bsort.o bsort++.o


CFLAGS+=-Wall
CXXFLAGS+=-Wall -std=c++11

CXXLIBS=-lstdc++

all: main bsort bsort++


main: main.o
	${CC} -o main main.o

bsort: bsort.o
	${CC} -o bsort bsort.o

bsort++: bsort++.o
	${CC} -o bsort++ bsort++.o ${CXXLIBS}

clean:
	rm -f $(OBJECTS) $(BINARIES)
