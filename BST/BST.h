#include<iostream>

using namespace std;

class Node{
	int data;
	Node* left;
	Node* right;
public:
	Node(int);
	int getData();
	void setData(int);
	Node* getLeft();
	void setLeft(Node*);
	Node* getRight();
	void setRight(Node*); 
};

class BST
{
	Node *root;
	void freeTree(Node*);
	int count(Node*);
	void recursivePreOrder(Node*);
	void recursiveInOrder(Node*);
	void recursivePostOrder(Node*);
public:
	BST();
	bool insert(int);
	bool delByVal(int);
	int count();
	void recursivePreOrder();
	void recursiveInOrder();
	void recursivePostOrder();
	void empty();
	~BST();
};

