#include <iostream> 
#include <stdlib.h>

#define ARRAY_SIZE 15
using namespace std;

void fill_array(int *my_array, int size);
void print_array(int *my_array, int size);
void print_array(int *my_array, int size, int currPos);


//compare and sort in pairs. O(n^2)
void bubbleSort(int *my_array, int size) {
	for(int i=0; i<size; ++i){
		for(int j=0; j<size-1; ++j){
			print_array(my_array, ARRAY_SIZE, j); sleep(2);			
			if(*(my_array+j+1) < *(my_array+j)){
				//swap
				int temp = 	*(my_array+j);
				*(my_array+j) = *(my_array+j+1);
				*(my_array+j+1) = temp;
			}
		}
	}	
}

//Find smallest, then put it in the 1st position. O(n^2)
void selectionSort(int *my_array, int size) {
	int minValIndex;
	for(int i=0; i<size; ++i){
		minValIndex = i;
		for(int j=i+1; j<size; ++j){
			if (*(my_array+j) < *(my_array+minValIndex)){
				minValIndex = j;			
			}
		}

		print_array(my_array, ARRAY_SIZE, minValIndex); sleep(2);
		//Swap
		if(i != minValIndex) {
			int temp = 	*(my_array+i);
			*(my_array+i) = *(my_array+minValIndex);
			*(my_array+minValIndex) = temp;
		}
	}
}


void insertionSort(int *my_array, int size) {
	for (int i=1, j; i < size; ++i) {
		int tmp = my_array[i];
		for(j = i; j > 0 && tmp < my_array[j-1]; --j) { 
			my_array[j] = my_array[j-1];
		}
		my_array[j] = tmp;
	}
}

void quickSort(int *my_array, int left, int right) {

	int i = left;
	int j = right;
	int pivotVal = *(my_array + ((left+right)/2));
	
	while(i <= j) {
		while (*(my_array+i) < pivotVal) { 
			i++;	
		}	
		
		while (*(my_array+j) > pivotVal) {
				j--;	
		}

		if (i <= j) {
			int temp = *(my_array+i);
			*(my_array+i) = *(my_array+j);
			*(my_array+j) = temp;
			i++; j--;
		}

		if (left < j) {
			quickSort(my_array, left, j);
		}
		
		if (right > i) {
			quickSort(my_array, i, right);	
		}
	}
}


int main(){
	int my_array[ARRAY_SIZE];
	fill_array(my_array, ARRAY_SIZE);
	print_array(my_array, ARRAY_SIZE);
	selectionSort(my_array, ARRAY_SIZE);
	print_array(my_array, ARRAY_SIZE);
	return 0;
}



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



void print_array(int *my_array, int size, int currPos ) {
	print_array(my_array, size);
	
	for (int i=0; i < currPos; ++i) {
		cout<<"   ";
	}
	cout<<" ^";
	cout<<"\n";
}

void print_array(int *my_array, int size) {

	cout<<"\n|";
    for (int i=0; i < size; ++i) {
    	cout<<my_array[i]<< "|";
  	}
    cout<<"\n";
}

