#include "PrefixTree.h"

PrefixTree::PrefixTree()
{
	root = new PFTNode ();
}

PrefixTree::~PrefixTree()
{
	delete root;	
}

void PrefixTree::insert(string word)
{
	PFTNode* next = root;
	for (int i=0; i < word.length(); ++i){
		next = next->getChild(word[i]);
	}
	next->isWord = true;
}

bool PrefixTree::lookup(string word)
{
	PFTNode* next = root;
	for (int i=0; i < word.length(); ++i){
		if (next->hasChild(word[i])){
			next = next->getChild(word[i]);
		}
		else{
			return false;
		}
	}
	return next->isWord;
}

void PrefixTree::getWordsFromClue 
	(string clue, vector <string>& results, bool* usable)
{
	string partial("");
	canUse = usable;
	getWordsFromClue (root, results, partial, clue);
}

void PrefixTree::getWordsFromClue 
	(PFTNode* node, vector <string>& results, string partial, string remainder)
{
	if (node->isWord && (remainder.length() == 0) ){
		//cout << "Adding " << partial << " to results\n";
		results.push_back (partial);
	}

	if (remainder.length() >= 1){
		// on a try all character, check all the branches, do not
		// branch on a letter that was predefined in the clue
		if (remainder[0] == '_'){
			remainder.erase (0, 1);
			for (char c='A'; c <= 'Z'; ++c){
				if ( node->hasChild(c) && canUse[c-'A'] ){
					string temp = partial+c;
					getWordsFromClue 
					(node->getChild(c), results, temp, remainder);
				}
			}
		}
		// otherwise a letter has been specified for the current position
		else if ( node->hasChild(remainder[0]) ) {
			char c = remainder[0];
			partial += c;
			remainder.erase(0, 1);
			getWordsFromClue
			(node->getChild(c), results, partial, remainder);
		}
	}
}