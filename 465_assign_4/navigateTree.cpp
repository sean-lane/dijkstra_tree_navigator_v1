#include <vector>
#include <iostream>

#include "v_edge.h"
#include "vertex.h"

using namespace std;

int navigateTree(vector<v_edge> treeEdges, vector<vertex> vertexes, vector<int> &sequence, int startVertex, int endVertex, int &finalCost) {
	
	int endVertexIndex;
	int startVertexIndex;

	// find index of startVertex within vertexes
	for(unsigned int i = 0; i < vertexes.size(); i++) {
		if(startVertex == vertexes[i].vertexName) {
			startVertexIndex = i;
			break;
		}
	}

	// find index of endVertex within vertexes
	for(unsigned int i = 0; i < vertexes.size(); i++) {
		if(endVertex == vertexes[i].vertexName) {
			endVertexIndex = i;
			break;
		}
	}

	// base case
	if(startVertex == endVertex) {
		sequence.push_back(vertexes[startVertexIndex].vertexName);
		return finalCost;
	}
	else {
	
		// for loop checks traces backward to find a path (since tree is a MST)
		for(unsigned int i = 0; i < treeEdges.size(); i++) {
			if (endVertex == treeEdges[i].vertex2) {		// if we find a path pointing from end node
				finalCost = (finalCost + treeEdges[i].cost);
				sequence.push_back(treeEdges[i].vertex2);
				return navigateTree(treeEdges, vertexes, sequence, startVertex, treeEdges[i].vertex1, finalCost); // follow the node backward
			}
		}
	}

	// if navigation reaches this line, we cannot reach the node
	cout << "Node " << vertexes[endVertexIndex].vertexName << " cannot be reached from Node " << vertexes[startVertexIndex].vertexName << "\n";
	return -1;
}