#include <stdio.h>
#include <vector>
#include "WordFreq.h"

using namespace std;

extern vector<WordFreq> GetMostFrequentKWords(string filename, int k);

int main() {
	vector<WordFreq> result = GetMostFrequentKWords("1.txt", 7);

	printf("+----------------------+---------+\n");
	printf("|          WORD        |   FREQ  |\n");
	printf("+----------------------+---------+\n");

	for (uint32_t i = 0; i < result.size(); i++) {
		printf("|%22s|%9d|\n", result[i].word.c_str(), result[i].freq);
	} // end-for
	printf("+----------------------+---------+\n");
} //end-main
