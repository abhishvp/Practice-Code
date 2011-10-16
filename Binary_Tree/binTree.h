#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>

class BinTree;

class Node {
    int key_value;
    Node *left;
    Node *right;

public:
	Node(){};
	Node(int keyval, Node *l, Node *r){
		key_value = keyval;
		left = l;
		right = r;
	}

    int getKeyVal(){return key_value;}
	friend class BinTree;
};


class BinTree {

public:
    BinTree();
    ~BinTree();

    void destroy_tree(Node *leaf);
    void insert(int key, Node *leaf);
    Node* search(int key, Node *leaf);
    Node* searchNonRecursively(int key, Node *leaf);
    
	void preorderTraversal(Node* node);
    void preorderTraversal();
    void insert(int key);
    Node* search(int key);
    void destroy_tree();

private:
    Node *root;
	
};

#endif
