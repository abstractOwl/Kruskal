#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

class DisjointSet
{
public:
	DisjointSet(int size);
	int	find(int pos);
	void	u(int v1, int v2);

private:
	int	*entries;
};

#endif

