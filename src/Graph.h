#ifndef GRAPH_H
#define GRAPH_H

#include <string>

using namespace std;

class Graph
{
public:
	Graph(int size);
	void	edge(string n1, string n2, int weight);
	int	weight(string n1, string n2);

private:
	string	*entries;
	int	*adjMatrix;
	int	length;
	int	max;
};

#endif

