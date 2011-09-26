#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
	:head(NULL)
{

}

LinkedList::~LinkedList()
{
	Node* tmp;
	while(head)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

void LinkedList::add(int val)
{
	Node* tmp = head;
	head = new Node(val);
	head->next = tmp;
}

bool LinkedList::detectAndRemoveLoop()
{
	Node* slowPtr = head;
	Node* fastPtr = head;
	bool isLoop = false;
	
	while( slowPtr && fastPtr && fastPtr->next )
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;

		if( slowPtr == fastPtr )
		{
			isLoop = true;
			break;
		}		
	}

	//Remove Loop
	if(isLoop)
	{
		Node *ptrA, *ptrB = slowPtr->next;
		int k = 0;

		while( ptrA != slowPtr)
		{
			k++;
			ptrA = ptrA->next;
		}

		ptrA = ptrB = head;

		while(k > 0){
			ptrB = ptrB->next;
			k--;
		}
	
		while(ptrA != ptrB)
		{
			ptrA = ptrA->next;
			ptrB = ptrB->next;
		}

		ptrB = ptrB->next;
		while(ptrB->next != ptrA)
		{
			ptrB = ptrB->next;
		}

		ptrB->next = NULL;
	}

	return isLoop;

}

void LinkedList::printList()
{
	Node* currNode = head;

	while(currNode)
	{
		cout << currNode->val << "->";
		currNode = currNode->next;
	}
	cout << "NULL \n";
}


