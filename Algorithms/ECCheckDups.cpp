// Check whether the given integer list has duplicates or not
// Return true if there is duplicate, false otherwise
#include <vector>
#include <algorithm>

bool ECCheckDuplicates(const std::vector<int> &listNumbers)
{
  using namespace std;
  if(listNumbers.size() == 0){
    return false;
  }
  vector<int> buffer;
  for(int n : listNumbers){
    buffer.push_back(n);
  }
  auto begin = buffer.begin();
  auto end = buffer.end();
  sort(begin, end);
  for(unsigned int i = 0; i < listNumbers.size() - 1; i++){
    if(buffer[i] == buffer[i+1]){
      return true;
    }
  }
  return false;
}
/*
// Testing
#include <iostream>
#include <cassert>
int main(){
  using namespace std;
  vector<int> ln1 = {1,2,1,3,3,4,3,2,4,2};
  vector<int> ln2 = {3, 8, 2, 9, 6, 1, 5, 7, 4};

  assert(ECCheckDuplicates(ln1));
  assert(!ECCheckDuplicates(ln2));

  vector<int> ln3 = {};

  assert(!ECCheckDuplicates(ln3));

  return 0;
}*/