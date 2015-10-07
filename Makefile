all: rithMatic.o
	clang++ rithMatic.o -o rithMatic

rithMatic.o: rithMatic.cpp engstr.h
	clang++  -c rithMatic.cpp

clean:
	rm *.o
