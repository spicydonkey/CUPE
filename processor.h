#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Split string by a delim and store in a preconstructed vector
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

// Parse a line of space separated doubles and store in a vector of doubles
std::vector<double> &parseline(const std::string &line, std::vector<double> &V);

#endif