#include "BinaryHeap.h"

// Construct the binary heap.
BinaryHeap::BinaryHeap( )
  : array( 11 ), theSize( 0 )
{
}

// Construct the binary heap.
// v is a vector containing the initial items.
BinaryHeap::BinaryHeap( const vector<int> &v )
  : array( v.size( ) + 1 ), theSize( v.size( ) )
{
    for( int i = 0; i < v.size( ); i++ ){
        array[ i + 1 ] = v[ i ];
	}
    buildHeap( );
}

// Insert item x into the priority queue, maintaining heap order.
// Duplicates are allowed.
void BinaryHeap::insert( const int x )
{
    array[ 0 ] = x;   // initialize sentinel
    if( theSize + 1 == array.size( ) )
        array.resize( array.size( ) * 2 + 1 );

      // Percolate up
    int hole = ++theSize;
    for( ; x < array[ hole / 2 ]; hole /= 2 )
        array[ hole ] = array[ hole / 2 ];
    array[ hole ] = x;
}

// Find the smallest item in the priority queue.
// Return the smallest item, or throw UnderflowException if empty.
const int & BinaryHeap::findMin( ) const
{
    if( isEmpty( ) )
        return -1;
    return array[ 1 ];
}

// Remove the smallest item from the priority queue.
// Throw UnderflowException if empty.
void BinaryHeap::deleteMin( )
{
    if( isEmpty( ) )
        return -1;

    array[ 1 ] = array[ theSize-- ];
    percolateDown( 1 );
}

// Remove the smallest item from the priority queue
// and place it in minItem. Throw UnderflowException if empty.
void BinaryHeap::deleteMin( int &minItem )
{
    minItem = findMin( );
    array[ 1 ] = array[ theSize-- ];
    percolateDown( 1 );
}

// Establish heap-order property from an arbitrary
// arrangement of items. Runs in linear time.
void BinaryHeap::buildHeap( )
{
    for( int i = theSize / 2; i > 0; i-- )
        percolateDown( i );
}

// Test if the priority queue is logically empty.
// Return true if empty, false otherwise.
bool BinaryHeap::isEmpty( ) const
{
    return theSize == 0;
}

// Make the priority queue logically empty.
void BinaryHeap::makeEmpty( )
{
    theSize = 0;
}

// Internal method to percolate down in the heap.
// hole is the index at which the percolate begins.
void BinaryHeap::percolateDown( int hole )
{
    int child;
    int tmp = array[ hole ];

    for( ; hole * 2 <= theSize; hole = child )
    {
        child = hole * 2;
        if( child != theSize && array[ child + 1 ] < array[ child ] ){
            child++;
		}
        if( array[ child ] < tmp ) {
            array[ hole ] = array[ child ];
		}
        else {
            break;
		}
    }
    array[ hole ] = tmp;
}


