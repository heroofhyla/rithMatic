/* rithMatic, an arithmetic problem set generator.  
 * File "engstr.h"
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
#ifndef ENGSTR_H
#define ENGSTR_H
#include <string>

namespace engstr{
	std::string ptHeader = "Name__________________\n"\
	                       "Date__________________\n";

	std::string latexHeader =  "Name\\underline{\\hspace{2in}}"\
	                           "\n\n\\medskip\n"\
	                           "Date\\underline{\\hspace{1.5in}}"\
	                           "\n\n\\medskip\n";

	std::string latexStart = "\\documentclass{article}\n"\
	                         "\\usepackage[margin=.75in]{geometry}\n"\
	                         "\\begin{document}\n";

	std::string latexEnd = "\\end{document}";
}
#endif
