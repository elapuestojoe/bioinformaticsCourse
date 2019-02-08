#include <iostream>
#include <list>
#include <algorithm> 
#include <iterator>

#include "blossum.h"

enum PreviousPaths {
	LEFT,
	TOP,
	DIAGONAL
};

struct cell {
	int value = 0;
	std::list <PreviousPaths> previousPathsList;		//TODO: Change list to vector
};

std::vector<std::string> processNeedlemanMatrix(cell *matrixPtr, int x, int y, std::string sequenceA, std::string sequenceB, std::string buffer, int gapPenalty);

std::vector<std::string> needlemanWunsch(std::string sequenceA, std::string sequenceB, int gapPenalty) {

	// Initialize matrix 
	cell matrix [sequenceA.length() + 1][sequenceB.length() + 1];
	int maxYValues[sequenceA.length() + 1];
	int maxXValues[sequenceB.length() + 1];
	
	maxYValues[0] = 0;
	maxXValues[0] = 0;

	//Set matrix first column
	for(size_t i = 1; i < sequenceA.length() + 1; i++) {
		maxYValues[i] = -gapPenalty;
		matrix[i][0].value = -gapPenalty;
		matrix[i][0].previousPathsList.push_front(PreviousPaths(TOP));
	}

	//Set matrix first row
	for(size_t i = 1; i < sequenceB.length() + 1; i++) {
		maxXValues[i] = -gapPenalty;
		matrix[0][i].value = -gapPenalty;
		matrix[0][i].previousPathsList.push_front(PreviousPaths(LEFT));
	}

	//Fill matrix
	for(size_t y = 1; y < sequenceA.length() + 1; y++) {
		for(size_t x = 1; x < sequenceB.length() + 1; x ++ ) {

			int diagonalScore = matrix[y-1][x-1].value + getBlossumValues(sequenceA[y-1], sequenceB[x-1], gapPenalty);
			int leftScore = maxYValues[y] - gapPenalty;
			int topScore = maxXValues[x] - gapPenalty;

			int maxValue = std::max(std::max(leftScore, topScore), diagonalScore);
			matrix[y][x].value = maxValue;

			if(maxValue == leftScore) {
				matrix[y][x].previousPathsList.push_front(PreviousPaths(LEFT));
			} else if (maxValue > leftScore) {
				maxYValues[y] = maxValue;
			}

			if(maxValue == topScore) {
				matrix[y][x].previousPathsList.push_front(PreviousPaths(TOP));
			} else if(maxValue > topScore) {
				maxXValues[x] = maxValue;
			}

			if(maxValue == diagonalScore) {
				matrix[y][x].previousPathsList.push_front(PreviousPaths(DIAGONAL));
			}
		}
	}

	std::vector<std::string> alignments = processNeedlemanMatrix(*matrix, sequenceB.length(), sequenceA.length(), sequenceA, sequenceB, "", gapPenalty);
//	for(std::vector<std::string>::iterator it = alignments.begin(); it != alignments.end(); ++it) {
//		std::cout << *it << std::endl;
//	}
	return alignments;
}

std::vector<std::string> processNeedlemanMatrix(cell *matrixPtr, int x, int y, std::string sequenceA, std::string sequenceB, std::string buffer, int gapPenalty) {
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
	std::list<PreviousPaths>::iterator it;
	for(it = matrixPtr[pos].previousPathsList.begin(); it != matrixPtr[pos].previousPathsList.end(); ++it) {
		switch(*it) {
			case LEFT: 
				leftAlignments = processNeedlemanMatrix(matrixPtr, x - 1, y, sequenceA, sequenceB, buffer + "-", gapPenalty);
				break;
			case TOP:
				topAlignments = processNeedlemanMatrix(matrixPtr, x, y - 1, sequenceA, sequenceB, buffer + "-", gapPenalty);
				break;
			case DIAGONAL:
				// Handles if both are - or both are chars
				if(sequenceA[y-1] == sequenceB[x-1]) {
					diagonalAlignments = processNeedlemanMatrix(matrixPtr, x - 1, y - 1, sequenceA, sequenceB, buffer + sequenceA[y-1], gapPenalty);
				// Handles if just sequenceA char is -
//				} else if(sequenceA[y-1] == '-') {
//					diagonalAlignments = processNeedlemanMatrix(matrixPtr, x - 1, y - 1, sequenceA, sequenceB, buffer + sequenceB[x-1], gapPenalty);
				} else {
					diagonalAlignments = processNeedlemanMatrix(matrixPtr, x - 1, y - 1, sequenceA, sequenceB, buffer + "-", gapPenalty);
				}
				break;
		}
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