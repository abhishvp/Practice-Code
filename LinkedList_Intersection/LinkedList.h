#include <iostream>

class LinkedList {

public:
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

public:
	LinkedList();
	~LinkedList();

	bool detectAndRemoveLoop();

	void printList();
	void add(int val);
	//Node* remove(int val);

    int findIntersectionNode(Node*head1, Node* head2);
	
	//special funtion just for testing
	void pointEndNodeTo(Node* nodeP);
	Node* getNthNode(int n);
	Node* getHead();


private:
		Node* head;

};