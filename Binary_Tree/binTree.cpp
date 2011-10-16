#include "binTree.h"

/*CONSTRUCTOR-DESTRUCTOR*/
BinTree::BinTree() {
    root=NULL;
}

BinTree::~BinTree() {
    destroy_tree();
}


void BinTree::destroy_tree(){
     destroy_tree(root);
}
void BinTree::destroy_tree(Node *leaf) {
    if(leaf!=NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf; 
    }
}





/*
INSERTION
*/

void BinTree::insert(int key){
    if(root!=NULL)
        insert(key, root);
    else{
        root = new Node;
        root->key_value = key;
        root->left=NULL;
        root->right=NULL;
    }
}

void BinTree::insert(int key, Node *leaf) {
    if(key < leaf->key_value){
        if(leaf->left!=NULL)
            insert(key, leaf->left);
        else{
            leaf->left = new Node();
            leaf->left->key_value =key;
            leaf->left->left=NULL; //Sets the left child of child Node to null
            leaf->left->right=NULL; //Sets the right child of child Node to null
        }
    }
    else if(key>=leaf->key_value){
        if(leaf->right!=NULL)
            insert(key, leaf->right);
        else{
            leaf->right=new Node;
            leaf->right->key_value=key;
            leaf->right->left=NULL; //Sets the left child of child Node to null
            leaf->right->right=NULL; //Sets the right child of child Node to null
        }
    }
}



/*
DELETION
*/


// Very imp... TO DO







/*
SEARCHING
*/
Node *BinTree::search(int key){
     return search(key, root);
}

Node *BinTree::search(int key, Node *leaf){
    if(leaf!=NULL){
        if(key==leaf->key_value)
            return leaf;
        if(key < leaf->key_value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else return NULL;
}

Node *BinTree::searchNonRecursively(int key, Node *leaf){
    while(leaf != NULL){
        if(key == leaf->key_value)
            return leaf;
        if(key < leaf->key_value)
            leaf = leaf->left;       
        else
            leaf = leaf->right;
    }
   
    return NULL;
}


/*
TRAVERSAL
*/
void BinTree::preorderTraversal(Node* node){
     if(node == NULL ){ return; }
     std::cout << node->key_value << " ";
     preorderTraversal(node->left);
     preorderTraversal(node->right);
}

void BinTree::preorderTraversal(){
	preorderTraversal(root);
}






