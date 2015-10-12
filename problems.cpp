#include <string>
#include <vector>
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
