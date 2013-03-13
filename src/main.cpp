#include "Graph.h"
#include <iostream>

using namespace std;
int main()
{
	int L, N;
	cin >> L;
	cin >> N;
	Graph graph(L);
	Heap heap(N);

	/* Construct Graph */
	for (int i = 0; i < N; i++) {
		string node;
		int weight;

		cin >> node >> weight;

		int delim = node.find("-");
		string	n1 = node.substr(0, delim),
			n2 = node.substr(delim + 1, node.length());

		graph.edge(n1, n2, weight);
	}

	// Perform Kruskal's Algorithm
}

