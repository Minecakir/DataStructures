/*
* @author: 152120181058 Mine ÇAKIR
* @author: 152120171104 Ezgi ÖZDIKYAR
* @brief: This program finds how many blobs in file with using recursive functions.
* @date:28/10/2020
*/
#include <iostream>
#include <fstream>// for file operations
#include <string>// for (string)
#include<iomanip>// for setw()
using namespace std;
float coMRow;//Center of mass for row
float coMCol;//Center of mass for col
void matrixTopFigure(int, int);
/**
* @brief	:This function creates top figures for matrix.
* @param	:Includes row and col from file.
*/
void matrixDownFigure(int, int);
/**
* @brief	:This function creates down figures for matrix.
* @param	:Includes row and col from file.
*/
int blobCount(char** blobArray, int blobRow, int blobCol, int r, int c);
/**
* @brief	:This function findes how many blobs in file.
* @param	:Includes 2D array, row and col from file, row and col for searching.
*/
int main()
{
	string fileName;
	string r, c;// search row and col;
	int blobRow = 0, blobCol = 0;
	int totalBlob = 0;
	char image;//For taking a blobs image from the file
	int pixel; //How many x in blob
	fstream dataFile;
	while (1)
	{
		printf("Enter the file name: ");  /*Ask file name from the user and open the file*/
		getline(cin, fileName);
		dataFile.open(fileName, ios::in);
		if (dataFile.is_open())
		{
			dataFile >> r >> c;
			break;
		}
		else
		{
			cout << "The file " << fileName << " was not found.\n";
		}
	}
	//cout <<"Row from the file: "<<r <<"Col from the file: "<< c << endl;
	blobRow = stoi(r);               //Converted from character to integer for Row
	blobCol = stoi(c);              //Converted from character to integer for Column
	//Created 2D Dynamic Array
	char** blobArray;
	blobArray = new char* [blobRow];
	for (int i = 0; i < blobRow; i++)
	{
		blobArray[i] = new char[blobCol];
	}
	matrixTopFigure(blobRow, blobCol);
	// Printed Image
	for (int i = 0; i < blobRow; i++) {
		cout << i % 10 << "|";
		for (int j = 0; j < blobCol; j++) {
			dataFile.get(image);
			if (image != '\n')
			{
				//cout << image;
				blobArray[i][j] = image;
				cout << blobArray[i][j];
			}
			else
				j--;
		}
		cout << "|" << i % 10 << endl;
	}
	matrixDownFigure(blobRow, blobCol);
	cout << endl << "+------+------------+---------+------------+" << endl;
	cout << "| BLOB | NoOfPixels | CoM Row | CoM Column |";
	cout << endl << "+------+------------+---------+------------+" << endl;
	for (int row = 0; row < blobRow; row++) {
		for (int col = 0; col < blobCol; col++) {
			//Check for a blob.
			pixel = blobCount(blobArray, blobRow, blobCol, row, col);
			if (pixel != 0)
			{
				totalBlob++;
				cout << "|" << setw(6) << totalBlob << "|";
				cout << setw(12) << fixed << setprecision(2) << pixel << "|" << setw(9) << coMRow / pixel << "|" << setw(12) << coMCol / pixel << "|" << endl;
				coMRow = 0;
				coMCol = 0;
			}
		}
	}
	cout << "+------+------------+---------+------------+" << endl;
	/*printf("Number of blobs =%d", totalBlob);*/
	for (int i = 0; i < blobRow; i++)
	{
		delete[]blobArray[i];
	}
	delete[]blobArray;
	dataFile.close();
	cout << endl;
	system("pause");
	return 0;
}

void matrixTopFigure(int blobRow, int blobCol)
{
	cout << "  ";
	//Column numbers for top
	for (int row = 0; row < blobCol; row++)
		cout << row % 10;
	cout << endl << " +";
	// "-" figure for top
	for (int col = 0; col < blobCol; col++)
		cout << "-";
	cout << "+" << endl;
}
void matrixDownFigure(int blobRow, int blobCol)
{
	cout << " +";
	for (int i = 0; i < blobCol; i++)
		cout << "-";
	cout << "+" << endl << "  ";
	for (int i = 0; i < blobCol; i++)
		cout << i % 10;
	cout << endl;
}
int blobCount(char** blobArray, int blobRow, int blobCol, int r, int c)
{
	if (r < 0 || r >= blobRow)
	{
		return 0;
	}
	if (c < 0 || c >= blobCol)
	{
		return 0;
	}
	if (blobArray[r][c] == ' ')
	{
		return 0;	// empty 
	}
	else
	{
		//Search 4 neighbour
		blobArray[r][c] = ' ';
		coMRow = coMRow + r;
		coMCol = coMCol + c;
		return 1
			+ blobCount(blobArray, blobRow, blobCol, r - 1, c)
			+ blobCount(blobArray, blobRow, blobCol, r, c - 1)
			+ blobCount(blobArray, blobRow, blobCol, r, c + 1)
			+ blobCount(blobArray, blobRow, blobCol, r + 1, c);
	}
}
