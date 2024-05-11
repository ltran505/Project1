/*
	Guild, Ryan (team leader)
	Tran, Lily
	Nguyen, Jordan
	Aljaffan, Maha

	CS A250
	Project (Part B)
*/

#include "Cookie.h"
#include "CookieList.h"
#include "Testing.h"
#include "Interface.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    
    CookieList myCookieList;
    createCookieList(myCookieList);
    displayMenu();
    processChoice(myCookieList);
	cout << endl;
	return 0;
}