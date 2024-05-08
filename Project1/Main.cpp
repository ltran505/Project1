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

#include <iostream>
#include <string>

using namespace std;

int main()
{
    CookieList myCookieList;

    createCookieList(myCookieList);

    cout << "All cookies in the list:" << endl;
    myCookieList.printAllCookies();
    cout << endl;

    Cookie myCookie("Snickerdoodle", 150, 2, 
        { "Flour", "Sugar", "Cinnamon" });

    myCookieList.addCookie
        ("Snickerdoodle", 150, 2, { "Flour", "Sugar", "Cinnamon" });

    cout << "After adding Snickerdoodle:" << endl;
    myCookieList.printAllCookies();
    cout << endl; 
	
    // Search for the Snickerdoodle cookie
    bool found = myCookieList.searchCookie("Snickerdoodle");
    cout << "Search for Snickerdoodle: " 
         << (found ? "Found" : "Not Found") << endl;

    // Search for a non-existent cookie
    found = myCookieList.searchCookie("Peanut Butter");
    cout << "Search for Peanut Butter: " 
         << (found ? "Found" : "Not Found") << endl;

    // Test the copy constructor
    CookieList copiedList(myCookieList);
    cout << "Contents of the copied list:" << endl;
    copiedList.printAllCookies();
    cout << endl;

    // Clear the original list
    myCookieList.clearList();
    cout << "Original list after clearing:" << endl;
    myCookieList.printAllCookies();
    cout << endl;
    cout << "Copied list should still have cookies:" << endl;
    copiedList.printAllCookies();
    cout << endl;

    // Test the assignment operator
    CookieList anotherList;
    anotherList.addCookie("Macadamia Nut", 220, 1,
        { "Flour", "Sugar", "Macadamia Nuts" });
    anotherList = myCookieList;
    cout << "After assignment from an empty list:" << endl;
    anotherList.printAllCookies();
    cout << endl;

    // Re-populate myCookieList and assign again
    createCookieList(myCookieList);
    anotherList = myCookieList;
    cout << "After re-populating and re-assigning:" << endl;
    anotherList.printAllCookies();
    cout << endl;


	return 0;
}