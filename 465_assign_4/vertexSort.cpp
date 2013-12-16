#include <vector>

#include "vertex.h"

using namespace std;

vector<vertex> vertexSort(vector<vertex> sortVector) {
	vertex temp;
	int swaps = 1;

	while(swaps != 0) {

		// reset counter variable
		swaps = 0;

		// use bubble sort to sort vertexes into their proper indexes
		for(unsigned int i = 0; i < (sortVector.size() - 1); i++) {
			if (sortVector[i].vertexName > sortVector[i+1].vertexName) {
				temp.vertexName = sortVector[i+1].vertexName;
				temp.currentCost = sortVector[i+1].currentCost;
				sortVector[i+1] = sortVector[i];
				sortVector[i] = temp;
				swaps++;
			}
		}
	}
	return sortVector;
}