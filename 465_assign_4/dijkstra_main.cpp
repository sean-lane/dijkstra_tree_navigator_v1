#include <fstream>
#include <vector>
#include <iostream>

#include "v_edge.h"
#include "vertex.h"

using namespace std;


vector<v_edge> dijkstraMST(vector<v_edge> edges, vector<v_edge> &finalEdges, vector<vertex> &vertexes, vector<vertex> &visitedVertex, int startVertex);

vector<vertex> vertexSort(vector<vertex> sortVector);

int navigateTree(vector<v_edge> treeEdges, vector<vertex> vertexes, vector<int> &sequence, int startVertex, int endVertex, int &finalCost);

void main() {
	
	// vectors for passing graph information around
	vector<v_edge> edgeStorage;
	vector<v_edge> finalTree;
	vector<int> sequence;
	vector<vertex> vertexes;
	vector<vertex> visitedVertex;

	// input file
	ifstream input("graph_input.txt");
	
	// graph information variables
	v_edge temp;
	int beginningNode;
	vertex vertMove;
	int vertFlag;
	int finalCost;

	// read in from input file
	if (input.is_open() == true) {

		input >> beginningNode;

		while(!input.eof()) {

			input>>temp.vertex1;
			input>>temp.vertex2;
			input>>temp.cost;

			// allocate edge array
			edgeStorage.push_back(temp);
		}


		// allocate vertexes
		if(vertexes.empty()) {
			vertMove.vertexName = edgeStorage[0].vertex1;
			vertexes.push_back(vertMove);
		}
		for(unsigned int i = 0; i < edgeStorage.size(); i++) {
			
				// check edge vertex 1 for vertexes
				vertFlag = 1;
				for(unsigned int j = 0; j < vertexes.size(); j++) {
					if (edgeStorage[i].vertex1 == vertexes[j].vertexName) {
						vertFlag = 0;
					}
				}

				if(vertFlag == 1) {
					vertMove.vertexName = edgeStorage[i].vertex1;
					vertexes.push_back(vertMove);
				}

				// check edge vertex 2 for vertexes
				vertFlag = 1;
				for(unsigned int j = 0; j < vertexes.size(); j++) {
					if (edgeStorage[i].vertex2 == vertexes[j].vertexName) {
						vertFlag = 0;
					}
				}

				if(vertFlag == 1) {
					vertMove.vertexName = edgeStorage[i].vertex2;
					vertexes.push_back(vertMove);
				}
			}

	}else{
		cout << "File \"graph_input.txt\" not found in the target directory.";
	}

	if(!(edgeStorage.empty())) {
		// 0 the cost of the first node
		for(unsigned int i = 0; i < vertexes.size(); i++) {
			if(beginningNode == vertexes[i].vertexName) {
				vertexes[i].currentCost = 0;
			}
		}

		// sort vertexes in order of index for easy indexing in dijkstraMST
		vertexes = vertexSort(vertexes);

		// calculate MST from edges
		finalTree = dijkstraMST(edgeStorage, finalTree, vertexes, visitedVertex, beginningNode);

		// output pathing
		for(unsigned int i = 0; i < vertexes.size(); i++) {

			cout << "From " << beginningNode << " to " << vertexes[i].vertexName << ":\n";
	
			sequence.clear();
			finalCost = 0;
			
			// navigate through tree, display pathing
			finalCost = navigateTree(finalTree, vertexes, sequence, beginningNode, vertexes[i].vertexName, finalCost);
			
			// if sequence is empty, the navigate algorithm already displayed answer of "no path"
			if (!(sequence.empty())) {
				cout << "The shortest path is: ";
				for(unsigned int j = sequence.size(); j > 0; j--) {
					cout << sequence[(j-1)] << "->";
				}

				cout << "\nThe distance is: " << finalCost << "\n";
			}
		}
	}
	system("pause");
}