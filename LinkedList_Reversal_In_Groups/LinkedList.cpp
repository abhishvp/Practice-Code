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

void LinkedList::reverse()
{
	Node* previous = NULL;
	Node* current = head;

	while(current)
	{
		Node* tmp = current->next;
		current->next = previous;
		previous = current;
		current = tmp;
	}

	head = previous;
}

void LinkedList::reverseInGroups(int groupSize)
{
	if(groupSize == 0)
		return;

	Node* previous = NULL;
	Node* current = head;

	bool firstTime = true;

	Node* endOfPrevBlockPtr = current;
	Node* endOfNextBlockPtr = NULL;

	while(current)
	{
		for(int i=0; i< groupSize && current != NULL; i++)
		{
			Node* tmp = current->next;
			current->next = previous;
			previous = current;
			current = tmp;
		}

		if(firstTime)
		{
			head = previous;
			firstTime = false;
		}
		else
		{
			endOfPrevBlockPtr->next = previous;
			endOfPrevBlockPtr = endOfNextBlockPtr;
		}

		if(current == NULL)
		{
			if( endOfNextBlockPtr != NULL )
			{
				endOfPrevBlockPtr->next = previous;
				endOfNextBlockPtr->next = NULL;
			}
			else
			{
				endOfPrevBlockPtr->next = NULL;
			}
		}
		else
		{
			endOfNextBlockPtr = current;
			previous = NULL;	
		}
	}

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


