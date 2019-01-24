#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 

std::string readFile(char filename[]);
void needlemanWunsch(std::string sequenceA, std::string sequenceB, int gapPenalty);
std::vector<std::string> processNeedlemanMatrix(int *matrixPtr, int x, int y, std::string sequenceA, std::string sequenceB, std::string buffer, int gapPenalty);

char sequenceAFilename[] = "E:\\CppPlayground\\bio\\sequenceAlignment\\sequenceA.txt";
char sequenceBFilename[] = "E:\\CppPlayground\\bio\\sequenceAlignment\\sequenceB.txt";

int main(int argc, char **argv)
{
	std::string sequenceA = readFile(sequenceAFilename);
	std::string sequenceB = readFile(sequenceBFilename);
	
	std::cout << "Sequence A: " << sequenceA << std::endl;
	std::cout << "Sequence B: " << sequenceB << std::endl;
	
	needlemanWunsch(sequenceA, sequenceB, -1);
	
	return 0;
}

std::string readFile(char filename[]) {
	std::ifstream ifs(filename);
	std::stringstream buffer;
	buffer << ifs.rdbuf();
	ifs.close();
	return buffer.str();
}

void needlemanWunsch(std::string sequenceA, std::string sequenceB, int gapPenalty) {
	int matrix[sequenceA.length() + 1][sequenceB.length() + 1];
	
	for(unsigned int y = 0; y < sequenceA.length() + 1; y++) {
		for(unsigned int x = 0; x < sequenceB.length() + 1; x++) {
			if(y == 0) {
				matrix[y][x] = 0;
			} else if(x == 0) {
				matrix[y][x] = 0;
			} else {
				int diagonalScore = matrix[y-1][x-1] + (sequenceA[y-1] == sequenceB[x-1] ? 1 : 0);
				int leftScore = matrix[y][x-1] + gapPenalty;
				int topScore = matrix[y-1][x] + gapPenalty;
				matrix[y][x] = std::max(std::max(leftScore, topScore), diagonalScore);
			}
		}
	}
	
	std::vector<std::string> alignments = processNeedlemanMatrix(*matrix, sequenceB.length(), sequenceA.length(), sequenceA, sequenceB, "", gapPenalty);
	
	for(std::vector<std::string>::iterator it = alignments.begin(); it != alignments.end(); ++it) {
		std::cout << *it << std::endl;
	}
	for(unsigned int y = 0; y < sequenceA.length() + 1; y++) {
		for(unsigned int x = 0; x < sequenceB.length() + 1; x++) {
			std::cout << matrix[y][x] << " ";
		}
		std::cout << "\n";
	}
}

std::vector<std::string> processNeedlemanMatrix(int *matrixPtr, int x, int y, std::string sequenceA, std::string sequenceB, std::string buffer, int gapPenalty) {
	std::vector<std::string> result(0);
	
	if(x == 0 && y == 0) {
		std::reverse(buffer.begin(), buffer.end());
		result.insert(result.end(), buffer);
		return result;
	}
	std::vector<std::string> topAlignments(0);
	std::vector<std::string> leftAlignments(0);
	std::vector<std::string> diagonalAlignments(0);
	
	int pos = ( (sequenceB.length() + 1) * y) + x;
	
	int currentVal = matrixPtr[pos];
	
	if(x != 0 && matrixPtr[pos-1] == currentVal) {
		leftAlignments = processNeedlemanMatrix(matrixPtr, x-1, y, sequenceA, sequenceB, buffer + "-", gapPenalty);
	}
	if(y != 0 && matrixPtr[pos - (sequenceB.length() + 1)] == currentVal) {
		topAlignments = processNeedlemanMatrix(matrixPtr, x, y-1, sequenceA, sequenceB, buffer + "-", gapPenalty);
	}
	if(x != 0 && y != 0 && sequenceA[y-1] == sequenceB[x-1]) {
		diagonalAlignments = processNeedlemanMatrix(matrixPtr, x-1, y-1, sequenceA, sequenceB, buffer + sequenceA[y-1], gapPenalty);
	}
	
	for(std::vector<std::string>::iterator it = topAlignments.begin(); it != topAlignments.end(); ++it) {
		result.insert(result.end(), *it);
	}

	for(std::vector<std::string>::iterator it = leftAlignments.begin(); it != leftAlignments.end(); ++it) {
		result.insert(result.end(), *it);
	}

	for(std::vector<std::string>::iterator it = diagonalAlignments.begin(); it != diagonalAlignments.end(); ++it) {
		result.insert(result.end(), *it);
	}
	return result;
}