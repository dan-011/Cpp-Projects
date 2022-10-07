//
//  ValidPalindrome.cpp
//  
//
//  Created by Yufeng Wu on 1/18/21.
//
//

#include <iostream>
#include <cstdio>

using namespace std;

// Function to test if the input string is a valid palindrome
// Note: only consider alphanumeric symbols and ignore cases
bool IsValidPalindrome(const string &strInput)
{
    // your code go here ...
    if(strInput.size() == 0) return true;
    unsigned int i = 0;
    unsigned int j = strInput.size() - 1;
    while(i < j){
	    char c1 = (char)tolower(strInput[i]);
	    char c2 = (char)tolower(strInput[j]);
	    if(!isalnum(c1) || !isalnum(c2)){
		    if(!isalnum(c1)){
			    i++;
		    }
		    if(!isalnum(c2)){
			    j--;
		    }
		    continue;
	    }
	    if(c1 != c2){
		    return false;
	    }
	    i++;
	    j--;
    }
    return true;
}
/*
int main(){
	cout << (IsValidPalindrome("...............ab;;;cdd.cx??a!") ? "true" : "false") << endl;
	return 0;
}*/
