bin/testTableEntry: testTableEntry.cpp TableEntry.h
		mkdir -p bin
		g++ -o bin/testTableEntry testTableEntry.cpp

bin/testHashTable: testHashTable.cpp hashTable.h TableEntry.h OneDriveict.h /Users/angelasal/Library/CloudStorage/OneDrive-UPV/PRA/PRA_P1/ListLinked.h
		mkdir -p bin
		g++ -o bin/testHashTable testHashTable.cpp	
clean:
		rm -rf *.o *.gch bin	