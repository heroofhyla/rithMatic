#ifndef PROBLEMS_H
#define PROBLEMS_H
void addProblems(char oper, std::vector<std::string> &problems, bool latexMode,
                 bool uniqueMode);
std::string genProblem(char oper, int t, int b, bool latexMode);
std::string getstroper(char oper, bool latexMode);
#endif
