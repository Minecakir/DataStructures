#ifndef _AVLNODE_H_
#define _AVLNODE_H_
#include <stdio.h>
#include"WordFreq.h"
struct AVLNode {
	WordFreq words;
	int height;
	AVLNode* left, * right;
	AVLNode(string word) : words(word) { words.freq++; left = right = NULL; height = 0; }
};

#endif