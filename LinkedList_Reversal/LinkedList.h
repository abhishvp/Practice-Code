#include <iostream>

class LinkedList {

public:
	LinkedList();
	~LinkedList();
	
	void reverse();
	void printList();
	void add(int val);
	//Node* remove(int val);


private:
	struct Node {
		int	val;
		Node* next;

		Node(int aVal)
		{
			val = aVal;
			next = NULL;
		}

		int getVal()
		{
			return val;
		}
	};


private:
		Node* head;

};