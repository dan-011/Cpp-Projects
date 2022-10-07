//
//  RemoveDupPointers.cpp
//  
//
//  Created by Yufeng Wu on 1/18/21.
//
//

#include <string>
#include <vector>

using namespace std;

//
void RemoveDupPointers(vector<string *> &arrayPtrs)
{
    // arrayPtrs: STL vector of pointers to strings
    // remove pointers that are pointed to identical strings in the array
    // Your code goes here...
    unsigned int i = 0;
    unsigned int j = 0;
    vector<string*>::iterator k = arrayPtrs.begin();
    while(i < arrayPtrs.size()){
	    j = i+1;
	    while(j < arrayPtrs.size()){
		    if(*arrayPtrs[i] == *arrayPtrs[j]){
			    arrayPtrs.erase(k+j);
		    }
		    else{
			    j++;
		    }
	    }
	    i++;
    }
}
/*
// Testing
#include <iostream>

int main(){
	string s1 = "abc";
	string s2 = "bcd";
	string s3 = "abc";
	string s4 = "def";
	string s5 = "ijh";
	vector<string*> arrayPtrs = {&s1, &s2, &s5, &s4};
	RemoveDupPointers(arrayPtrs);
	for(string* ptr : arrayPtrs){
		cout << *ptr << endl;
	}
	return 0;
}*/