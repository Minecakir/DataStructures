#include <stdio.h>
#include <iostream>
#include "Deque.h"

using namespace std;

int Test1();
int Test2();


///--------------------------------------------------------------------
/// main function
///
int main() {
	int grade = 0;

	grade += Test1();
	grade += Test2();

	printf("Your grade is: %d\n", grade);

	return 0;
} //end-main

///-------------------------------------------------------------------
/// Test1
///
int Test1() {
	try {
		Deque dq;

		dq.AddFront(10);
		dq.AddFront(20);

		if (dq.head->item != 20) return 0;
		if (dq.tail->item != 10) return 0;

		dq.AddFront(30);
		dq.AddFront(40);
		dq.AddRear(50);
		dq.AddRear(60);
		dq.AddRear(70);

		if (dq.Front() != 40) return 0;
		if (dq.Rear() != 70) return 0;
		if (dq.RemoveFront() != 40) return 0;
		if (dq.RemoveRear() != 70) return 0;

		if (dq.Front() != 30) return 0;
		if (dq.Rear() != 60) return 0;
		if (dq.RemoveFront() != 30) return 0;
		if (dq.RemoveRear() != 60) return 0;

		if (dq.Front() != 20) return 0;
		if (dq.Rear() != 50) return 0;
		if (dq.RemoveFront() != 20) return 0;
		if (dq.RemoveRear() != 50) return 0;

		if (dq.Front() != 10) return 0;
		if (dq.Rear() != 10) return 0;
		if (dq.RemoveFront() != 10) return 0;
		if (!dq.IsEmpty()) return 0;
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
	} //end-catch

	return 20;
} //end-Test1

///-------------------------------------------------------------------
/// Test2
///
int Test2() {
	try {
		Deque dq;

		int N = 100;
		for (int i = 1; i <= N; i++) dq.AddFront(i);

		// Walk forward
		DequeNode* p = dq.head;
		for (int i = N; i >= 1; i--) {
			if (p->item != i) return 0;
			p = p->next;
		} //end-for

		// Walk backwards
		p = dq.tail;
		for (int i = 1; i <= N; i++) {
			if (p->item != i) return 0;
			p = p->prev;
		} //end-for

		for (int i = 1; i <= N; i++) dq.AddRear(i);

		for (int i = N; i >= 1; i--) {
			if (dq.Front() != i) return 0;
			if (dq.RemoveFront() != i) return 0;
		} //end-for

		for (int i = N; i >= 1; i--) {
			if (dq.Rear() != i) return 0;
			if (dq.RemoveRear() != i) return 0;
		} //end-for

		if (!dq.IsEmpty()) return 0;
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
	} //end-catch

	return 20;
} //end-Test2

