#include <iostream>
#include <fstream>
#include "Node.h"
#include "List.h"

using namespace std;

int List::Length()
{
	int cont = 0;

	PointerNode aux = head;
	if (!IsEmpty()) {
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
	}
	return cont;
};

void List::Add(string charVal)
{
	if (IsEmpty()) {
		head = new Node(charVal);
	}
	else
	{
		PointerNode aux = head;
		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = new Node(charVal);
	}
};

PointerNode List::RemoveElement() {
	PointerNode response = NULL;
	if (!IsEmpty()) {
		if (head->NextNode == NULL)
		{
			response = head;
			head = NULL;
			delete head;
		}
		else
		{
			response = head;
			head = head->NextNode;
		}
	}
	return response;
}

void List::DisplayString()
{
	PointerNode aux;
	if (IsEmpty()) {
		cout << "Lista esta vacia";
	}
	else
	{
		aux = head;
		while (aux)
		{
			cout << " " << aux->charValue;
			aux = aux->NextNode;
		}
		cout << "\n" << endl;
	}
};
