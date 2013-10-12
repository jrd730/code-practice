#pragma once
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "PFTNode.h"
using namespace std;

class PrefixTree
{
public:
		
	PrefixTree ();
	~PrefixTree ();

	void insert (string word);
	bool lookup (string word);
	void remove (string word);
	
	void getWordsFromClue 
		(string clue, vector <string>& results, bool* usable);

private:

	void getWordsFromClue 
		(PFTNode* node, vector <string>& results, 
			string partial, string remainder);

	PFTNode* root;
	bool* canUse;
};