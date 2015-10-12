all: main.o problems.o
	clang++ main.o problems.o -o rithMatic

main.o: main.cpp engstr.h
	clang++ -c main.cpp

problems.o: problems.cpp problems.h engstr.h
	clang++ -c problems.cpp
clean:
	rm *.o
