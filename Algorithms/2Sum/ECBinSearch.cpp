// Your first C++ program is here...
#include "ECBinSearch.h"
int ECBinarySearch(const int listNumbers[], int size, int value)
{
  // input list of numbers comes as listNumbers vector
  // You need to implement binary search of "value" over this list; 
  // return the position (i.e., array index) of the vector that matches "value"; 
  // or return -1 if not found.
  int start = 0;
  int end = size;
  int median;
  int current;
  while(start < end){
	median = (start + end) / 2;
	current = listNumbers[median];
	if(current == value){
		return median;
	}
	else if(current < value){
		start = median + 1;
	}
	else{
		end = median;
	}
  }
  return -1; 
}
/*
#include <iostream>

int main(){
	using namespace std;
	int arr[] = {1,2,3,4,5};
	int size = 5;
	int value = 5;
	cout << "Array: ";
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Value: " << value << endl;
	cout << "Returns: " << ECBinarySearch(arr, size, value) << endl;
	return 0;
}*/
