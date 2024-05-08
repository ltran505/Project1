/*
	Guild, Ryan (team lead)
	Tran, Lily
	Nguyen, Jordan
	Aljaffan, Maha

	CS A250
	Project (Part B)
*/

#include "Cookie.h"
#include "CookieList.h"
#include "Testing.h"

#include <iostream>
#include <string>

using namespace std;


void printAllCookies(const CookieList& list) {
	list.printAllCookies();
}

int main()
{
    CookieList myCookieList;

    createCookieList(myCookieList);

    cout << "All cookies in the list:" << endl;
    printAllCookies(myCookieList);
    cout << endl;

    Cookie myCookie("Snickerdoodle", 150, 2, { "Flour", "Sugar", "Cinnamon" });

    myCookieList.addCookie("Snickerdoodle", 150, 2, { "Flour", "Sugar", "Cinnamon" });

    cout << "After adding Snickerdoodle:" << endl;
    printAllCookies(myCookieList);
    cout << endl; 
	
	return 0;
}