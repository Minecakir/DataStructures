/*
* @author: 152120171104 Ezgi Ozdikyar
* @author: 152120181058 Mine Cakir
* @date: 18.11.2020
*/
#include <stdio.h>
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include "Poly.h"

using namespace std;
//-------------------------------------------------
// Creates a polynomial from an expression.
// Returns a pointer to the first PolyNode in the list (head of the list)
//
// Expression will be of the following sort:
// Ex1: 2.3x^4 + 5x^3 - 2.64x - 4
// Ex2: -4.555x^10 - 45.44
// Ex3: x^6 + 2x^4 - x^3 - 6.3x + 4.223 
// Ex4: 34
// Ex5: -x+1
// Ex6: -3x^4    +   4x
// Ex7: -2x  - 5
//

PolyNode* CreatePoly(char* expr)
{
	string str;
	str = expr;
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	PolyNode* node = NULL;
	if (str == "")
		return node;
	int strSize = str.size();

	//	How many monomials has the polynomial?
	int termCounter = 1; // Count how many + and - in polynomial.
	for (int i = 1; i < strSize; ++i) {
		if (str[i] == '+' || str[i] == '-')
			termCounter++;
	}
	int term = termCounter;
	//String parsing 
	if (isdigit(str[0]))
	{
		str.insert(0, "+");
	}
	if (str[0] == 'x')
	{
		str.insert(0, "+");
	}	
	str.append("+");
	strSize = str.size();

	//	Extract
	termCounter = 0;
	int j = 0;
	string *strArray=new string[100];
	for (int i = 1; i < strSize; ++i)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			strArray[termCounter++] = str.substr(j, i - j);
			j = i;
		}
	}
	for (int i = 0; i < term; ++i)
	{
		if (strArray[i][1] == 'x')	//x is after the +/- sign 
		{
			strArray[i].insert(1, "1");
		}
		bool flag = false;	
		int len = strArray[i].size();
		for (int j = 1; j < len; ++j)
		{
			if (strArray[i][j] == 'x')
			{
				flag = true;
				if (j == len - 1)
					strArray[i].append("^1");
				break;
			}
		}	
		if (!flag)
		{
			strArray[i].append("x^0");
		}		
	}
	//	Extracting the coefficients and exponents as numbers
	int exp;
	double coeff;
	for (int i = 0; i < term; ++i)
	{
		int strSize = strArray[i].size();
		for (int j = 0; j < strSize; ++j)
		{
			if (strArray[i][j] == '^')
			{
				exp = stoi(strArray[i].substr(j + 1, strSize - j));
				coeff = stod(strArray[i].substr(0, j));
				node = AddNode(node, coeff, exp);
				break;
			}
		}
	}
	return node;
}

/// -------------------------------------------------
/// Walk over the poly nodes & delete them
///
void DeletePoly(PolyNode* poly)
{
	while (poly)
	{
		PolyNode* old = poly;
		poly = poly->next;
		delete old;
	}
} // end-DeletePoly
	
//-------------------------------------------------
// Adds a node (coefficient, exponent) to poly. If there already 
// is a node with the same exponent, then you simply add the coefficient
// to the existing coefficient. If not, you add a new node to polynomial
// Returns a pointer to the possibly new head of the polynomial.
//
PolyNode* AddNode(PolyNode* head, double coef, int exp)
{
	if (coef == 0.0)
		return head;
	PolyNode* node = new PolyNode;
	node->coef = coef;
	node->exp = exp;
	if (head == NULL)
	{
		node->next = NULL;
		return node;
	}
	PolyNode* p = new PolyNode;
	PolyNode* q = new PolyNode;
	p = q = head;
	while (q != NULL && q->exp >= exp)
	{
		if (q->exp == exp)
		{
			node->coef = node->coef + q->coef;
			if (node->coef == 0.0)
			{
				/*
				* Delete variable x with coefficient 0.
				*/
				if (p == head && q == head) 
				{
					p = p->next;
					q = q->next;
					head = p;
				}
				else 
				{
					p->next = q->next;
					q = q->next;
				}
			}
			else
			{
				node->next = q->next;
				q = q->next;
				break;
			}
		}
		else
		{
			p = q;
			q = q->next;
		}
	}
	if (node->coef == 0.0) {
		return head;
	}
	if (q == head)
	{
		node->next = q;
		return node;
	}
	else if (q == NULL)
	{
		p->next = node;
		node->next = NULL;
	}
	else
	{
		node->next = q;
		p->next = node;
	}

	return head;
}// end-AddNode

//-------------------------------------------------
// Adds two polynomials and returns a new polynomial that contains the result
// Computes: poly3 = poly1 + poly2 and returns poly3
//
PolyNode* Add(PolyNode* poly1, PolyNode* poly2) {
	PolyNode* node = NULL;
	while (poly1 != NULL && poly2 != NULL)
		/*if poly1 and poly2 not equal NULL */
	{
		if (poly1->exp > poly2->exp) {
			/*if poly 1 exp > poly2 exp add poly1 to node then equal poly1 to next of poly1*/
			node = AddNode(node, poly1->coef, poly1->exp);
			poly1 = poly1->next;
		}
		else if (poly1->exp < poly2->exp) {
			/*if poly 2 exp > poly1 exp add poly2 to node then equal poly2 to next of poly2*/
			node = AddNode(node, poly2->coef, poly2->exp);
			poly2 = poly2->next;
		}
		else {
			/*if poly 1 exp = poly2 exp sum poly1 and poly2 then
					Equal poly1 and poly2 to their next*/
			node = AddNode(node, (poly1->coef) + (poly2->coef), poly1->exp);
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
	}
	return node;
} //end-Add

//-------------------------------------------------
// Subtracts poly2 from poly1 and returns the resulting polynomial
// Computes: poly3 = poly1 - poly2 and returns poly3
//
PolyNode* Subtract(PolyNode* poly1, PolyNode* poly2) {
	PolyNode* node = NULL;
	/*	We adapted the add function for subtract*/
	while (poly1 != NULL && poly2 != NULL)
	{
		if (poly1->exp > poly2->exp) {
			node = AddNode(node, poly1->coef, poly1->exp);
			poly1 = poly1->next;
		}
		else if (poly1->exp < poly2->exp) {
			node = AddNode(node, poly2->coef, poly2->exp);
			poly2 = poly2->next;
		}
		else {
			node = AddNode(node, (poly1->coef) - (poly2->coef), poly1->exp);
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
	}
	return node;
} //end-Substract

//-------------------------------------------------
// Multiplies poly1 and poly2 and returns the resulting polynomial
// Computes: poly3 = poly1 * poly2 and returns poly3
//
PolyNode* Multiply(PolyNode* poly1, PolyNode* poly2) {
	PolyNode* node = NULL;
	PolyNode* temp = poly2;
	while (poly1 != NULL)
	{
		while (poly2 != NULL)
		{
			/*Multiply coef and exponent values.*/
			node = AddNode(node, (poly1->coef * poly2->coef), (poly1->exp + poly2->exp));
			poly2 = poly2->next;
		}
		poly2 = temp;
		poly1 = poly1->next;
	}
	DeletePoly(temp); /*delete the polynomial used for the next multiplication*/
	return node;
} //end-Multiply

//-------------------------------------------------
// Evaluates the polynomial at a particular "x" value and returns the result
//
double Evaluate(PolyNode *poly, double x)
{
	double result = 0.0;
	for (; poly != NULL; poly = poly->next)
		/*Substitute the x value and multiply the result by the coefficient*/
		result += poly->coef*pow(x, poly->exp);
	return result;
} //end-Evaluate

//-------------------------------------------------
// Computes the derivative of the polynomial and returns it
// Ex: poly(x) = 3x^4 - 2x + 1-->Derivative(poly) = 12x^3 - 2
//
PolyNode *Derivative(PolyNode *poly)
{
	PolyNode* p2 = NULL;
	while (poly != NULL)
	{
		/*Take the exponent in front of x and multiply it by the coefficient of x*/
		p2 = AddNode(p2, poly->coef * poly->exp, poly->exp - 1);
		poly = poly->next;
	}
	return p2;
} //end-Derivative

//-------------------------------------------------
// Plots the polynomial in the range [x1, x2].
// -39<=x1<x2<=39
// -12<=y<=12
// On the middle of the screen you gotta have x & y axis plotted
// During evaluation, if "y" value does not fit on the screen,
// then just skip it. Otherwise put a '*' char depicting the curve
//
void Plot(PolyNode *poly, int x1, int x2){
	int yvalues[100],xvalues[100], y;
	int counter = 0,a,b;
	int matris[24][78];
	for (int i = x1; i <= x2; i++)
	{
		y = round(Evaluate(poly, i));
		if (y > 12 || y < -12)
			continue;
		xvalues[counter] = i;
		yvalues[counter] = y;
		counter++;
	}
	for (int i = -12; i <= 12; i++)
	{
		for (int j = x1; j <= x2; j++)
		{
			for (int m = 0; m < counter; m++)
			{
				if (xvalues[m] == j && yvalues[m] == i)
				{
					a = 12 - i;
					b = 39 + j;
					matris[a][b] = 1;
				}
			}
		}
	}
	cout << setw(3) << " (Y)" << endl;
	int number = 12;
	int number2 = 39;
	for (int j = 0; j <= 24; j++)
	{
		if (number != -13)
		{
			cout << setw(3) << number << "|";
			number--;
		}
		else
		{
			cout << "    ";
		}
		for (int i = 0; i <= 78 ; i++)
		{
			if (matris[j][i] == 1 && i <= x2 - x1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	for (int k =79;k>=0; k--)
	{
		if (k == 79)
		{
			cout << " (X)";
		}
		else
			cout << "_";
	}
	cout << endl<<"    ";
	for (int k = 39; k >= 0; k--)
	{
		cout << k%10;
	}
	for (int k = 1; k <=39; k++)
	{
		cout << k % 10;
	}
} //end-Plot
