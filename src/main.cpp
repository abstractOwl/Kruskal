#include "DisjointSet.h"
#include "Graph.h"
#include "Heap.h"
#include <cstdlib>
#include <iostream>

using namespace std;
int main()
{
	int L, N;
	cin >> L;
	cin >> N;

	DisjointSet disjSet(L);
	Graph graph(L);
	Heap heap(N);

	/* Construct Graph */
	for (int i = 0; i < N; i++) {
		string node;
		int weight;

		cin >> node >> weight;

		int	delim	=	node.find("-"),
			v1	=	atoi(node.substr(1, delim - 1).c_str()) - 1,
			v2	=	atoi(node.substr(delim + 2, node.length()).c_str()) - 1;

		graph.edge(v1, v2, weight);
		heap.add(v1, v2, weight);
	}

	// Perform Kruskal's Algorithm
	for (int i = 0; i < N; i++) {
		HeapNode* top = heap.remove();
		if (disjSet.find(top->v1) != disjSet.find(top->v2)) {
			cout << "v" << top->v1 + 1 << "-v" << top->v2 + 1 << endl;
			disjSet.u(top->v1, top->v2);
		}
	}
}

