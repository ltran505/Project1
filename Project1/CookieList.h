/*
	Guild, Ryan (team leader)
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
	void addCookie(const std::string& name, size_t calories,
	size_t servings, const std::set<std::string>& ingredients);

	// Accessor function
	Cookie* getCookie(const std::string& cookieName) const;
	size_t getCount() const;

	// isEmpty function
	bool isEmpty() const;

	// search cookie function
	bool searchCookie(const std::string& cookieName) const;

	// Function printAllCookies
	void printAllCookies() const;

	// Function clearList
	void clearList();

	// The Big Three
	// Copy Constructor
	CookieList(const CookieList& other); 

	// Overloaded assignment operator
	CookieList& operator=(const CookieList& cookieToAssign); 

	// Destructor
	~CookieList();

private:

	Node* first;
	Node* last;
	size_t count;
};

#endif

