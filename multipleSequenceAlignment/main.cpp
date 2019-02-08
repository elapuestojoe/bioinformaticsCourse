#include <iostream>
#include <string>
#include <vector>

#include "stringUtilities.h"
#include "sequenceUtilities.h"

char sequenceAFilename[] = "..\\sequenceA.txt";
char sequenceBFilename[] = "..\\sequenceB.txt";
char sequenceCFilename[] = "..\\sequenceC.txt";

int gapPenalty = 8;

int main(int argc, char **argv)
{
	std::string sequenceA = readFile(sequenceAFilename);
	std::string sequenceB = readFile(sequenceBFilename);
	std::string sequenceC = readFile(sequenceCFilename);
	
	std::cout << "Sequence A: " << sequenceA << std::endl;
	std::cout << "Sequence B: " << sequenceB << std::endl;
	std::cout << "Sequence C: " << sequenceC << std::endl;
	
	std::string multipleSequenceString = multipleSequenceAlignment(std::vector<std::string>{sequenceA, sequenceB, sequenceC}, gapPenalty);
	
	std::cout << std::endl << "Global best alignment is: " << multipleSequenceString << std::endl;
	
	return 0;
}
