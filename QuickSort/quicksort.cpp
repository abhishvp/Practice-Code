#include <iostream>

using namespace std;


void swap( int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition( int arr[], int sI, int eI )
{
    int pivotI = eI;
    int pivVal = arr[pivotI];
    int wallIndex = 0;
    
    for(int i = sI; i < pivotI-1; i++ )
    {
        if( arr[i] <= pivVal )
        {
            swap( &arr[wallIndex], &arr[i] );
            wallIndex++;
        }
    }
    
    swap( &arr[wallIndex], &arr[pivotI] );
    pivotI = wallIndex;
    
    return pivotI;
}



void quickSort( int arr[], int sI, int eI )
{
    int pivotI = partition( arr, sI, eI );
    
    if( pivotI-1 > sI )
        quickSort( arr, sI, pivotI-1 );
    if( pivotI+1 < eI)
        quickSort( arr, sI, pivotI+1 );
}





int main()
{
    int a[10] = {1, 2, 3, 9, 8, 7, 6, 5, 0, 4 };
    
    //int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    //int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    
    
    quickSort( a, 0, 9);
    
    for( int i = 0; i<10; i++)
    {
        cout << i << ", ";
    }

}
