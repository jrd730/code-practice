#pragma once
#include <cstdlib>

class PFTNode
{
	public:
		
		PFTNode (){
			for (int i=0; i < 26; ++i){
				children[i] = NULL;
			}
			isWord = false;
		}

		~PFTNode (){
			for (int i=0; i < 26; ++i){
				delete children[i];
				children[i] = NULL;
			}
		}

		PFTNode* getChild (char c){
			if ( (c >= 'A') && (c <= 'Z') ){
				if (!children[c-'A']){
					children[c-'A'] = new PFTNode ();
				}
				return children[c-'A'];
			}
			return NULL;
		}

		bool hasChild (char c){
			if ( (c >= 'A') && (c <= 'Z') ){
				if (children[c-'A']){
					return true;
				}
			}
			return false;
		}

		bool isWord;

	private:	

		PFTNode* children[26];
};
