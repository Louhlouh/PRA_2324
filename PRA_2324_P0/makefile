.SUFFIXES: .cpp .h .o
.cpp.o: ; g++ -c $*.cpp

all: main

BrazoRobotico.o: BrazoRobotico.cpp BrazoRobotico.h

main.o: main.cpp BrazoRobotico.h

main: main.o BrazoRobotico.o
	g++ -o main main.o BrazoRobotico.o

clean:
	rm -f *.o main

test: all
	./main
