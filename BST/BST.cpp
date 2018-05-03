#include "BST.h"


Node::Node(int data)
{
	this->data = data;
	left = nullptr;
	right = nullptr;
}

int Node::getData()
{
	return data;
}

void Node::setData(int data)
{
	this->data = data;
}

Node * Node::getLeft()
{
	return left;
}

void Node::setLeft(Node *left)
{
	this->left = left;
}

Node * Node::getRight()
{
	return right;
}

void Node::setRight(Node *right)
{
	this->right = right;
}





void BST::freeTree(Node *del)
{
	if (del == nullptr)
		return;

	freeTree(del->getLeft());
	freeTree(del->getRight());
	delete del;
}

BST::BST()
{
	root = nullptr;
}

bool BST::insert(int data)
{
	Node *newNode = new Node(data);
	if (newNode == nullptr) {
		return false;
	}
	if (root == nullptr) {
		root = newNode;
		return true;
	}

	Node *temp = root;

	while (temp != nullptr) {
		if (temp->getData() > data) {
			if (temp->getLeft() == nullptr) {
				temp->setLeft(newNode);
				return true;
			}
			temp = temp->getLeft();
		}
		else if (temp->getData() < data) {
			if (temp->getRight() == nullptr) {
				temp->setRight(newNode);
			}
			temp = temp->getRight();
		}
		else {
			return newNode;
			return false;
		}
		
	}
}

bool BST::delByVal(int data)
{
	if(root==nullptr)
		return false;
	
	Node* del = root,*parent=root;

	while (data != del->getData()) {
		if (data < del->getData()) {
			parent = del;
			del = del->getLeft();
		}
		else {
			parent = del;
			del->getRight();
		}
		if (del == nullptr)
			return false;
	}

	while (true) {
		if (del->getRight() == nullptr&&del->getLeft() == nullptr) {
			if (parent->getLeft() == del)
			{
				parent->setLeft(nullptr);
				delete del;
				return true;
			}
			if (parent->getRight() == nullptr)
			{
				parent->setRight(nullptr);
				delete del;
				return true;
			}
			if (root == del) {
				root = nullptr;
				delete del;
				return true;
			}
		}
		if (del->getLeft()) {
			Node * max = del->getLeft();
			parent = del;
			while (max->getRight()) {
				parent =max;
				max = max->getRight();
			}
			int temp = del->getData();
			del->setData(max->getData());
			max->setData(temp);
			del = max;
		}
		if (del->getRight()) {
			Node * min = del->getRight();
			parent = del;
			while (min->getLeft()) {
				parent = min;
				min = min->getRight();
			}
			int temp = del->getData();
			del->setData(min->getData());
			min->setData(temp);
			del = min;
		}
	}

	return false;
}

int BST::count(Node *startNode)
{
	if (startNode == nullptr)
		return 0;
	return 1+count(root->getLeft())+count(root->getRight());
}

void BST::recursivePreOrder(Node *root)
{
	if (root == nullptr)
		return;
	cout << root->getData();
	recursivePreOrder(root->getLeft());
	recursivePreOrder(root->getRight());
}

void BST::recursiveInOrder(Node *root)
{
	if (root == nullptr)
		return;
	recursiveInOrder(root->getLeft());
	cout << root->getData();
	recursiveInOrder(root->getRight());
}

void BST::recursivePostOrder(Node *root)
{
	if (root == nullptr)
		return;
	recursivePostOrder(root->getLeft());
	recursivePostOrder(root->getRight());
	cout << root->getData();
}


int BST::count()
{
	return count(root);
}

void BST::recursivePreOrder()
{
	recursivePreOrder(root);
}

void BST::recursiveInOrder()
{
	recursiveInOrder(root);
}

void BST::recursivePostOrder()
{
	recursivePostOrder(root);
}

void BST::empty()
{
	freeTree(root);
}

BST::~BST()
{
	freeTree(root);
}
