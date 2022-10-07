#include "ECLongestPrefix.h" 
#include <iostream>
#include <string>

using namespace std;

// Implement the longest prefix function here...
std::string ECLongestPrefix(int numStrings, const std::string arrayStrings[])
{
	// YW: this only serves as a starter code, which just print out the given array of strings
	// Replace with your own code here...
	if(numStrings == 0){
		return "";
	}
	unsigned int minStr = arrayStrings[0].size();
	for(int i = 0; i < numStrings; i++){
		unsigned int size = arrayStrings[i].size();
		if(size < minStr){
			minStr = size;
		}
	}
	string prefix = "";
	for(unsigned int i = 0; i < minStr; i++){
		bool charEquivalent = true;
		for(int j = 0; j < numStrings - 1; j++){
			if(arrayStrings[j][i] != arrayStrings[j+1][i]){
				charEquivalent = false;
				break;
			}
		}
		if(charEquivalent){
			prefix += arrayStrings[0][i];
		}
		else{
			break;
		}
	}
	return prefix;
}
/*
int main(){
	string arg[4];
	arg[0] = "pie";
	arg[1] = "daf";
	arg[2] = "ase";
	arg[3] = "daf";
	cout << ECLongestPrefix(4, arg) << endl;
	return 0;
}*/
