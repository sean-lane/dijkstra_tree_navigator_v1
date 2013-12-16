#pragma once

#include <iostream>

using namespace std;

struct v_edge {		// v_edge models the edge of a graph
	// parameters
	int vertex1;
	int vertex2;
	int cost;

	// default constructor
	v_edge();

	// init- constructor
	v_edge(int startVertex, int endVertex, int travelCost);
};