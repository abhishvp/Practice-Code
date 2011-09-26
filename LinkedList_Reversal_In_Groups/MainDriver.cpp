#include "LinkedList.h"

int main()
{
	LinkedList myList;

	myList.add(8);
	myList.add(7);
	myList.add(6);
	myList.add(5);
	myList.add(4);
	myList.add(3);
	myList.add(2);
	myList.add(1);
	
	myList.printList();
	myList.reverseInGroups(10);
	myList.printList();	

	getchar();
}