/*
	Guild, Ryan (team leader)
	Tran, Lily
	Nguyen, Jordan
	Aljaffan, Maha

	CS A250
	Project (Part B)
*/

#include "CookieList.h"

#include <iostream>

using namespace std;

void CookieList::addCookie(const Cookie& newCookie)
{
	Node* newNode = new Node(newCookie, nullptr);

	if (count == 0) 
	{
		first = newNode;
		last = newNode;
	}
	else 
	{
		last->setNext(newNode);
		last = newNode;
	}
	count++;
}

void CookieList::addCookie(const std::string& name, size_t calories,
		size_t servings, const std::set<std::string>& ingredients)
{
	Cookie newCookie(name, calories, servings, ingredients);
	addCookie(newCookie);
}

size_t CookieList::getCount() const 
{
	return count;
}

bool CookieList::isEmpty() const 
{
	return (count == 0);
}

bool CookieList::searchCookie(const std::string& cookieName) const
{
	Node* current = first;
	while (current != nullptr) 
	{
		if (current->getCookie().getName() == cookieName) 
		{
			return true;
		}
		current = current->getNext();
	}
	return false;
}

void CookieList::printAllCookies() const
{
	cout << "\n" << string(62, '-') << "\n"
		<< "    COOKIE RECIPES    \n"
		<< string(62, '-') << "\n\n";

		Node* current = first;
		
	while (current != nullptr)
	{
		cout << "    " << current->getCookie().getName() << "\n";
		current = current->getNext();
	}
	
}

void CookieList::printCookiesSelection() const
{
	Node* current = first;
	size_t index = 1;

	while (current != nullptr) {
		cout << "    " << index << ": "
			<< current->getCookie().getName() << "\n";
		current = current->getNext();
		++index;
	}
}

void CookieList::printRecipe(size_t selection) const
{
	getCookieLocation(--selection)->getCookie().printRecipe();
}

void CookieList::clearList()
{
	Node* current = first;
	while (current != nullptr)
	{
		Node* next = current->getNext();
		delete current;
		current = next;
	}
	first = nullptr;
	last = nullptr;
	count = 0;
}

CookieList::CookieList(const CookieList& other)
{
	first = nullptr;
	last = nullptr;
	count = 0;
	Node* current = other.first;
	while (current != nullptr)
	{
		addCookie(current->getCookie());
		current = current->getNext();
	}
}

CookieList& CookieList::operator=(const CookieList& cookieToAssign)
{
	if (&cookieToAssign != this)
	{
		clearList();
		Node* current = cookieToAssign.first;
		while (current != nullptr)
		{
			addCookie(current->getCookie());
			current = current->getNext();
		}
	}
	else
	{
		cerr << "Attempted assignment to itself.";
	}

	return *this;
}

CookieList::~CookieList()
{
	clearList();
}

Node* CookieList::getCookieLocation(size_t selection) const
{
	Node* current = first;
	size_t index = 0;

	while (current != nullptr && index < selection)
	{
		current = current->getNext();
		++index;
	}

	return current;
}

void CookieList::printCalories(size_t selection) const
{
	const Cookie& cookieChoice = getCookieLocation(--selection)->getCookie();

	cout << "    " << cookieChoice.getName()
		<< " (calories: ";
	cookieChoice.printCalories();
	cout << ")" << '\n';
}

void CookieList::printLimitedCalories(size_t maxCalories) const
{
	Node* current = first;

	while (current != nullptr)
	{
		const Cookie& cookie = current->getCookie();
		if (cookie.getCalories() <= maxCalories)
		{
			cout << "    " << cookie.getName()
				<< " (calories: ";
			cookie.printCalories();
			cout << ")" << '\n';
		}
		current = current->getNext();
	}
}


