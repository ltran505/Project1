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

using namespace std;

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

Cookie* CookieList::getCookie(const std::string& cookieName) const {
	Node* current = first;
	while (current != nullptr) {
		if (current->getCookie().getName() == cookieName) {
			return &(current->getCookie()); // Return a pointer to the Cookie object
		}
		current = current->getNext(); // Move to the next node
	}
	return nullptr; // Return nullptr if no cookie with the given name is found
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

bool CookieList::searchCookie(const std::string& cookieName) const {
	Node* current = first;
	while (current != nullptr) {
		if (current->getCookie().getName() == cookieName) { // Assuming Cookie class has a getName() method
			return true; // Cookie found, return true
		}
		current = current->getNext(); // Move to next node
	}
	return false; // Cookie not found after traversing the list
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

// Copy Constructor
CookieList::CookieList(const CookieList& other) : first(nullptr), last(nullptr), count(0)
{
	// Code here
}

// 
CookieList& CookieList::operator=(const CookieList& cookieToAssign)
{
	// TODO: insert return statement here
	if (&cookieToAssign != this)
	{
	    Node *othertemp = cookieToAssign.first;
		first = othertemp;
		Node *temp = first;
		while (temp != nullptr && othertemp != nullptr)
		{
		    temp->setNext(othertemp->getNext());
		    temp = temp->getNext();
		    othertemp = othertemp->getNext();
		}
		count = cookieToAssign.count;
	}
	else
		cerr << "Attempted assignment to self.";
	
	return *this;
}

// Destructor
CookieList::~CookieList()
{
	if (!this->isEmpty())
	{
		this->clearList();
	}
	delete first;
	first = nullptr;
}
