#include <limits>
#include "SkipList.h"
#include "SkipListNode.h"

class SkipListNode;

	SkipList::SkipList(){
		this->head = new SkipListNode();
		SkipListNode *right = new SkipListNode(INT_MAX);
		this->head->setRight(right);
	}

	void add(int value){
		SkipListNode *newNode = new SkipListNode(value);
		while(true){


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