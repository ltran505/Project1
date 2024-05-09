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
		<< "    a. Print all recipes \n" << "    b. Print cookie recipe \n"
		<< "    c. Print cookie calories \n" 
		<< "    d. Print limited calories \n" << "    e. To exit \n";

}


// Definition function processChoice
void processChoice(CookieList& cookieList)
{
	cout << "Enter your choice: ";
	char selection;
	cin >> selection;
	switch (selection)
	{
	case 'e': cout << "Thank you for using our software. Good bye!";
		break;
	default: cout << "  => Sorry. That is not a selection.\n\n"
		<< string(62, '=') << "\n" << "Would you like to try again (y/n)? ";
		char again;
		cin >> again;
		if (again == 'y')
			displayMenu();
		else
			cout << "Thank you for using our software. Good bye!";

		break;
	}

}
