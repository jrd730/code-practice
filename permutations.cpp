#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main ()
{
	cout << "\nPermutations of a string:\n";
	string s ("abcd");
	do{ 
		cout << s << endl;
	}while (next_permutation (s.begin(), s.end()));
	cout << "\n";

	cout << "Permutations of an array:\n";
	int arr[] = {1, 2, 3, 4};
	do{ 
		for (int i=0; i < 4; ++i) cout << arr[i]; cout << endl;
	}while (next_permutation (arr, arr+4));
	cout << "\n";

	return 0;
}