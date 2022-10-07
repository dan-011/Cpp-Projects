// Given a sorted list, find the smallest number of covering intervals
// For example, if A={1,2,3,5,6,9}, there are three covering intervals [1,3], [5,6] and [9]

//int ECSmallestCoverIntervals(const int[] arrInts, int szArr)
int ECSmallestCoverIntervals(const int* arrInts, int szArr)
{
	// arrInts: sorted array of integers; szArr: number of integers in the array
	// Your code here
	if(szArr == 0){
		return 0;
	}
	int i = arrInts[0];
	int j = 0;
	int count = 0;

	while(j < szArr){
		if(i != arrInts[j]){
			count++;
			while(i != arrInts[j]){
				i++;
			}
		}
		else{
			i++;
			j++;
		}
	}
	count++;
	return count;
}
/*
#include <iostream>
#include <cassert>
int main(){
	int arr1[] = {0,1,2,4,5,7};
	int sz1 = 6;
	
	int arr2[] = {2,3,4,5,6};
	int sz2 = 5;

	int arr3[] = {10,11,12,15,20,21,25,26,27,29,30};
	int sz3 = 11;

	int arr4[] = {};
	int sz4 = 0;

	int arr5[] = {1};
	int sz5 = 1;

	assert(ECSmallestCoverIntervals(arr1, sz1) == 3);
	assert(ECSmallestCoverIntervals(arr2, sz2) == 1);
	assert(ECSmallestCoverIntervals(arr3, sz3) == 5);
	assert(ECSmallestCoverIntervals(arr4, sz4) == 0);
	assert(ECSmallestCoverIntervals(arr5, sz5) == 1);

	return 0;
}*/
