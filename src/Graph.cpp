#include "Graph.h"
#include "Heap.h"
#include <iostream>

using namespace std;
Graph::Graph (int size)
{
	length = 0;
	max = size;

	entries		=	new string[size];
	adjMatrix	=	new int[size * size];
}

/**
 * Make edge between nodes
 */
void Graph::edge (string n1, string n2, int weight)
{
	int p1 = -1, p2 = -1;
	for (int i = 0; i < length; i++) {
		if (entries[i] == n1) {
			p1 = i;
		} else if (entries[i] == n2) {
			p2 = i;
		}

		if (p1 != -1 && p2 != -1) {
			break;
		}
	}

	if (p1 == -1) {
		p1 = length;
		entries[length++] = n1;
	}
	if (p2 == -1) {
		p2 = length;
		entries[length++] = n2;
	}

	adjMatrix[p1 * max + p2] = weight;
}

// Get weight of edge between nodes
int Graph::weight (string n1, string n2)
{
	int p1 = -1, p2 = -1;
	for (int i = 0; i < length; i++) {
		if (entries[i] == n1) {
			p1 = i;
		} else if (entries[i] == n2) {
			p2 = i;
		}

		if (p1 != -1 && p2 != -1) {
			break;
		}
	}

	return adjMatrix[p1 * max + p2];
}

