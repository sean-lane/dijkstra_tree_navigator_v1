#include <iostream>
#include <vector>

#include "v_edge.h"
#include "vertex.h"

using namespace std;

// vertexDefine collects all the edges for a given vertex
vector<v_edge> vertexDefine(vector<v_edge> edges, int vertex) {

	// variables for loop
	vector<v_edge> collection;
	v_edge temp;

	// for each element in edges, check to see if the edge is for our current vertex
	for(unsigned int i = 0; i < edges.size(); i++) {
		if(edges[i].vertex1 == vertex) {
			temp.vertex1 = edges[i].vertex1;
			temp.vertex2 = edges[i].vertex2;
			temp.cost = edges[i].cost;

			// if so, add to collection
			collection.push_back(temp);
		}
	}
	return collection;
}

// primary function: runs dijkstra's algorithm on a set of edges and vertexes
vector<v_edge> dijkstraMST(vector<v_edge> edges, vector<v_edge> &finalEdges, vector<vertex> &vertexes, vector<vertex> &visitedVertex, int startVertex) {

	int failFlag = 1;

	// base case 1: we have visited all vertexes, return
	if (visitedVertex.size() == vertexes.size()) {
		return finalEdges;

	} 
	else {

		// collect edges for a vertex
		vector<v_edge> collection = vertexDefine(edges, startVertex);
		int vertex1Index;
		int vertex2Index;

		// for each edge, calculate the current cost to the connected nodes
		for(unsigned int i = 0; i < collection.size(); i++) {

			// collect starting and ending vertex index
			for(unsigned int j = 0; j < vertexes.size(); j++) {
				if(collection[i].vertex2 == vertexes[j].vertexName) {
					vertex2Index = j;
					break;
				}
			}

			for(unsigned int j = 0; j < vertexes.size(); j++) {
				if(collection[i].vertex1 == vertexes[j].vertexName) {
					vertex1Index = j;
					break;
				}
			}
		
			if((collection[i].cost + vertexes[vertex1Index].currentCost) < vertexes[vertex2Index].currentCost) {
				vertexes[vertex2Index].currentCost = (collection[i].cost + vertexes[vertex1Index].currentCost);

				// check to see if there is an edge to that node already
				for(unsigned int j = 0; j < finalEdges.size(); j++) {
					if(finalEdges[j].vertex2 == vertexes[vertex2Index].vertexName) {
						finalEdges.erase(finalEdges.begin() + j);
					}
				}

				finalEdges.push_back(collection[i]);
			}
			failFlag = 0;

		}
		// base case 2: there are no edges leaving this vertex
		if (failFlag == 1) {
			return finalEdges;
		}
		else {

			// otherwise place this vertex in the visited vector, visit next one
			visitedVertex.push_back(vertexes[vertex1Index]);

			// visit all nodes connected to this node
			for(unsigned int i = 0; i < collection.size(); i++) {
				finalEdges = dijkstraMST(edges, finalEdges, vertexes, visitedVertex, collection[i].vertex2);
			}

			return finalEdges;
		}
	}
}