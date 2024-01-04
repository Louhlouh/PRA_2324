all: bin/praA_Array bin/praA_Linked

bin/praA_Array: praA_Array.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/praA_Array praA_Array.cpp ListArray.h

bin/praA_Linked: praA_Linked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/praA_Linked praA_Linked.cpp ListLinked.h

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

test: all
	./bin/praA_Array
	./bin/praA_Linked

clean:
	rm -r *.o *.gch bin




