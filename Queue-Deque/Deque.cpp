/**
* @author: Ezgi Özdikyar -> 152120171104
* @author: Mine ÇAKIR -> 152120181058
* @date:16.12.2020
*/
#include "Deque.h"
#include<iostream>
///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque()
{
	this->head = NULL;
	this->tail = NULL;
	this->noOfItems = 0;
} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() 
{
	while (!this->head) 
	{
		DequeNode* node = head;
		head = head->next;
		delete node;
	}
	noOfItems = 0;
} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
/// 
void Deque::AddFront(int item) 
{
	DequeNode* node = new DequeNode(item);
	node->prev = node->next = NULL;
	if (this->head == NULL)
		this->head = this->tail = node;
	else
	{
		node->next = head;
		head->prev = node;
		head = node;
		head->prev = NULL;
	}
	noOfItems++;
} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {
	DequeNode* node = new DequeNode(item);
	node->next = node->prev = NULL;
	if (this->head == NULL)
		this->head = this->tail = node;
	else
	{
		this->tail->next = node;
		node->prev = this->tail;
		this->tail = node;
		tail->next = NULL;
	}
	noOfItems++;
} //end-AddRear

///------------------------------------------------------
/// Removes and return the item at the front of the Deque
/// If the Deque is empty, throws an exception
/// 
int Deque::RemoveFront() {
	DequeNode* tempHead = this->head;
	int item;
	if (this->head == NULL)
		throw std::exception("Dequeue::RemoveFront: Empty queue");
	else
	{
		item = head->item;
		this->head = this->head->next;
		if (!this->head)
			this->tail = NULL;
		delete tempHead;
		tempHead = NULL;
	}
	this->noOfItems--;
	return item;
} //end-RemoveFront

///------------------------------------------------------
/// Removes and return the item at the rear of the Deque
/// If the Deque is empty, throws an exception
/// 
int Deque::RemoveRear() {
	DequeNode* tempRear = this->tail;
	int item;
	if (this->head == NULL)
		throw std::exception("Dequeue::RemoveRear: Empty queue");
	else
	{
		item = tempRear->item;
		this->tail = this->tail->prev;
		if (!this->head)
			this->tail = NULL;
		delete tempRear;
		tempRear = NULL;
	}
	this->noOfItems--;
	return item;
} //end-RemoveRear

///------------------------------------------------------
/// Returns the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throws an exception
/// 
int Deque::Front() {
	if (this->head == NULL)
		throw std::exception("Dequeue::Front: Empty queue");
	else
		return this->head->item;
} //end-Front

///------------------------------------------------------
/// Returns the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throws an exception
/// 
int Deque::Rear() {
	if (this->head == NULL)
		throw std::exception("Dequeue::Rear: Empty queue");
	else
		return this->tail->item;
} //end-Rear
