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
	
    // Search for the Snickerdoodle cookie
    bool found = myCookieList.searchCookie("Snickerdoodle");
    cout << "Search for Snickerdoodle: " << (found ? "Found" : "Not Found") << endl;

    // Search for a non-existent cookie
    found = myCookieList.searchCookie("Peanut Butter");
    cout << "Search for Peanut Butter: " << (found ? "Found" : "Not Found") << endl;

    // Test the copy constructor
    CookieList copiedList(myCookieList);
    cout << "Contents of the copied list:" << endl;
    printAllCookies(copiedList);
    cout << endl;

    // Clear the original list
    myCookieList.clearList();
    cout << "Original list after clearing:" << endl;
    printAllCookies(myCookieList);
    cout << "Copied list should still have cookies:" << endl;
    printAllCookies(copiedList);
    cout << endl;

    // Test the assignment operator
    CookieList anotherList;
    anotherList.addCookie("Macadamia Nut", 220, 1, { "Flour", "Sugar", "Macadamia Nuts" });
    anotherList = myCookieList;  // myCookieList is currently empty
    cout << "After assignment from an empty list:" << endl;
    printAllCookies(anotherList);
    cout << endl;

    // Re-populate myCookieList and assign again
    createCookieList(myCookieList);
    anotherList = myCookieList;
    cout << "After re-populating and re-assigning:" << endl;
    printAllCookies(anotherList);
    cout << endl;


	return 0;
}