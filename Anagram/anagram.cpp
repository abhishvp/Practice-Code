#include <iostream>
using namespace std;


bool isAnagram( char* string1, char* string2 ){
	if( !string1 && !string2 )
		return false;
	
	int lenS1 = strlen( string1 );
	int lenS2 = strlen( string2 );
	if( lenS1 != lenS2 )
		return false;

	int checkArray[256], i=256;

	while( --i >= 0 ){
		checkArray[i] = 0; 	
	}

	for( i=0; i<lenS1; i++ ){
		int v = (int) string1[i];
		checkArray[v]++;
	}

	for( i=0; i<lenS2; i++ ){
		int v = (int) string2[i];
		if( checkArray[v] > 0 ){
			checkArray[v]--;
		}
		else{
			return false;
		}
	}

	return true;
}


int main(){

char a[] = "";
char b[] = "";

if( isAnagram( a, b ) )
	cout << "Strings are anagrams";
else
	cout << "Strings are not anagrams";

getchar();

}