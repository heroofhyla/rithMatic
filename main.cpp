/* rithMatic, an arithmetic problem set generator.  
 *
 * Copyright (C) 2015 Michael Stroud
 *
 * rithMatic is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "engstr.h"
#include "problems.h"

int main(int argc, char *argv[]){
	std::ofstream fileOut;
	int arg;
	int columns = 10;
	std::string startstring = "";
	std::string headerstring = "";
	std::string endstring = "";
	bool latexMode = false;
	char *fileDest;
	bool fileMode = false;
	bool randomize = false;
	bool uniqueMode = false;
	bool showHeader = false;
	std::srand(std::time(0));
	std::vector<char> operators;
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
				startstring = engstr::latexStart;
				endstring = engstr::latexEnd;
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
				operators.push_back('+');
				break;
			case 's':
				operators.push_back('-');
				break;
			case 'm':
				operators.push_back('*');
				break;
			case 'd':
				operators.push_back('/');
				break;
		}

	}

	if (showHeader){
		if (latexMode){
			headerstring = engstr::latexHeader;
		}else{
			headerstring = engstr::ptHeader;
		}
	}
	if (operators.size() == 0){
		operators.push_back('+');
	}
	std::vector<std::string> problems;
	for (int i = 0; i < operators.size(); ++i){
		addProblems(operators[i],problems,latexMode,uniqueMode);
	}
	if (randomize){
		random_shuffle(problems.begin(), problems.end());
	}

	if (fileMode){
		fileOut.open(fileDest);
	}
	std::ostream &outstream = (fileMode)?fileOut:std::cout;
	outstream << startstring;
	outstream << headerstring;
	for (int i = 0; i < ceil(problems.size()/double(columns)); ++i){
		for (int k = 0; k < columns; ++k){
			if (i*columns + k < problems.size()){
				outstream << problems[i*columns + k];
			}
		}
		outstream << "\n";
	}
	outstream << endstring;
	if (fileMode){
		fileOut.close();
	}
	return 0;
}



