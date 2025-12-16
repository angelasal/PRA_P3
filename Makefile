bin/testTableEntry: testTableEntry.cpp TableEntry.h
		mkdir -p bin
		g++ -o bin/testTableEntry testTableEntry.cpp
bin/testHashTable: testHashTable.cpp HashTable.h TableEntry.h ListLinked.h
		mkdir -p bin
		g++ -o bin/testHashTable testHashTable.cpp
bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h BSTree.h TableEntry.h
		mkdir -p bin
		g++ -o bin/testBSTreeDict testBSTreeDict.cpp
bin/testBSTree: testBSTree.cpp BSTree.h
		mkdir -p bin
		g++ -o bin/testBSTree testBSTree.cpp
clean:
		rm -rf *.o *.gch bin	