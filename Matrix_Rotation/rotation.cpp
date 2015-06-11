#include <iostream>
using namespace std;

void printArray( int* array, int rSize, int cSize )
{
    for( int i = 0; i < rSize; i++ )
    {
        for( int j = 0; j < cSize; j++ )
        {
            cout << *((array + i*cSize ) + j);
            
            if( j < rSize-1 )
            {
                cout << ", ";
            }
        }    
        cout << endl;
    }
}

void rotate( int arr[][5], int rSize, int cSize )
{
    //FOR EACH LAYER
    for( int j = 0; j < rSize/2; j++)
    {
        int minI = j;    
        int maxI = cSize-1 - j; // REMEMBER TO minus 1
        
        for( int i = minI; i < maxI; i++ )
        {
            //THINKING OF THIS OFFSET IS THE MAIN TRICK
            int offset = i - minI;
            
            //IF DONE SMARTLY - only one temp is needed
            int temp = arr[minI][i];
            
            arr[minI][i] = arr[maxI-offset][minI];
            
            arr[maxI-offset][minI] = arr[maxI][maxI-offset];
            
            arr[maxI][maxI - offset] = arr[i][maxI];
            
            arr[i][maxI] = temp;   
        }
    }

}

/*
void printArray( int* array, int size)
{
    
    for( int i=0; i< size; i++ )
    {
        cout << array[i] << ", ";
    }
}
*/

int main()
{
    int array[5][5] = {
                        { 00, 01, 02, 03, 04},
                        { 10, 11, 12, 13, 14},
                        { 20, 21, 22, 23, 24},
                        { 30, 31, 32, 33, 34},
                        { 40, 41, 42, 43, 44},
                      };
    printArray( (int*)array, 5, 5 );
    
    cout << endl << endl;
    
    rotate( array, 5, 5 );
    printArray( (int*)array, 5, 5 );
}
