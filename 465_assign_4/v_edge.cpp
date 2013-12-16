#include "v_edge.h"

using namespace std;

v_edge::v_edge() {
	vertex1 = 0;
	vertex2 = 0;
	cost = 0;
}

v_edge::v_edge(int startVertex, int endVertex, int travelCost) {
	vertex1 = startVertex;
	vertex2 = endVertex;
	cost = travelCost;
}