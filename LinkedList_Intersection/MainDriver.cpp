#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList myList1;
	LinkedList myList2;

	myList1.add(5);
	myList1.add(4);
	myList1.add(3);
	myList1.add(2);
	myList1.add(1);

	myList2.add(20);
	myList2.add(10);

	myList2.pointEndNodeTo(myList1.getNthNode(5));


	cout << myList1.findIntersectionNode(myList1.getHead(), myList2.getHead());

	getchar();
}