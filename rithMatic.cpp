/* rithMatic, an arithmetic problem set generator.
 * Copyright (C) 2015 Michael Stroud
 *
 * rithMatic is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

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

void addProblems(char, std::vector<std::string>&, bool, bool);

int main(int argc, char *argv[]){
	std::ofstream fileOut;
	int arg;
	int columns = 10;
	bool latexMode = false;
	char *fileDest;
	bool fileMode = false;
	bool randomize = false;
	bool addition = false;
	bool subtraction = false;
	bool multiplication = false;
	bool division = false;
	bool uniqueMode = false;
	bool showHeader = false;
	std::srand(std::time(0));
	while ((arg = getopt(argc, argv, "huc:asmdrlo:")) != EOF){
		switch (arg){
			case 'h':
				showHeader = true;
				break;
			case 'c':
				columns = atoi(optarg);
				break;
			case 'u':
				uniqueMode = true;
				break;
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
		addProblems('+', problems, latexMode, uniqueMode);
	}

	if (subtraction){
		addProblems('-', problems, latexMode, uniqueMode);
	}

	if (multiplication){
		addProblems('x', problems, latexMode, uniqueMode);
	}

	if (division){
		addProblems('/', problems, latexMode, uniqueMode);
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
		if (showHeader){
			if (latexMode){
				fileOut << "Name\\underline{\\hspace{2in}}\n\n\\medskip\n"<<
					"Date\\underline{\\hspace{1.5in}}\n\n\\medskip\n";
			}else{
				fileOut << "Name___________________\n" <<
					"Date___________________\n";
			}
		}
		for (int i = 0; i < ceil(problems.size()/double(columns)); ++i){
			for (int k = 0; k < columns; ++k){
				if (i*columns + k < problems.size()){
					fileOut << problems[i*columns + k];
				}
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
		if (showHeader){
			if (latexMode){
				std::cout << "Name\\underline{\\hspace{2in}}\n\n\\medskip\n"<<
					"Date\\underline{\\hspace{1.5in}}\n\n\\medskip\n";
			}else{
				std::cout << "Name___________________\n" <<
					"Date___________________\n";
			}
		}
		for (int i = 0; i < ceil(problems.size()/double(columns)); ++i){
			for (int k = 0; k < columns; ++k){
				if (i*columns + k < problems.size()){
					std::cout << problems[i*columns + k];
				}
			}
			std::cout << "\n";
		}
		if (latexMode){
			std::cout << "\\end{document}";
		}
	}

	return 0;
}

void addProblems(char oper, std::vector<std::string> &problems, bool latexMode, bool uniqueMode){
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
		int startval = 0;
		if (uniqueMode && oper != '/'){
			startval = i;
		}
		for (int k = startval; k < 10; ++k){
			if (k == 0 && oper == '/'){
				//skip div by zero
			}else{
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
						if ((i*k)/10 == 0){
							ss << "\\begin{tabular}{cc}\n" <<
								" & " << (i*k) << " \\\\\n" <<
								stroper << " & " << k << " \\\\\n" <<
								"\\hline\n" <<
								" & \\\\\n" <<
								" & \\\\\n" <<
								"\\end{tabular}\\quad\n";

						}else{
							ss << "\\begin{tabular}{cc}\n" <<
								(i*k)/10 << "& " << (i*k)%10 << " \\\\\n" <<
								stroper << " & " << k << " \\\\\n" <<
								"\\hline\n" <<
								" & \\\\\n" <<
								" & \\\\\n" <<
								"\\end{tabular}\\quad\n";
						}
					}


				}
				else{
					if (oper != '/'){
						ss << i << oper << k << "=__ ";
					}else{
						ss << (i*k) << oper << k << "=__ ";
					}
				}
				problems.push_back(ss.str());
			}
		}
	}
}
