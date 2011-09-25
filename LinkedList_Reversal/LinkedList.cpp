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


