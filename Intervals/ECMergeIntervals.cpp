// Given a sorted list, find the smallest number of covering intervals
// For example, if A={1,2,3,5,6,9}, there are three covering intervals [1,3], [5,6] and [9]
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void MergeInterval(const std::vector<std::pair<int,int>> &v1, const std::vector<std::pair<int,int>> &v2, std::vector<std::pair<int,int>> &res);

void ECMergeIntervalsHelper(const std::vector<std::pair<int,int> > &listIntervals, unsigned int start, unsigned int end, std::vector<std::pair<int,int> > &resIntervals){
  if(end - start == 0){
    return;
  }
  else if(end - start == 1){
    resIntervals.push_back(listIntervals[start]);
    return;
  }
  else{
    vector<pair<int, int>> v1;
    vector<pair<int, int>> v2;
    unsigned int median = (start + end)/2;
    ECMergeIntervalsHelper(listIntervals, start, median, v1);
    ECMergeIntervalsHelper(listIntervals, median, end, v2);
    MergeInterval(v1, v2, resIntervals);
  }
}

void MergeInterval(const std::vector<std::pair<int,int>> &v1, const std::vector<std::pair<int,int>> &v2, std::vector<std::pair<int,int>> &res){
  if(v2.size() == 0 || v1.size() == 0){
    if(v1.size() == 0){
      for(pair<int,int> p : v2){
        res.push_back(p);
      }
    }
    else{
      for(pair<int,int> p : v1){
        res.push_back(p);
      }
    }
    return;
  }
  for(unsigned int i = 0; i < v1.size()-1; i++){
    res.push_back(v1[i]);
  }
  pair<int,int> comp = v1[v1.size()-1];
  pair<int,int> newPair;
  unsigned int lastIndex;
  bool compWritten = false;
  for(unsigned int i = 0; i < v2.size(); i++){
    pair<int,int> current = v2[i];
    if(comp.second >= current.first && comp.second < current.second){ // [1,3][2,4] == [1,4]
      newPair = {comp.first, current.second};
      res.push_back(newPair);
      lastIndex = i+1;
      compWritten = true;
      break;
      //comp = newPair;
    }
    else if(comp.second >= current.first && comp.second >= current.second){ // [1,4][2,4] == [1,4] or [1,5][2,4] == [1,5]
      lastIndex = i+1;
      continue;
    }
    else{
      res.push_back(comp);
      lastIndex = i+1;
      comp = current;
      break;
    }
  }
  if(!compWritten){
    res.push_back(comp);
  }
  for(unsigned int i = lastIndex; i < v2.size(); i++){
    res.push_back(v2[i]);
  }
}

void ECMergeIntervals(const std::vector<std::pair<int,int> > &listIntervals, std::vector<std::pair<int,int> > &listNonOverlapIntervals)
{
  // arrInts: sorted array of integers; szArr: number of integers in the array
  vector<pair<int, int>> lI;
  for(auto pair : listIntervals){
    lI.push_back(pair);
  }
  sort(lI.begin(), lI.end());
  ECMergeIntervalsHelper(lI, 0, lI.size(), listNonOverlapIntervals);

}

int main(){
  using namespace std;
  vector<pair<int, int>> a1 = {{1,3},{1,1},{1,1},{1,1},{4,6}};//{{1,3},{1,1},{1,1},{1,1},{2,6}};//,{8,10},{15,18}};*/
  //unsigned int i;
  //pair<int, int> p = binIntervalSearch(a1, 0, 1, i);
  //cout << "[" << p.first << ", " << p.second << "]" << endl;
  //cout << "Discovered: " << i << endl;

  vector<pair<int, int>> r1;
  ECMergeIntervals(a1, r1);
  for(pair<int, int> _pair : r1){
    cout << "[" << _pair.first << ", " << _pair.second << "]";
  }
  cout << endl;
  return 0;
}

//  [[1,3],[2,6],[8,10],[15,18]]