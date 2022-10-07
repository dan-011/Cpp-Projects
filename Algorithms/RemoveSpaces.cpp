// your code goes here
#include <iostream>
#include <string>

using namespace std;

string RemoveSpaces( const string &strIn)
{
    // your code goes here...
    string rv = "";
    for(char c : strIn){
	if((int)c != 32){
		rv += c;
	}
    }
    return rv;
}
