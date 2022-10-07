#include "StringOps.h"
#include <algorithm>

using namespace std;


// concatnate strings: concatnate strConcating into strConcatTo
void ConcatenateStrings( std::vector<char> &strConcatTo, const std::vector<char> &strConcating  )
{
    for(char c : strConcating){
        strConcatTo.push_back(c);
    }
}

// find all distinct k-length substrings in strInput and store in the set setUniqueSubstrings
void GetDistinctSubstrings( const std::vector<char> & strInput, int k, std::set< std::vector<char> > &setUniqueSubstrings  )
{
  setUniqueSubstrings.clear();
  if(k > (int)strInput.size() || k <= 0){
    return;
  }
  for(unsigned int i = 0; i < strInput.size(); i++){
    vector<char> buf;
    int count = 0;
    unsigned int index = i;
    while(count < k && index < strInput.size()){
        buf.push_back(strInput[index]);
        index++;
        count++;
    }
    if(buf.size() == (unsigned int)k){
        setUniqueSubstrings.insert(buf);
    }
  }
  
}

// determine if strInput contains strPattern as a substring
bool IsSubString( const std::vector<char> &strInput, const std::vector<char> &strPattern )   
{
    for(unsigned int i = 0; i < strInput.size(); i++){
        for(unsigned int j = 0; j < strPattern.size(); j++){
            if(j + i >= strInput.size()){
                return false;
            }
            if(strInput[i+j] != strPattern[j]){
                break;
            }
            if(j == strPattern.size() - 1){
                return true;
            }
        }
    }
    return false;
}

// find duplicate (i.e. appearing at least twice) characters in string
void GetDuplicateChars(const std::vector<char> &strInput, std::set<char> &setDupChars)
{
    if(strInput.size() == 0) return;
    vector<unsigned int> asciiVals;
    for(char c : strInput){
        asciiVals.push_back((int)c);
    }
    auto start = asciiVals.begin();
    auto end = asciiVals.end();
    sort(start, end);
    for(unsigned int i = 0; i < asciiVals.size() - 1; i++){
        if(asciiVals[i] == asciiVals[i+1]){
            setDupChars.insert((char)asciiVals[i]);
        }
    }
}
/*
#include <iostream>
#include <cassert>
int main(){
    using namespace std;
    set<vector<char>> b;
    vector<char> a = {'a','b','c','d','e','f','g','h', 'i'};
    GetDistinctSubstrings(a, 2, b);
    cout << "Distinct Substring test" << endl;
    for(vector<char> i : b){
        for(char c : i){
            cout << c << ' ';
        }
        cout << endl;
    }

    vector<char> v1 = {'a','b','c'};
    vector<char> v2 = {'d','e','f'};
    vector<char> v3 = {'h','e','l','l','o','i','t','i','s','m','e'};
    vector<char> v4 = {'i','t'};
    vector<char> v6 = {'x','y','z'};
    vector<char> v8 = {'x','y','x','z'};
    vector<char> v7;
    cout << "Concatenate Strings" << endl;
    ConcatenateStrings(v1, v2);
    for(char i : v1){
        cout << i << ' ';
    }
    cout << endl;

    assert(!IsSubString(v1,v6));
    assert(IsSubString(v3, v4));
    assert(!IsSubString(v6,v7));
    assert(!IsSubString(v8,v6));

    string str1 = "xyh";
    string str2 = "abxyzc";
    cout << endl << endl;
    int count = str2.find(str1, 0);
    cout << count << endl;

    cout << "GetDiplicateChars" << endl;
    vector<char> vectorWithDups = {'a','b','c','c','a','d','e','f','d','b'};
    set<char> s2;
    GetDuplicateChars(vectorWithDups, s2);
    for(char c : s2){
        cout << c << ' ';
    }
    cout << endl;

    cout << "GetDistinctSubstrings" << endl;
    vector<char> v = {'l', 'g', 'i', 'n', 'r', 's', 't'};
    set<vector<char>> s3 = {{'x','y','z'}};
    GetDistinctSubstrings(v, 1, s3);
    for(vector<char> _v : s3){
        for(char c : _v){
            cout << c;
        }
        cout << ' ';
    }
    cout << endl;
    cout << s3.size() << endl;

    return 0;
}*/