#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

void addProblems(char, std::vector<std::string>&, bool);
int main(int argc, char *argv[]){
	std::ofstream fileOut;
	int arg;
	bool latexMode = false;
	char *fileDest;
	bool fileMode = false;
	bool randomize = false;
	bool addition = false;
	bool subtraction = false;
	bool multiplication = false;
	bool division = false;
	std::srand(std::time(0));
	while ((arg = getopt(argc, argv, "asmdrlo:")) != EOF){
		switch (arg){
			case 'l':
				latexMode = true;
			break;
			case 'o':
				fileMode = true;
				fileDest = optarg;
			break;
			case 'r':
				randomize = true;
			break;
			case 'a':
				addition = true;
			break;
			case 's':
				subtraction = true;
			break;
			case 'm':
				multiplication = true;
			break;
			case 'd':
				division = true;
			break;
		}
		
	}
	
	if (!addition && !subtraction && !multiplication && !division){
		addition = true;
	}
	
	std::vector<std::string> problems;
	if (addition){
		addProblems('+', problems, latexMode);
	}
	
	if (subtraction){
		addProblems('-', problems, latexMode);
	}
	
	if (multiplication){
		addProblems('x', problems, latexMode);
	}
	
	if (division){
		addProblems('/', problems, latexMode);
	}
	
	if (randomize){
		random_shuffle(problems.begin(), problems.end());
	}
	
	if (fileMode){
		fileOut.open(fileDest);
		if (latexMode){
		fileOut << "\\documentclass{article}\n" <<
					"\\usepackage[margin=.75in]{geometry}\n" <<
					"\\begin{document}\n";
		}
		for (int i = 0; i < problems.size()/10; ++i){
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
		for (int i = 0; i < problems.size()/10; ++i){
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

void addProblems(char oper, std::vector<std::string> &problems, bool latexMode){
	std::stringstream ss;
	std::string stroper = "$+$";
	if (latexMode){
		switch (oper){
			case '+':
				stroper = "$+$";
			break;
			case '-':
				stroper = "$-$";
			break;
			case 'x':
				stroper = "$\\times$";
			break;
			case '/':
				stroper = "$\\div$";
			break;
		}
	}
	for (int i = 0; i < 10; ++i){
		for (int k = 0; k < 10; ++k){
			ss.str("");
			if (latexMode){
			
				if (oper != '/'){
					ss << "\\begin{tabular}{cc}\n" <<
							"& " << i << " \\\\\n" <<
							stroper << " & " << k << " \\\\\n" <<
							"\\hline\n" <<
							" & \\\\\n" <<
							" & \\\\\n" <<
							"\\end{tabular}\\quad\n";
				}else{
					ss << "\\begin{tabular}{cc}\n" <<
							"& " << (i*k) << " \\\\\n" <<
							stroper << " & " << k << " \\\\\n" <<
							"\\hline\n" <<
							" & \\\\\n" <<
							" & \\\\\n" <<
							"\\end{tabular}\\quad\n";
				}
			}
			else{
				ss << i << oper << k << "=__ ";
			}
			problems.push_back(ss.str());
		}
	}
}
