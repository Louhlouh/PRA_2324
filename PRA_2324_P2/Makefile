.SUFFIXES: .cpp .h .o
.cpp.o: ; g++ -c $*.cpp

all: test_DyV

test_DyV.o: test_DyV.cpp DyV.h

test_DyV: test_DyV.o 
	g++ -o test_DyV test_DyV.o 

clean:
	rm -f *.o test_DyV
	rm -f *.gch test_DyV
	rm -f *.o Monedas
	rm -f *.o Mochila

test: all
	./test_DyV
