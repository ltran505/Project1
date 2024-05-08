/*
	Guild, Ryan (team lead)
	Tran, Lily
	Nguyen, Jordan
	Aljaffan, Maha

	CS A250
	Project (Part B)
*/

#ifndef COOKIELIST_H
#define COOKIELIST_H

#include "Cookie.h"

class Node
{
public:
	Node() : cookie(), next(nullptr) {}
	Node(const Cookie& newCookie, Node* newNext)
		: cookie(newCookie), next(newNext) {}
	Cookie& getCookie() { return cookie; }
	Node* getNext() const { return next; }
	void setCookie(const Cookie& newCookie) { cookie = newCookie; }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}
private:
	Cookie cookie;
	Node* next;
};

class CookieList
{
public:
	// Default constructor
	CookieList();
	
	// Functions addCookie
	void addCookie(const Cookie& newCookie);
	
	// Accessor function
	size_t getCount() const;

	// Boolean functions
	bool isEmpty() const;

	// Function printAllCookies
	void printAllCookies() const;

	// Function clearList
	void clearList();

	// The Big Three
	CookieList(const CookieList& other); //Copy Constructor
	CookieList& operator=(const CookieList& rhs); //Overloaded assignment operator
	~CookieList(); //Destructor

private:

	Node* first;
	Node* last;
	size_t count;
};

#endif

