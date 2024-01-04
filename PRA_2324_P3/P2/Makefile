all: bin/testBSTree

bin/testBSTree: BSTree.h BSNode.h testBSTree.cpp
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp

test: all
	./bin/testBSTree

clean:
	rm -rf *.o *.gch bin