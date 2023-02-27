#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node {

private:
	string charValue = "";
	float value = 0;
	Node* NextNode;


public:  // Constructors

	Node() {
		string charValue = "";
		value = 0;
		NextNode = NULL;
	}

	Node(string v)
	{
		charValue = v;
		NextNode = NULL;
	}

	Node(float v)
	{
		value = v;
		NextNode = NULL;
	}

	Node(float v, Node* newNextNode)
	{
		value = v;
		NextNode = newNextNode;
	}

	Node(string charVal, Node* newNextNode)
	{
		charValue = charVal;
		NextNode = newNextNode;
	}
	friend class Queue;
	friend class Stack;
	friend class List;
	friend class ExpressionProcessor;
};

typedef Node* PointerNode; //Alias
