/**
* @author: 152120171104 -->Ezgi Özdikyar
* @author: 152120181058 -->Mine ÇAKIR
* @date: 06.01.2021
*/
#include "WordFreq.h"
#include <vector>
#include<iostream>
#include<fstream>
#include"AVL.h"
using namespace std;
///-----------------------------------------------------------------
/// Process the given text file and return the most frequent "k" words
///
vector<WordFreq> GetMostFrequentKWords(string filename, int k)
{
	vector<WordFreq> result;
	fstream data;
	string temp;
	string word;
	AVL AVLwords;
	int counter2 = 0;
	data.open(filename, ios::in);
	if (!data.is_open())
	{
		cout << "File is not found!" << endl;
		exit(0);
	}
	while (!data.eof())
	{
		getline(data, temp);
		for (int i = 0; i < temp.size(); i++)
		{
			if (int(temp[i]) > 64 && int(temp[i]) < 91 || int(temp[i]) > 96 && int(temp[i]) < 123)
			{
				if (int(temp[i]) > 64 && int(temp[i]) < 91)
				{
					word += temp[i] + 32;
					continue;
				}
				word += temp[i];
			}
			else
			{
				if (word.size() >= 3)
					AVLwords.add(word);
				word = "\0";
			}
		}
		if (word.size() >= 3)
			AVLwords.add(word);
		word = "";
	}
	int t = AVLwords.getMaxFrequency();
	vector<vector<string>> words(t + 1);
	for (int i = 0; i < AVLwords.getCounter(); i++)
	{
		for (int j = 0;; j++)
		{
			if (AVLwords.min()->words.freq == j && AVLwords.min())
			{
				AVLNode* minimum = AVLwords.min();
				words[j].push_back(minimum->words.word);
				AVLwords.remove(minimum);
				break;
			}
		}
	}
	for (int i = t; i >= 0; i--)
	{
		for (int j = 0; j < words[i].size(); j++)
		{
			WordFreq frequentWord("");
			frequentWord.word = words[i][j];
			frequentWord.freq = i;
			result.push_back(frequentWord);
			counter2++;
			if (counter2 == k)
				break;
		}
		if (counter2 == k)
			break;
	}
	data.close();
	return result;
} //end-GetMostFrequentKWords

