#include <iostream> 
#include <stdlib.h>
#include <string>

#define ARRAY_SIZE 15
using namespace std;


void fill_array(int *my_array, int size) {
//	srand ( time(NULL) );
	srand (1);
    for (int i=0; i < size; ++i) {
		int tmp;
		do{
			tmp = rand() % 100;
		} while(tmp < 10);
   		my_array[i] = tmp;
  	}
}

void print_array(int *my_array, int size) {

	cout<<"\n|";
    for (int i=0; i < size; ++i) {
    	cout<<my_array[i]<< "|";
  	}
    cout<<"\n";
}

void insertionSort(int *my_array, int size) {
	for(int i = 1, j; i < size; ++i){
		int tmpVal = *(my_array + i);
		for( j= i; j > 0 && tmpVal < *(my_array + j-1); --j) {
			*(my_array+j) = *(my_array+j-1);
		}
		*(my_array+j) = tmpVal;
	}
}

//Non Recursive;
int binarySearch(int *my_array, int size, int searchVal){
	int left =0, right = size-1;
	while(left<=right){
		int midIndex = (left + right)/2;
		if(*(my_array+midIndex) == searchVal){
			return midIndex;
		}
		else if(searchVal < *(my_array+midIndex)) { 
			right = midIndex-1;
		} else {
			left = midIndex+1;
		}
	}

	return -1;
}

//Recursive - just for fun;
int binarySearch(int *my_array, int left, int right, int searchVal){
		int midIndex = (left + right)/2;
		if(*(my_array+midIndex) == searchVal){
			return midIndex;
		}
		else if(searchVal < *(my_array+midIndex) && midIndex > left) { 
			return binarySearch(my_array, left, midIndex-1, searchVal);
		} else if(right > midIndex){
			return binarySearch(my_array, midIndex+1, right, searchVal);
		}
		return -1;
}



int main(){
	int my_array[ARRAY_SIZE];
	int sVal;
	fill_array(my_array, ARRAY_SIZE);
	insertionSort(my_array, ARRAY_SIZE);
	print_array(my_array, ARRAY_SIZE);
 	cout << "Enter SearchValue:";
	cin >> sVal;
	//cout << "Index of the item found = "<< binarySearch(my_array, ARRAY_SIZE, sVal)<< endl;
	cout << "Index of the item found recursively = "<< binarySearch(my_array, 0, ARRAY_SIZE-1, sVal)<< endl;
	return 0;
}
