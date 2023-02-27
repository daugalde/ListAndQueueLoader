#pragma once
#include "Queue.h"
#include "List.h"
#include "Stack.h"

using namespace std;

class ExpressionProcessor {

private:
	Queue queue = Queue();
	List postFixExpressionList = List();
	Stack operatorStack = Stack();

public:
	ExpressionProcessor() {
		queue.LoadFiles();

		//queue.Display();
	}

	void ProcessFiles();

	void ProcessInfixExpression();

	bool CheckIfNumber(string elementOperator);

	int GetPriorityStack(string stringOperator);

	int GetPriorityElement(string stringOperator);

	void EvaluateExpression();

	friend class Queue;
	friend class List;
	friend class Stack;
};