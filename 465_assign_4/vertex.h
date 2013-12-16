#include <iostream>
using namespace std;

struct vertex {		// vertex models the vertexes of a graph
	// parameters
	int vertexName;
	int currentCost;

	// default constructor
	vertex();

	// init-constructor 1
	vertex(int vertex_name);

	// init-constructor 2
	vertex(int vertex_name, int current_cost);
};