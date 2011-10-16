#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

class BinaryHeap
{
  public:
    BinaryHeap( );
    BinaryHeap( const vector<int> & v );

    bool isEmpty( ) const;
    const Comparable & findMin( ) const;

    void insert( const int x );
    void deleteMin( );
    void deleteMin( Comparable & minItem );
    void makeEmpty( );

  private:
    int theSize;  // Number of elements in heap
    vector<int> array;    // The heap array

    void buildHeap( );
    void percolateDown( int hole );
};

#endif
