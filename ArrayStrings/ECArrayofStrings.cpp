#include <iostream>
#include "ECArrayofStrings.h" 

using namespace std;

ECArrayofStrings :: ECArrayofStrings()
{
}

ECArrayofStrings :: ~ECArrayofStrings() // does the destructor do anything?
{
  // your code goes here
}

void ECArrayofStrings :: AddString( const string &strToAdd )
{
  setofstrings.push_back(strToAdd);
}

int ECArrayofStrings :: GetNumofStrings() const
{
  // your code goes here
  return setofstrings.size();
}

int ECArrayofStrings :: GetMaxLen() const
{
  if(GetNumofStrings() == 0){
    return 0;
  }
  unsigned int max_len = setofstrings[0].size();
  for(string s : setofstrings){
    if(s.size() > max_len){
      max_len = s.size();
    }
  }
  return max_len;
}

string ECArrayofStrings :: GetLongestCommonPrefix() const
{
  string prefix = "";
  LongestCommonPrefixHelper(0, GetNumofStrings(), prefix);
  return prefix;
}

void ECArrayofStrings::LongestCommonPrefixHelper(unsigned int start, unsigned int end, string &res) const{
  if(end - start <= 1){
    res = setofstrings[start];
    return;
  }
  else{
    unsigned int median = (start + end)/2;
    string res1;
    string res2;
    LongestCommonPrefixHelper(start, median, res1);
    LongestCommonPrefixHelper(median, end, res2);
    res = GetLongestCommonPrefixofTwo(res1, res2);
    return;
  }
}

void ECArrayofStrings:: Dump() const
{
  for(string s : setofstrings){
    cout << s << endl;
  }
}

string ECArrayofStrings :: GetLongestCommonPrefixofTwo(const string &str1, const string &str2) const
{
  string prefix = "";
  unsigned int i = 0;
  while(i < str1.size() && i < str2.size()){
    if(str1[i] == str2[i]){
      prefix += str1[i];
    }
    else{
      break;
    }
    i++;
  }
  return prefix;
}

std::string ECArrayofStrings::Concatnate() const{
  string res = "";
  for(string s : setofstrings){
    res += s;
  }
  return res;
}