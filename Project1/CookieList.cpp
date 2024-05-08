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

void CookieList::addCookie(const std::string& name, size_t calories,
			size_t servings, const std::set<std::string>& ingredients)
{
	Cookie newCookie(name, calories, servings, ingredients);
	Node* newNode = new Node(newCookie, nullptr);

	if (count == 0)
	{
		first, last = newNode;
	}else
	{
		last->setNext(newNode);
		last = newNode;
	}
	++count;
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
	Node* current = first;

	cout << "Cookie Names:";
	while (current != nullptr)
	{
		cout << current->getCookie().getName() << endl;
		current = current->getNext();
	}
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
