/* rithMatic, an arithmetic problem set generator.  
 * File "problems.cpp"
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
#include <vector>
#include <string>
#include <sstream>
#include "problems.h"
void addProblems(char oper, std::vector<std::string> &problems, bool latexMode, 
                 bool uniqueMode)
{
	for (int i = 0; i < 100; ++i){
		int t = i/10;
		int b = i%10;
		if (oper == '/'){
			t *= b;
		}
		if (!uniqueMode || t < b){
			problems.push_back(genProblem(oper, t, b, latexMode));
		}
	}
}


std::string genProblem(char oper, int t, int b, bool latexMode)
{
	std::stringstream ss;
	std::string stroper = getstroper(oper, latexMode);
	if (latexMode){

		if (t < 10){
			ss << "\\begin{tabular}{cc}\n" <<
			      " & " << (t) << " \\\\\n" <<
			      stroper << " & " << b << " \\\\\n" <<
			      "\\hline\n" <<
			      " & \\\\\n" <<
			      " & \\\\\n" <<
			      "\\end{tabular}\\quad\n";

		}else{
			ss << "\\begin{tabular}{cc}\n" <<
			      t/10 << "& " << t%10 << " \\\\\n" <<
			      stroper << " & " << b << " \\\\\n" <<
			      "\\hline\n" <<
			      " & \\\\\n" <<
			      " & \\\\\n" <<
			      "\\end{tabular}\\quad\n";
		}
	}else{
		ss << t << oper << b << "=__ ";
	}

	return ss.str();
}


std::string getstroper(char oper, bool latexMode){
	std::string stroper;
	stroper = oper;

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

	return stroper;


}
