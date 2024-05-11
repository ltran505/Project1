/*
	Guild, Ryan (team leader)
	Tran, Lily
	Nguyen, Jordan
	Aljaffan, Maha

	CS A250
	Project (Part B)
*/

#include "Interface.h"

#include <iostream>
#include <string>

using namespace std;

// Definition function displayMenu
void displayMenu()
{
    cout << string(62, '*') << "\n"
        << string(24, ' ') << "COOKIE RECIPES" << string(24, ' ') << "\n"
        << string(62, '*') << "\n\n"
        << "Select one of the following: \n\n"
        << "    a. Print all recipes \n" 
        << "    b. Print cookie recipe \n"
        << "    c. Print cookie calories \n"
        << "    d. Print limited calories \n" 
        << "    e. To exit \n";
}

// Definition function processChoice
void processChoice(CookieList& cookieList)
{
    char selection;
    bool keepGoing = true;

    cout << "\nEnter your choice: ";
    cin >> selection;

    while (keepGoing)
    {
        switch (selection)
        {
        case 'a':
            cookieList.printAllCookies();
            cout << "\n" << string(62, '=') << "\n\n";
            cout << "Would you like to continue (y/n)? ";
            break;
        case 'e':
            cout << "\nThank you for using our software. Good bye!\n";
            keepGoing = false; // Exit the loop
            break;
        default:
            cout << "\n  => Sorry. That is not a selection.\n\n"
                << string(62, '=') << "\n\n"
                << "Would you like to try again (y/n)? ";
            break;
        }

        char tryAgain;
        cin >> tryAgain;
        cout << endl;

        if (tryAgain == 'n')
        {
            cout << "Thank you for using our software. Good bye!";
            keepGoing = false; // Exit the loop
        }
        else if (tryAgain == 'y')
        {
            keepGoing = false;
            displayMenu();
            processChoice(cookieList);
        }
    }
}
