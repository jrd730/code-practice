#include <iostream>
#include <string>
using namespace std;

bool ispalindrome (const string& s){
  int half = s.length()/2;
  for (int i = 0; i < half; ++i){
    if (s[i] != s[s.length()-1]){
      return false;
    }
  }return true;
}

bool isalmostpalindrome (const string& s, char matchany='*'){
  int half = s.length()/2;
  for (int i = 0; i < half; ++i){
    if (s[i] != s[s.length()-i-1]){
      if (s[i] == matchany || s[s.length()-i-1] == matchany)
        continue;
      else 
        return false;
    }
  }return true;
}

int palindromicdist (const string& s){
  if (ispalindrome(s)) return 0;
  for (int j=1; j < s.length(); ++j){
    for (int i=0; i < s.length(); ++i){
      string tmp = s;
      tmp.insert (i, j, '*');
      cout << "testing: " << tmp << endl;
      if (isalmostpalindrome(tmp)) return j;
    }
    string tmp = s;
    tmp.insert (tmp.end(), j, '*');
    cout << "testing: " << tmp << endl;
    if (isalmostpalindrome(tmp)) return j;
  }
  return s.length()-1;
}

int main (int argc, char** argv){
  int N;
  cin >> N;
  for (; N; --N){
    string s; 
    cin >> s;
    cout << palindromicdist (s) << endl;
  }
  return 0;
}