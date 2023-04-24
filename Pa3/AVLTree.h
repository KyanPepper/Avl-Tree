#pragma once
#include "AVLNode.h"
#include <iostream>
class AVLTree
{
public:
	//This is my implementation of the textbooks avl. Implmented with class instead of structs. Uses
	// Private varibles with a refpointer returns with getters. Look in Node class for implementation.
AVLTree() {
		phead = nullptr;
	}
~AVLTree() {
		cout << "Destroying Tree" << endl;
	}
//Helper Function
void printInOrder() {
	int rank = 50;
	printInOrder(phead,rank);
}

//Prints in order but with rank as a reference that updates from the lowest node.
void printInOrder(AVLNode* node, int &rank) const {
	if (node == nullptr) {
		return;
	}
	printInOrder(node->getLeftp(), rank);
	rank--;
	cout << rank << ". " << node->getData().getName() << ", " << node->getData().getRate() << endl;
	printInOrder(node->getRightP(), rank);
}
//checks for empty tree
bool empty() {
	return phead == nullptr;
}
//finds max value
AVLNode* findMax(AVLNode* t) const
{
	if (t != nullptr)
		while (t->getRightP() != nullptr)
			t = t->getRightP();
	return t;
}
//Finds minimum value in tree
AVLNode* findMin(AVLNode* t) const
{
	if (t != nullptr)
		while (t->getLeftp() != nullptr)
			t = t->getLeftp();
	return t;
}
//textbook insert
void Insert(const CancerData &datam, AVLNode*& t) {
	if (t == nullptr) {
		t = new AVLNode(datam, nullptr, nullptr, 0);
		t->setheight(0);

	}
	else if (datam > t->getData()) {
		Insert(datam, t->getRightpRef());
	}
	else if (datam < t->getData()) {
		Insert(datam, t->getLeftpRef());
	}
	balance(t);
}
//Balences tree textbook style.
void balance(AVLNode*& node) {
	if (node == nullptr)
		return;
	if (height(node->getLeftp()) - height(node->getRightP()) > 1) {
		if (height(node->getLeftp()->getLeftp()) >= height(node->getLeftp()->getRightP()))
			node = rightRotate(node);
		else
			node = doubleRightRotate(node);
	}
	if (height(node->getRightP()) - height(node->getLeftp()) > 1) {
		if (height(node->getRightP()->getRightP()) >= height(node->getRightP()->getLeftp()))
			node = leftRotate(node);
		else
			node = doubleLeftRotate(node);
	}
	node->setheight(max(height(node->getLeftp()), height(node->getRightP())) + 1);
}
//Returns height of node
int height(AVLNode* t) const
{
	if (t == nullptr) {
		return -1;
	}
	else {
		return t->getHeight();
	}
}
//All functions below deal with roations using textbook solution
AVLNode* rightRotate(AVLNode*& t) {
	AVLNode* n1 = t->getLeftp();
	t->setLeftp(n1->getRightP());
	n1->setRightp(t);
	t->setheight(max(height(t->getLeftp()), height(t->getRightP())) + 1);
	n1->setheight(max(height(n1->getLeftp()), (t->getHeight())) + 1);
	return n1;
}
AVLNode* leftRotate(AVLNode*& t) {
	AVLNode* n1 = t->getRightP();
	t->setRightp(n1->getLeftp()); 
	n1->setLeftp(t);
	t->setheight(max(height(t->getRightP()), height(t->getLeftp())) + 1) ;
	n1->setheight(max(height(n1->getRightP()), (t->getHeight())) + 1);
	return n1;
}
AVLNode* doubleRightRotate(AVLNode*& t) {
	t->setLeftp(leftRotate(t->getLeftpRef()));
	t = rightRotate(t);
	return t;
}
AVLNode* doubleLeftRotate(AVLNode*& t) {
	t->setRightp(rightRotate(t->getRightpRef())) ;
	t = leftRotate(t);
	return t;
}
//helper function
void Insert(const CancerData& data) {
	
	Insert(data, phead);

}
//Deletes Trees by individually deleteing all pointers.
void Clear(AVLNode* t) {
	if (t == nullptr) {
		return;
	}
	Clear(t->getLeftp());
	Clear(t->getRightP());
	delete t;
}//helper function
void Clear() {
	Clear(phead);
}
//helper function
AVLNode* findMax() {
	return findMax(phead);
}
//Helper function 
AVLNode* findMin() {
	return findMin(phead);
}

private:
	AVLNode* phead = nullptr;
};

