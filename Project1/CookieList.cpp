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
// Default Constructor
CookieList::CookieList() : first(nullptr), last(nullptr), count(0) {}

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

bool CookieList::isEmpty() const {
	return count == 0;
}

CookieList::~CookieList()
{
	if (!this->isEmpty())
	{
		this->clearList();
	}
	delete first;
	first = nullptr;
}
