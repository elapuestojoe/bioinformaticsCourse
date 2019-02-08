#include <string>
#include <iostream>
#include <vector>
#include <iterator>

#include "needlemanWunsch.h"

int sequenceMatches(std::string sequence);
std::string findBestAlignment(std::vector<std::string> alignments);

std::string multipleSequenceAlignment(std::vector<std::string> sequences, int gapPenalty) {
	
	std::cout << std::endl << "Alignments: " << std::endl;
	for(std::string sequence : sequences) {
		std::cout << sequence << std::endl;
	}
	
	if(sequences.size() == 0) {
		return "";
	} else if(sequences.size() == 1) {
		return sequences[0];
	}
	
	int bestAlignmentScore = 0;
	std::string bestAlignment, leftSequence, rightSequence;
	
	for(std::vector<std::string>::iterator firstIterator = sequences.begin(); firstIterator != std::prev(sequences.end()); ++firstIterator) {
		for(std::vector<std::string>::iterator secondIterator = std::next(firstIterator, 1); secondIterator != sequences.end(); ++secondIterator) {
			
			std::vector<std::string> alignments = needlemanWunsch(*firstIterator, *secondIterator, gapPenalty);
//			
			std::string bestLocalAlignment = findBestAlignment(alignments);
//	
			int score = sequenceMatches(bestLocalAlignment);
			if(score > bestAlignmentScore) {
				bestAlignmentScore = score;
				leftSequence = *firstIterator;
				rightSequence = *secondIterator;
				bestAlignment = bestLocalAlignment;
			}
			std::cout << "Trying to align sequences: " << *firstIterator << " with " << *secondIterator << " yields: " << std::endl;
			std::cout << bestLocalAlignment << std::endl;
			std::cout << "Score : " << score << std::endl;
		}
	}
	
	std::cout << "Best alignment is between " << leftSequence << " and " << rightSequence << " : " << bestAlignment << std::endl;
	std::cout << "Score: " << bestAlignmentScore << std::endl;
	
	std::vector<std::string> newAlignments = {bestAlignment};
	for(std::vector<std::string>::iterator it = sequences.begin(); it != sequences.end(); ++it) {
		if(*it != leftSequence && *it != rightSequence) {
			newAlignments.push_back(*it);
		}
	}
	
	return multipleSequenceAlignment(newAlignments, gapPenalty);
}

int sequenceMatches(std::string sequence) {
	int matches = 0;
	for(std::string::iterator it = sequence.begin(); it != sequence.end(); ++it) {
		*it != '-' ? matches++: 0;
	}
	return matches;
}

std::string findBestAlignment(std::vector<std::string> alignments) {
	
	if(alignments.size() == 1) {
		return alignments[0];
	}
	
	int maxScore = 0;
	std::string bestAlignment = "";

	for(std::vector<std::string>::iterator it = alignments.begin(); it != alignments.end(); ++it) {
		int alignmentScore = sequenceMatches(*it);
		if(alignmentScore > maxScore) {
			maxScore = alignmentScore;
			bestAlignment = *it;
		}
	}
	return bestAlignment;
}