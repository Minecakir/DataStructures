#include <vector>
#include "AVL.h"
using namespace std;

void AVL::eraseTreeNodes(AVLNode* node) {
	if (node == NULL) return;
	eraseTreeNodes(node->left);
	eraseTreeNodes(node->right);
	delete node;
} 

AVLNode* AVL::min() {
	if (root == NULL) throw std::exception("AVL::min - Tree is empty");
	AVLNode* p = root;
	while (p->left != NULL)
	{
		p = p->left;
	}
	return p;
} 

void AVL::add(string word) 
{
	AVLNode* parent = NULL;
	AVLNode* current = root;
	while (current) 
	{
		parent = current;
		if (word == current->words.word)
		{
			current->words.freq++;
				return;
		}
		else if (word < current->words.word) 
			current = current->left;
		
		else 
			current = current->right;		
	} 
	AVLNode* node = new AVLNode(word);
	counter++;
	if (root == NULL) 
		root = node;
	else if (word < parent->words.word)
		parent->left = node;
	else 
		parent->right = node;
} 

void AVL::remove(AVLNode* min) {
	AVLNode* parent = NULL;
	AVLNode* current = root;
	while (current && current != min)
	{
		parent = current;
		if (min->words.word < current->words.word)
			current = current->left;
		else
			current = current->right;
	}
	if (current == NULL) return;   
	if (current->left && current->right)
	{
		AVLNode* qp = current;
		AVLNode* q = current->left;

		while (q->right)
		{
			qp = q;
			q = q->right;
		} 
		current->words.word = q->words.word;
		parent = qp;
		current = q;
	} 
	if (current == root)
	{
		root = root->left ? root->left : root->right;
		delete current;
		return;
	} 
	if (current == parent->left) 
		parent->left = current->left ? current->left : current->right;
	else               
		parent->right = current->left ? current->left : current->right;
	delete current;
} 
void AVL::max(AVLNode *node) 
{
	if (!node)
		return;
	if (node->words.freq > maxFrequency)
		maxFrequency = node->words.freq;

	max(node->left);
	max(node->right);
}

int AVL::getMaxFrequency() {
	max(root);
	return maxFrequency;
}

void AVL::print() 
{
	printf("AVL Keys: ");
	printAux(root);
	printf("\n");
} 

void AVL::printAux(AVLNode* node) {
	if (node == NULL) return;
	printAux(node->left);
	cout << node->words.word<<" ";
	cout << node->words.freq << " ";
	printAux(node->right);
} // end-printAux
