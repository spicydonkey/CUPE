// simulate.cpp
// CUPE simulation 

#include <iostream>
#include <fstream> //Replace with XML Parser later
#include <string>
#include <sstream>
#include <stdlib.h>

#include "cupe.h"
#include "toe.h"
#include "processor.h" 
//include XMLParser

// Debug option
#undef DEBON

// Version stage
#define ALPHA

// Storage variable
PhysicsVector tmp_vect;

// Command-line usage of CUPE
void usage(void)
{
	// Print usage to user
	std::cout << "Usage: simulate <file>\n";
}


// Initialise the physics engine and set world parameters
	// filename arg should be updated to an XML document/file later
double InitCUPE(World& world, std::string FileName)
{
	// Open file
	std::ifstream fin;
	fin.open(FileName.c_str());

	std::string line;

	// Read the number of particles
	std::getline(fin, line);
	int NumParts = atoi(line.c_str());

	// Read particle information
	for (int i = 0; i < NumParts; i++)
	{
		Particle particle;

		// Mass
		std::getline(fin, line);
		particle.mass() = atof(line.c_str());
		
		// Position
		std::getline(fin, line);
		parseline(line, particle.displacement().components());

		// Velocity
		std::getline(fin, line);
		parseline(line, particle.velocity().components());

		world.ensemble().push_back(particle);
	}
	// Close file
	fin.close();

	double MaxTime = 100.0;	// Not set by file at this stage
	return MaxTime;
}

int main(int argc, char* argv[])
{
	// Check if the arguments CUPE is called with are valid
	// Otherwise tell user the usage of the program
	if (argc < 2)
	{
		usage();
		return 1;
	}
#ifdef DEBON	// get command line arguments
	else 
	{
		// print CL input
		// argv[1] should be a valid filename
		for (int i = 0; i < argc; i++)
		{
			std::cout << argv[i] << " ";
		}
		std::cout << std::endl;
	}
#endif
	std::string filename = argv[1];
#ifdef DEBON	// Check filename for validity
	std::cout << filename << '\n';
#endif

	// Parse input arguments
		// Open input XML file as simulation initialiser
		// Graphics on/off
	//std::ifstream fin;
	//fin.open(filename);	// open file
#ifdef DEBON	// Read file
	std::string line;
	if (fin.is_open())
	{
		// print all lines in file
		while (std::getline(fin, line))
		{
			std::cout << line << '\n';
		}
		fin.close();	// close file
	}
#endif

	// Parse XML
		// Initialise a world to simulate
	double time_limit;
	World world;

#ifdef DEBON
	// Test PhysicsVector object

	std::vector<double> myVect;
	for (int i = 0; i < 10; i++)
	{
		myVect.push_back(i);
	}

	// Initialise a PhysicsVector object
	PhysicsVector myPhysVect(myVect);

	for (int i = 0; i < 10; i++)
	{
		std::cout << myPhysVect[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "It works!\n";
#endif
	time_limit = InitCUPE(world, filename);
	world.printframe();
		// Initialise the physical laws
		// Get simulation range--e.g. time range
	// Close XML file
	//fin.close();



	// Simulate physics of the world for the range of time given
		// Call numerical solver to do calculation and evolve world
		// Output world snapshot
		// Graphical feedback?
	
	// Free memory and close files
	
	return 0;
}