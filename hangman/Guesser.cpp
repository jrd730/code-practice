#include "Guesser.h"

Guesser::Guesser ()
{
	fill(letterCounts, letterCounts+26, 0);
	loadFile("OSPD4.txt");
}

Guesser::~Guesser ()
{

}

void Guesser::run ()
{
	cout << "Total letter counts:\n";
	for (int i=0; i < 26 ; ++i){
		cout << (char)(i+'A') << " : " << letterCounts[i] << endl;
	}
	string clue;
	do{
		cout << "\nEnter a clue (use '_' to denote an unknown letter): ";
		clue = "";
		getline(cin, clue);	
		bool canUse[26];
		fill(canUse, canUse+26, true);
		
		// Letters that are already defined in the clue must be set 
		// to unusable on a try all character
		for (unsigned i = 0; i < clue.length(); ++i){
			clue[i] = toupper(clue[i]);
			if (isalpha(clue[i])){
				canUse[clue[i]-'A'] = false;
			}
		}

		vector <string> results;
		prefixtree.getWordsFromClue (clue, results, canUse);
		
		if (results.size () > 0){
			cout << "Found " << results.size() << " words\n";
			for (unsigned i=0; i < results.size(); ++i){
				if(results[i].length() == clue.length())
					cout << results[i] << "\t";
			}cout << "\n";
		}

		else{
			cout << "No words matching the clue were found\n";
		}
	}while (clue != "quit");
} 

char Guesser::makeGuess (string clue)
{

}

void Guesser::loadFile (string fileName)
{
  ifstream fin;
  fin.open (fileName.c_str());
  if (!fin.fail()){
    char nextChar;
    bool add = true;
    string newWord("");
    while (fin.good()){
      nextChar = fin.get();
      if (nextChar != fin.eof()){
        if (nextChar == ' '){
          add = false;
          prefixtree.insert(newWord);
          //cout << newWord << endl;
        }
        else if (nextChar == '\n'){
          newWord = ("");
          add = true;
        }
        else if (add){
          newWord+=nextChar;
          //letterCounts[nextChar-'A']++;
        }
      }
    }
  }
}
