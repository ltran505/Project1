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
        << string(24, ' ') << "COOKIE RECIPES" << string(24, ' ') 
        << "\n" << string(62, '*') << "\n\n"
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
    char mainSelection;
    bool keepGoing = true;

    cout << "\nEnter your choice: ";
    cin >> mainSelection;

    while (keepGoing)
    {
        switch (mainSelection)
        {
        case 'a':
            cookieList.printAllCookies();
            cout << "\n" << string(62, '=') << "\n\n"
                << "Would you like to continue (y/n)? ";
            break;
        case 'b':
            cout << "\n" << string(62, '-') << "\n"
                << "    COOKIE RECIPE    "
                << "\n" << string(62, '-') << "\n\n"
                << "Choose a cookie to view the recipe.\n\n";
            cookieList.printCookiesSelection();
            cout << "\nSelect the cookie: ";
            size_t cookieSelection;
            cin >> cookieSelection;
            cookieList.printRecipe(cookieSelection);
            cout << "\n" << string(62, '=') << "\n\n";
            cout << "Would you like to continue (y/n)? ";
            break;
        case 'c':
            cout << "\n" << string(62, '-') << "\n"
                << "    COOKIE CALORIES    "
                << "\n" << string(62, '-') << "\n\n"
                << "Choose a cookie # to view number of calories.\n\n";
            cookieList.printCookiesSelection();
            cout << "\nYour choice: ";
            cin >> cookieSelection;
            cout << "\n";
            cookieList.printCalories(cookieSelection);
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
        if (keepGoing)
        {
            char tryAgain;
            cin >> tryAgain;
            if (tryAgain == 'n')
            {
                keepGoing = false;
                cout << "\nThank you for using our software. Good bye!";
            }
            else if (tryAgain == 'y')
            {
                keepGoing = false;
                displayMenu();
                processChoice(cookieList);
            }
        }
    }

}
