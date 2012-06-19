#include "common.hpp"
#include "init.hpp"

#include "output.hpp"
#include "fileutil.hpp"

#include <fstream>

void initProject(Output* output, const char* name, const char* file, const char* path)
{
	createPathForFile(file);

	std::ofstream out(file);
	if (!out)
	{
		output->error("Error opening project file %s for writing\n", file);
		return;
	}
	
	out << "path " << path << std::endl;
	out << "include \\.(cpp|cxx|cc|c|hpp|hxx|hh|h|inl|py|pl|pm|js|as|hlsl|cg|fx)$" << std::endl;

	output->print("Project file %s created, run 'qgrep build %s' to build\n", file, name);
}
