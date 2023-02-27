#include "ExpressionProcessor.h"
#include <iomanip>
void ExpressionProcessor::ProcessFiles() {

	ProcessInfixExpression();
}

void ExpressionProcessor::ProcessInfixExpression() {

	int queueLength = this->queue.Length();
	for (int i = 0; i < queueLength; i++) {
		cout << "START Display List Item " + to_string(i + 1) << "\n" << endl;
		QueuePointerNode element = this->queue.GetElementAt(i);
		List* list = element->list;
		cout << " Original Expression List \n" << endl;
		list->DisplayString();
		this->postFixExpressionList.~List();
		while (!list->IsEmpty()) {
			PointerNode node = list->RemoveElement();
			if (CheckIfNumber(node->charValue)) {
				this->postFixExpressionList.Add(node->charValue);
			}
			else {
				if (this->operatorStack.IsEmpty()) {
					this->operatorStack.Push(node->charValue);
				}
				int commingOperator = GetPriorityElement(node->charValue);
				int stackOperator = GetPriorityStack(this->operatorStack.GetTop());
				if (commingOperator > stackOperator && node->charValue != ")") {
					this->operatorStack.Push(node->charValue);
				}
				else if (commingOperator <= stackOperator && node->charValue != ")") {
					this->postFixExpressionList.Add(this->operatorStack.Pop());
					this->operatorStack.Push(node->charValue);
				}
				else if (node->charValue == ")") {
					while (this->operatorStack.GetTop() != "(") {
						this->postFixExpressionList.Add(this->operatorStack.Pop());
					}
					this->operatorStack.Pop();
					
				}
			}
		}
		while (!this->operatorStack.IsEmpty()) {
			string poppedElement = this->operatorStack.Pop();
			if (poppedElement != "(") {
				this->postFixExpressionList.Add(poppedElement);
			}
		}

		cout << " Postfix Expression List \n" << endl;

		this->postFixExpressionList.DisplayString();

		EvaluateExpression();

		cout << "\n\nEND Display List Item " + to_string(i + 1) << endl;
		cout << "     " << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "     " << endl;
	}
	
}

bool ExpressionProcessor::CheckIfNumber(string elementOperator) {

	try {
		int num = stoi(elementOperator);
		return true;
	}
	catch (std::exception& e) {
		return false;
	}
}

int ExpressionProcessor::GetPriorityStack(string stringOperator) {
	if (stringOperator == "+" || stringOperator == "-") {
		return 1;
	}
	else if (stringOperator == "*" || stringOperator == "/") {
		return 2;
	}
	else if (stringOperator == "^") {
		return 3;
	}
	else if (stringOperator == "(") {
		return 0;
	}
}

int ExpressionProcessor::GetPriorityElement(string stringOperator) {
	if (stringOperator == "+" || stringOperator == "-") {
		return 1;
	}
	else if (stringOperator == "*" || stringOperator == "/") {
		return 2;
	}
	else if (stringOperator == "^") {
		return 4;
	}
	else if (stringOperator == "(") {
		return 5;
	}
}

void ExpressionProcessor::EvaluateExpression() {

	Stack result = Stack();

	float num1 = 0;

	float num2 = 0;

	float mathResult = 0;

	while (!this->postFixExpressionList.IsEmpty()) {

		string numberOrOperator = this->postFixExpressionList.RemoveElement()->charValue;
		if (CheckIfNumber(numberOrOperator)) {
			result.PushNumber(stoi(numberOrOperator));
		}
		else {

			num2 = result.PopNumber();
			num1 = result.PopNumber();

			if (numberOrOperator == "+") {
				mathResult = (num1 + num2);
			}
			else if (numberOrOperator == "-") {
				mathResult = num1 - num2;
			}
			else if (numberOrOperator == "*") {
				mathResult = num1 * num2;
			}
			else if (numberOrOperator == "/" && num2 != 0) {
				mathResult = num1 / num2;
			}
			else if (numberOrOperator == "^") {
				mathResult = 1;
				while (num2 != 0) {
					mathResult *= num1;
					--num2;
				}

			}
			result.PushNumber(mathResult);
		}
	}
	
	cout << " Evaluated Expression List \n" << endl;

	result.DisplayNumber();


}