#include "vertex.h"

using namespace std;

vertex::vertex() {
	vertexName = 0;
	currentCost = 9999999;
}

vertex::vertex(int vertex_name) {
	vertexName = vertex_name;
	currentCost = 9999999;
}

vertex::vertex(int vertex_name, int current_cost) {
	vertexName = vertex_name;
	currentCost = current_cost;
}