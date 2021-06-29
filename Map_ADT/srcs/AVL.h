#ifndef _AVL_H_
#define _AVL_H_

#include <iostream>
#include <vector>
#include <stack>
#include<string>
#include "AVLNode.h"
using namespace std;

class AVL {
private:
	AVLNode* root;
	int counter;
	int maxFrequency;
	void printAux(AVLNode* node);
	void eraseTreeNodes(AVLNode* node);
	void max(AVLNode*);
public:
	AVL() { root = NULL; counter = 0, maxFrequency = 0; }
	~AVL() { eraseTreeNodes(root); root = NULL; }
	AVLNode* min();
	void add(string word);
	void remove(AVLNode*);
	int getCounter() { return counter; }
	void print();
	int getMaxFrequency();
};
#endif
