#include <limits>
#include <iostream>
#include "SkipList.h"
#include "SkipListNode.h"

class SkipListNode;

	SkipList::SkipList(){ //Init the skip list
		this->head = new SkipListNode();
		SkipListNode *right = new SkipListNode(INT_MAX);
		this->head->setRight(right);
	}

	void SkipList::add(int value){
		SkipListNode *curr = this->head;
		SkipListNode *newNode = new SkipListNode(value);
		while(true){
			std::cout << "NewNode is " << newNode->getValue() << "\n";
			std::cout << "Curr is " << curr->getValue() << "\n";
			std::cout << "Curr->right is " << curr->getRight()->getValue() << "\n";
			std::cout << "Comparing " << newNode->getValue() << " to " << curr->getRight()->getValue() << "\n";
			if(newNode->getValue() > curr->getRight()->getValue() && curr->getRight() != NULL){
				std::cout << newNode->getValue() << " is greater than " << curr->getRight()->getValue() << ": Moving right\n";
				curr = curr->getRight();
				continue;
			}
			else if(newNode->getValue() < curr->getRight()->getValue() && curr->getRight() != NULL && curr->getDown() == NULL){
				std::cout << newNode->getValue() << " is less than " << curr->getRight()->getValue() << " and down is null\n";
				newNode->setRight(curr->getRight());
				std::cout << newNode->getValue() << " right is " << newNode->getRight()->getValue() << "\n";
				curr->getRight()->setLeft(newNode);
				curr->setRight(newNode);
				newNode->setLeft(curr);
				std::cout << newNode->getValue() << " left is " << newNode->getLeft()->getValue() << "\n";
				std::cout << newNode->getValue() << " is now between " << newNode->getLeft()->getValue() << " and " << newNode->getRight()->getValue() << "\n";
				break;
			}
			else{
				curr = curr->getDown();
				continue;
			}
		}
	}

	bool remove(int){
		return true;
	}

	bool contains(int){
		return true;
	}

	//SkipListNode getLeftNode(SkipListNode *left);
	//SkipListNode findValue(int value);