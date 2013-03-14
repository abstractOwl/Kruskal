#include <cmath>
#include "Heap.h"

// constructor
Heap::Heap(int size)
{
	entries = new HeapNode*[size];
	insertPos = 0; // First empty index
}

// Add new node to heap
HeapNode* Heap::add(int v1, int v2, int weight)
{
	HeapNode* node		=	new HeapNode;
	node->v1			=	v1;
	node->v2			=	v2;
	node->weight		=	weight;
	entries[insertPos]	=	node;

	upHeap(insertPos);

	insertPos++;

	return node;
}

// Get minimum node in heap (root)
HeapNode* Heap::min()
{
	return entries[0];
}

// Remove minimum node from heap
HeapNode* Heap::remove()
{
	HeapNode* target = entries[0];

	// Replace root with last element
	entries[0] = entries[insertPos - 1];
	insertPos--;

	downHeap(0);

	return target;
}

// Return index of current node's left child
int Heap::left(int index)
{
	return 2 * index + 1;
}
// Return index of current node's right child
int Heap::right(int index)
{
	return left(index) + 1;
}
// Return index of current node's parent
int Heap::parent(int index)
{
	return (int)(floor((index - 1) / 2));
}

// Swap nodes
void Heap::swap(int first, int second)
{
	HeapNode* tmp		=	entries[first];
	entries[first]	=	entries[second];
	entries[second]	=	tmp;
}

// Reconstruct heap after delete
void Heap::downHeap(int index)
{
	HeapNode* curr		=	entries[index];
	HeapNode* lChild	=	entries[left(index)];
	HeapNode* rChild	=	entries[right(index)];

	if (left(index) < insertPos
		&& lChild->weight < rChild->weight
		&& lChild->weight < curr->weight) {
		swap(index, left(index));
		downHeap(left(index));
	} else if (right(index) < insertPos
		&& rChild->weight < lChild->weight
		&& rChild->weight < curr->weight) {
		swap(index, right(index));
		downHeap(right(index));
	}
}

// Reconstruct heap after insert
void Heap::upHeap(int index)
{
	if (index == 0) return;

	if (entries[index]->weight < entries[parent(index)]->weight) {
		swap(index, parent(index));
	}

	upHeap(parent(index));
}

