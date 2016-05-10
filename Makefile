
BINARIES= main bsort bsort++ absmin horner first-order-dynamic

OBJECTS= main.o bsort.o bsort++.o horner.o 

CFLAGS+=-Wall
CXXFLAGS+=-Wall -std=c++11

CXXLIBS=-lstdc++

all: ${BINARIES}

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
	
first-order-dynamic: first-order-dynamic.o
	${CC} -o first-order-dynamic first-order-dynamic.cpp -lstdc++ -lm

clean:
	rm -f $(OBJECTS) $(BINARIES)
