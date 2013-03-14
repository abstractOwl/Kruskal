#include "DisjointSet.h"

DisjointSet::DisjointSet(int size)
{
	entries = new int[size];

	for (int i = 0, j = size; i < j; i ++) {
		entries[i] = -1;
	}
}

int DisjointSet::find(int pos)
{
	if (entries[pos] < 0) {
		return pos;
	} else {
		return find(entries[pos]);
	}
}

void DisjointSet::u(int v1, int v2)
{
	int r1 = find(v1);
	int r2 = find(v2);

	entries[r2] = r1;
}

