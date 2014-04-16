#include <limits>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "SkipList.h"
#include "SkipListNode.h"

class SkipListNode;

	SkipList::SkipList(){ //Init the skip list
		this->head = new SkipListNode(INT_MIN);
		SkipListNode *right = new SkipListNode(INT_MAX);
		this->head->setRight(right);
		this->depth = 1;
		srand (time(NULL));
	}

	void SkipList::add(int value){
		SkipListNode *curr = this->head;
		SkipListNode *newNode = new SkipListNode(value);
		while(true){
			/*std::cout << "NewNode is " << newNode->getValue() << "\n";
			std::cout << "Curr is " << curr->getValue() << "\n";
			std::cout << "Curr->right is " << curr->getRight()->getValue() << "\n";
			std::cout << "Comparing " << newNode->getValue() << " to " << curr->getRight()->getValue() << "\n";*/
			if(newNode->getValue() > curr->getRight()->getValue() && curr->getRight() != NULL){
				//std::cout << newNode->getValue() << " is greater than " << curr->getRight()->getValue() << ": Moving right\n";
				curr = curr->getRight();
				continue;
			}
			else if(newNode->getValue() < curr->getRight()->getValue() && curr->getRight() != NULL && curr->getDown() == NULL){
				//std::cout << newNode->getValue() << " is less than " << curr->getRight()->getValue() << " and down is null\n";
				newNode->setRight(curr->getRight());
				//std::cout << newNode->getValue() << " right is " << newNode->getRight()->getValue() << "\n";
				curr->getRight()->setLeft(newNode);
				curr->setRight(newNode);
				newNode->setLeft(curr);
				//std::cout << newNode->getValue() << " left is " << newNode->getLeft()->getValue() << "\n";
				std::cout << newNode->getValue() << " is now between " << newNode->getLeft()->getValue() << " and " << newNode->getRight()->getValue() << "\n";
				break;
			}
			else{
				curr = curr->getDown();
				continue;
			}
		}
		bool flip = coinFlip();
		SkipListNode *farLeft = newNode;
		while(flip == true){
				std::cout << "Random coin flip is true\n";
				while(farLeft->getUp() == NULL && farLeft->getLeft() != NULL){ //Iterate all the way to the left in the current layer while up is NULL
						farLeft = farLeft->getLeft();
					}
				if(farLeft->getUp() == NULL)
					addTopLayer();
				
				SkipListNode *stackedNode = new SkipListNode(value);
				farLeft = newNode;
				stackedNode->setDown(newNode);
				std::cout << "StackedNode down is " << stackedNode->getDown()->getValue() << "\n";
				if(newNode->getLeft()->getUp() != NULL)
					stackedNode->setLeft(newNode->getLeft()->getUp());
				else{
					while(farLeft->getUp() == NULL){ //Iterate all the way to the left in the current layer while up is NULL
						farLeft = farLeft->getLeft();
					}
					stackedNode->setLeft(farLeft->getUp());

				}
				stackedNode->setRight(newNode->getRight()->getUp());
				stackedNode->getLeft()->setRight(stackedNode);
				stackedNode->getRight()->setLeft(stackedNode);
				newNode->setUp(stackedNode);
				newNode = stackedNode;
				farLeft = newNode;
				flip = coinFlip();
			}

		farLeft = newNode;
		while(farLeft->getLeft() != NULL){ //Iterate all the way to the left in the current layer
			farLeft = farLeft->getLeft();
		}
		if(farLeft->getUp() == NULL) //if the "INT_MIN" node has no up, add a new layer
			addTopLayer();
	}

	bool remove(int){
		return true;
	}

	bool contains(int){
		return true;
	}

	bool SkipList::coinFlip(){
		double flip = (double)rand()/(double)RAND_MAX;
		//std::cout << "Flip is " << flip << "\n";
		if(flip >= .5)
			return true;
		return false;
	}

	void SkipList::addTopLayer(){

		SkipListNode *newHead = new SkipListNode(INT_MIN);
		SkipListNode *newTail = new SkipListNode(INT_MAX);
		SkipListNode *farRight = this->head;

		newHead->setRight(newTail);
		newHead->setDown(this->head);
		newTail->setLeft(newHead);
		this->head->setUp(newHead);

		while(farRight->getRight() != NULL){ //iterate from head all the way right
			//std::cout << "FarRight is " << farRight->getValue() << "\n";
			if(farRight->getRight()->getValue() != INT_MAX)
				farRight = farRight->getRight();
			else{
				farRight = farRight->getRight();
				//std::cout << "FarRight is " << farRight->getValue() << "\n";
				farRight->setUp(newTail);
				newTail->setDown(farRight);
			}
		}

		this->head = newHead;
		this->depth++;
		std::cout << "New top layer added\n";
	}

	//SkipListNode findValue(int value);