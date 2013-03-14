#include "Graph.h"

Graph::Graph (int size)
{
	length = 0;
	max = size;

	entries		=	new int[size];
	adjMatrix	=	new int[size * size];
}

/**
 * Make edge between nodes
 */
void Graph::edge (int v1, int v2, int weight)
{
	adjMatrix[v1 * max + v2] = weight;
	adjMatrix[v2 * max + v1] = weight;
}

// Get weight of edge between nodes
int Graph::weight (int v1, int v2)
{
	return adjMatrix[v1 * max + v2];
}

