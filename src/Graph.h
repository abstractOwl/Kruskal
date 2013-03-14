#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
public:
	Graph(int size);
	void	edge(int n1, int n2, int weight);
	int	weight(int n1, int n2);

private:
	int	*entries;
	int	*adjMatrix;
	int	length;
	int	max;
};

#endif

