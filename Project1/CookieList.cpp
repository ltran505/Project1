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

CookieList::~CookieList()
{
	if !(this->isEmpty())
	{
		this->clearList();
	}
}
