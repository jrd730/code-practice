#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

const string digit [] = {"", "one ","two ","three ", "four ","five " ,"six ","seven ","eight ","nine "};
const string ten [] = {"","ten ","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
const string teen [] = {"","eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen " ,"nineteen "};
const string magnitude [] = {"", "thousand ","million ","billion "};

string chunkToWord (int num)
{
    stringstream  chunk("");
    if (num >= 100){
        chunk << digit[(num/100)] << "hundred ";
        num %= 100;
    }
    if (num > 10 && num < 20 ){
        chunk << teen[num%10];
    }
    else{
        chunk << ten[num/10] << digit[num%10];
    }
    return chunk.str();
}

string numToWord (int num)
{
    if (num > 0){
        stack <string> chunks;
        stringstream word ("");
        while (num){
            chunks.push (chunkToWord(num%1000));
            num /= 1000;
        }
        while (!chunks.empty()){
            if (chunks.top().size()>0){
                word << chunks.top() << magnitude [chunks.size()-1];
            }
            chunks.pop();
        }
        return word.str();
    }
    else return "zero";
}

int main(int argc, char** argv)
{
    int n;
    do {
        cout << "enter a positive integer: ";
        string input ("");
        cin >> input;
        n = atoi (input.c_str());
        cout << numToWord(n) << endl;
    }while (n != 0);
    return 0;
}
