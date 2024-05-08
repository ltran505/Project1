/*
	Guild, Ryan (team lead)
	Tran, Lily
	Nguyen, Jordan
	Aljaffan, Maha

	CS A250
	Project (Part B)
*/

#include "CookieList.h"

#include <iostream>

// Testing
void CookieList::clearList()
{
	Node* current = first;
	while (current != nullptr) {
		Node* next = current->getNext();
		delete current;
		current = next;
	}
	first = nullptr;
	last = nullptr;
	count = 0;
}

size_t CookieList::getCount() const {
	return count;
}

CookieList::~CookieList()
{
	if !(this->isEmpty())
	{
		this->clearList();
	}
	delete first;
	first = nullptr;
}
