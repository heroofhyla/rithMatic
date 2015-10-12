/* rithMatic, an arithmetic problem set generator.  
 * File "problems.h"
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
#ifndef PROBLEMS_H
#define PROBLEMS_H
void addProblems(char oper, std::vector<std::string> &problems, bool latexMode,
                 bool uniqueMode);
std::string genProblem(char oper, int t, int b, bool latexMode);
std::string getstroper(char oper, bool latexMode);
#endif
