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

void CookieList::addCookie(const std::string& name, size_t calories, size_t servings, const std::set<std::string>& ingredients)
{
	//Code here
}

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

bool CookieList::searchCookie(const std::string& cookieName) const
{
	// Code here
}

void CookieList::printAllCookies() const
{
	// Code here
}

CookieList::CookieList(const CookieList& other) : first(nullptr), last(nullptr), count(0)
{
	// Code here
}

CookieList& CookieList::operator=(const CookieList& cookieToAssign)
{
	// TODO: insert return statement here
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
