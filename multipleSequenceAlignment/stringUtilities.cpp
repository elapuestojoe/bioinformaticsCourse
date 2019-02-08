#include <string>
#include <fstream>
#include <sstream>

std::string readFile(char filename[]) {
	
	std::ifstream ifs(filename);
	std::stringstream buffer;
	buffer << ifs.rdbuf();
	ifs.close();
	return buffer.str();
}