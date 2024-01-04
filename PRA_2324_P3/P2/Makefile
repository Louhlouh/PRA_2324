all: bin/testBSTree bin/testBSTreeDict

bin/testBSTree: BSTree.h BSNode.h testBSTree.cpp
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp

bin/testBSTreeDict: ../P1/Dict.h BSTreeDict.h BSNode.h ../P1/TableEntry.h testBSTreeDict.cpp
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp

test: all
	./bin/testBSTreeDict

clean:
	rm -rf *.o *.gch bin