#include "processor.h"


// Split string by a delim and store in a preconstructed vector
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<double> &parseline(const std::string &line, std::vector<double> &V)
{
	std::stringstream ss(line);
	std::string item;
	while (std::getline(ss, item, ' '))
	{
		V.push_back(atof(item.c_str()));
	}
	return V;
}