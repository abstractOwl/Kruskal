#ifndef HEAP_H
#define HEAP_H

#include <string>

using namespace std;

typedef struct HeapNode HeapNode;
struct HeapNode
{
	int		weight;
	string*	name;
};

class Heap
{
public:
	Heap(int size);
	HeapNode*	add(string *name, int weight);
	HeapNode*	min();
	HeapNode*	remove();

private:
	HeapNode	**entries;
	int			insertPos;

	int		left(int index);
	int		parent(int index);
	int		right(int index);
	void	downHeap(int index);
	void	upHeap(int index);
	void	swap(int first, int second);
};

#endif

