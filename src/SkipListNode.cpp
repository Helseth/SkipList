#include <limits>
#include "SkipListNode.h"


	SkipListNode::SkipListNode(){ //Special case for initial construction
		this->value = INT_MIN;
		this->up = 0;
		this->down = 0;
		this->left = 0;
		this->right = 0;
	}
	SkipListNode::SkipListNode(int value){ //Contructor
		this->value = value;
		this->up = 0;
		this->down = 0;
		this->left = 0;
		this->right = 0;
	}

	//I would hope you know what these do...
	int SkipListNode::getValue(){
		return this->value;
	}
	void SkipListNode::setValue(int value){
		this->value = value;
	}
	SkipListNode SkipListNode::getLeft(){
		return *left;
	}
	void SkipListNode::setLeft(SkipListNode *left){
		this->left = left;
	}
	SkipListNode SkipListNode::getRight(){
		return *right;
	}
	void SkipListNode::setRight(SkipListNode *right){
		this->right = right;
	}

	SkipListNode SkipListNode::getUp(){
		return *up;
	}
	void SkipListNode::setUp(SkipListNode *up){
		this->up = up;
	}
	SkipListNode SkipListNode::getDown(){
		return *down;
	}
	void SkipListNode::setDown(SkipListNode *down){
		this->down = down;
	}

	//Operator Overloads
	bool operator==(const SkipListNode& lhs, const SkipListNode& rhs){
		if(lhs.value == rhs.value)
			return true;
		else
			return false;
	}
	bool operator!=(const SkipListNode& lhs, const SkipListNode& rhs){
		if(lhs.value != rhs.value)
			return true;
		else
			return false;
	}
	bool operator<(const SkipListNode& lhs, const SkipListNode& rhs){
		if(lhs.value < rhs.value)
			return true;
		else
			return false;
	}
	bool operator<=(const SkipListNode& lhs, const SkipListNode& rhs){
		if(lhs.value <= rhs.value)
			return true;
		else
			return false;
	}
	bool operator>(const SkipListNode& lhs, const SkipListNode& rhs){
		if(lhs.value > rhs.value)
			return true;
		else
			return false;
	}
	bool operator>=(const SkipListNode& lhs, const SkipListNode& rhs){
		if(lhs.value >= rhs.value)
			return true;
		else
			return false;
	}

	