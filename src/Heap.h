#ifndef HEAP_H
#define HEAP_H

typedef struct HeapNode HeapNode;
struct HeapNode
{
	int		weight;
	int		v1, v2;
};

class Heap
{
public:
	Heap(int size);
	HeapNode*	add(int v1, int v2, int weight);
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

