#ifndef _WORDFREQ_H_
#define _WORDFREQ_H_

#include <string>
using namespace std;

struct WordFreq {
	string word;
	int freq;

	WordFreq(string word) : word(word) { freq = 0; }
};


#endif