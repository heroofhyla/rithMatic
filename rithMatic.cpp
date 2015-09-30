#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>

int main(int argc, char *argv[]){
	std::ofstream fileOut;
	int arg;
	bool latexMode = false;
	char *fileDest;
	bool fileMode = false;
	bool shuffleMode = false;
	std::srand(std::time(0));
	while ((arg = getopt(argc, argv, "slo:")) != EOF){
		switch (arg){
			case 'l':
				latexMode = true;
			break;
			case 'o':
				fileMode = true;
				fileDest = optarg;
			break;
			case 's':
				shuffleMode = true;
			break;
		}
		
	}
	
	std::string problems[100];
	std::stringstream ss;
	for (int i = 0; i < 10; ++i){
		for (int k = 0; k < 10; ++k){
			ss.str("");
			if (latexMode){
				ss << "\\begin{tabular}{cc}\n" <<
						"& " << i << " \\\\\n" <<
						"+ & " << k << " \\\\\n" <<
						"\\hline\n" <<
						" & \\\\\n" <<
						" & \\\\\n" <<
						"\\end{tabular}\\quad\n";
				problems[i*10 + k] = ss.str();
			}
			else{
				ss << i << "+" << k << "=__ ";
				problems[i*10 + k] = ss.str();
			}
		}
	}
	
	if (shuffleMode){
		random_shuffle(&problems[0], &problems[100]);
	}
	
	if (fileMode){
		fileOut.open(fileDest);
		if (latexMode){
		fileOut << "\\documentclass{article}\n" <<
					"\\usepackage[margin=.75in]{geometry}\n" <<
					"\\begin{document}\n";
		}
		for (int i = 0; i < 10; ++i){
			for (int k = 0; k < 10; ++k){
				fileOut << problems[i*10 + k];
			}
			fileOut << "\n";
		}
		if (latexMode){
			fileOut << "\\end{document}";
		}
		fileOut.close();
	}else{
		if (latexMode){
			std::cout << "\\documentclass{article}\n" <<
					"\\usepackage{fullpage}\n" <<
					"\\begin{document}\n" <<
					"\\noindent\n";
		}
		for (int i = 0; i < 10; ++i){
			for (int k = 0; k < 10; ++k){
				std::cout << problems[i*10 + k];
			}
			std::cout << "\n";
		}
		if (latexMode){
			std::cout << "\\end{document}";
		}
	}
	
	return 0;
}
