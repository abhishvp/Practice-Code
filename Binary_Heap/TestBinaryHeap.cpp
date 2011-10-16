
#include "Except.h"
#include "BinaryHeap.h"

#ifdef USE_DOT_H
    #include <iostream.h>
#else
    #include <iostream>
    using namespace std;
#endif

// Test program
int main( )
{
    int numItems = 10000;
    BinaryHeap h;
    int i = 37;
    int x;


    for( i = 37; i != 0; i = ( i + 37 ) % numItems )
        h.insert( i );
    for( i = 1; i < numItems; i++ )
    {
        h.deleteMin( x );
        if( x != i )
            cout << "Oops! " << i << endl;
    }
    for( i = 37; i != 0; i = ( i + 37 ) % numItems )
        h.insert( i );
    h.insert( 0 );


    return 0;
}
