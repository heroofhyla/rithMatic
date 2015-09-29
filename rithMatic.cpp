#include <iostream>

int main(int argc, char *argv[]){
	std::cout << argc << " arguments found.\n";
	for (int i = 0; i < argc; ++i){
		std::cout << argv[i] << "\n";
	}
	return 0;
}
