#include <iostream>
#include "Node.h"
#include "Stack.h"
#include <string>
#include <iomanip>
using namespace std;

int Stack::Length()
{
	int cont = 0;

	if (!IsEmpty()) {
		PointerNode aux = top;
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
	}
	return cont;
};

string Stack::GetTop()
{
	string result = "";
	if (!IsEmpty()) {
		PointerNode temp = top;
		result = top->charValue;
	}
	return result;
};

void Stack::Push(std::string value)
{
	if (top == NULL) {
		top = new Node(value);
	}
	else {
		top = new Node(value, top);
	}
};

void Stack::PushNumber(float value)
{
	if (top == NULL) {
		top = new Node(value);
	}
	else {
		top = new Node(value, top);
	}
};

string Stack::Pop()
{
	string result = "";
	if (!IsEmpty()) {

		if (top != NULL)
		{
			PointerNode temp = top;
			result = top->charValue;
			top = top->NextNode;
			delete temp;
		}
	}
	return result;
};

float Stack::PopNumber()
{
	float result = 0;
	if (!IsEmpty()) {

		if (top != NULL)
		{
			PointerNode temp = top;
			result = top->value;
			top = top->NextNode;
			delete temp;
		}
	}
	return result;
};

void Stack::DisplayNumber() {
	PointerNode aux = top;
	while (aux != NULL) {
		cout << " " << fixed << setprecision(2) << aux->value;
		aux = aux->NextNode;
	}
};

void Stack::Display() {
	PointerNode aux = top;
	while (aux != NULL) {
		cout << aux->charValue << " -> ";
		aux = aux->NextNode;
	}
};

