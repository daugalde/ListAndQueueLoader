#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"

using namespace std;

class QueueNode {

private:
	List* list = new List();
	QueueNode* NextNode;

public:  // Constructors

	QueueNode() {
		NextNode = NULL;
	}

	QueueNode(string fileName)
	{
		ifstream file(fileName);
		string str;
		while (!file.eof()) {
			getline(file, str);
			this->list->Add(str);
		}
		NextNode = NULL;
	}

	friend class List;
	friend class Queue;
	friend class ExpressionProcessor;
};

typedef QueueNode* QueuePointerNode; //Alias
