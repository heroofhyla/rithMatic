#ifndef ENGSTR_H
#define ENGSTR_H
#include <string>

namespace engstr{
	std::string ptHeader = "Name__________________\n"\
							"Date__________________\n";

	std::string latexHeader =  "Name\\underline{\\hspace{2in}}\n\n\\medskip\n"\
								"Date\\underline{\\hspace{1.5in}}\n\n\\medskip\n";

	std::string latexStart = "\\documentclass{article}\n"\
							  "\\usepackage[margin=.75in]{geometry}\n"\
							  "\\begin{document}\n";

	std::string latexEnd = "\\end{document}";
}
#endif
