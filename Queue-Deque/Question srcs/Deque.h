#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <stdio.h>

struct DequeNode {
	int item;
	DequeNode *prev, *next;

	DequeNode(int item) {
		this->item = item;
		this->prev = this->next = NULL;
	} //end-DequeNode
};

class Deque {
	// Normally, the class member variables are defined as private
	// I made them public solely for testing purposes
public:  
	DequeNode*head, *tail;
	int noOfItems;
public:
	Deque();
	~Deque();
	void AddFront(int item);
	void AddRear(int item);
	int RemoveFront();
	int RemoveRear();
	int Front();
	int Rear();
	bool IsEmpty() { return noOfItems == 0; }
	int  Size() { return noOfItems; }
};

#endif
