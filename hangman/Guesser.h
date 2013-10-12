#pragma once
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include "PrefixTree.h"
class Guesser
{
	public:
		Guesser ();
		~Guesser ();
		void run ();
		char makeGuess (string clue);
		void loadFile (string fileName);

	private:
		unsigned letterCounts[26];
		PrefixTree prefixtree;
		unsigned trysLeft;
};