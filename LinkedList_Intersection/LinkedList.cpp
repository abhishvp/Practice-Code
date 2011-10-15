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
		Node *ptrA = slowPtr->next, *ptrB = slowPtr->next;
		int k = 0;

		while( ptrA != slowPtr )
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

int LinkedList::findIntersectionNode(Node*head1, Node* head2)
{
	Node* nodePtr = head1;
	int count1 = 0; 
	int count2 = 0;
	int countDiff = 0;

	while( nodePtr )
	{
		nodePtr = nodePtr->next;
		count1++;
	}

	nodePtr = head2;
	while( nodePtr )
	{
		nodePtr = nodePtr->next;
		count2++;
	}

	Node *ptrA, *ptrB;
	if( count1 > count2 )
	{
		ptrA = head1;
		ptrB = head2;
		countDiff = count1 - count2;
	}
	else {
		ptrA = head2;
		ptrB = head1;
		countDiff = count2 - count1;
	}

	for(int i=0; i < countDiff-1 && ptrA; i++)
	{
		ptrA = ptrA->next;		
	}

	while(ptrA != ptrB && ptrA && ptrB )
	{
		ptrA = ptrA->next;
		ptrB = ptrB->next;
	}
	
	if(ptrA)
		return ptrA->val;
}

void LinkedList::pointEndNodeTo(Node* nodeP)
{
	Node* nodePtr = head;
	Node* prev = NULL;

	while(nodePtr)
	{
		prev = nodePtr;
		nodePtr = nodePtr->next;
	}

	if(prev)
	{
		prev->next = nodeP;
	}
}

LinkedList::Node* LinkedList::getNthNode(int n)
{
	Node* nodePtr = head;
	n--;
	while(n)
	{
		nodePtr = nodePtr->next;
		n--;
	}

	return nodePtr;
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

LinkedList::Node* LinkedList::getHead(){
	return head;
}
