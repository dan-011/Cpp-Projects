#include "EC2SUM.h"
#include <vector>
using namespace std;

//void EC2SUM( const int listNumbers[], int sizeNumbers, const int listTargets[], int szTargets, bool list2SUMRes[] )
void EC2SUM(const vector<int> &listNumbers, const vector<int> &listTargets, vector<bool> &list2SUMRes )
{
  int sizeNumbers = listNumbers.size();
  int szTargets = listTargets.size();
  // for each number x = listTargets[i], if there are two numbers 
  // in listNumbers that add up to x, then list2SUMres[i]=true 
  // otherwise, list2SUMRes[i]=false
  int lNum[sizeNumbers];
  for(int i = 0; i < sizeNumbers; i++){
	  lNum[i] = listNumbers[i];
  }
  for(int i = 0; i < szTargets; i++){
	  //list2SUMRes[i] = false;
	  list2SUMRes.push_back(false);
  }
  ECSort(lNum, sizeNumbers);
  int target;
  int searchVal;
  int searchResult;
  for(int i = 0; i < szTargets; i++){
	  target = listTargets[i];
	  for(int j = 0; j < sizeNumbers; j++){
		searchVal = target - listNumbers[j];
		searchResult = ECBinarySearch(lNum, sizeNumbers, searchVal);
		if(searchResult > -1 && searchResult != j){
			list2SUMRes[i] = true;
			break;
		}
	  }
  }
}/*
#include <cassert>
#include <iostream>
using namespace std;
int main(){
	int listNumbers[] = {3, 2, 4, 1, 5};
	int sizeNumbers = 5;
	int listTargets[] = {3, 6, 100, 10, 8, 7};
	int szTargets = 6;
	bool expected[] = {true, true, false, false, true, true};
	bool list2SUMRes[] = {false,false,false,false,false,false};

	EC2SUM(listNumbers, sizeNumbers, listTargets, szTargets, list2SUMRes);
	for(int i = 0; i < szTargets; i++){
		//cout << "comparing " << expected[i] << " and " << list2SUMRes[i] << endl;
		assert(expected[i] == list2SUMRes[i]);
	}
	return 0;
}*/
