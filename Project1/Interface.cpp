/*
    Guild, Ryan (team leader)
    Tran, Lily
    Nguyen, Jordan
    Aljaffan, Maha

    CS A250
    Project (Part D)

    1. SELECTION NAME: Print cookie recipe and calories
    2. PURPOSE: This selection will print a list of cookies,
    ask the user to choose one, and based on the user's choice,
    it will print the servings, the needed ingredients,
    and the calories.
    Assumption: User chooses one of the cookies.
    3. EXPECTED OUTPUT:

    **************************************************************
                        COOKIE RECIPES
    **************************************************************

    Select one of the following:

        a. Print all recipes
        b. Print cookie recipe
        c. Print cookie calories
        d. Print limited calories
        e. Print cookie recipe and calories
        f. To exit

    Enter your choice: e

    --------------------------------------------------------------
        COOKIE RECIPE
    --------------------------------------------------------------

    Choose a cookie to view the recipe.

        1: Lemon Square Bars
        2: Biscotti
        3: Nutella Brownies
        4: Butter Snow Flakes
        5: Chocolate Chip Cookies
        6: Oatmeal Cookies
        7: Walnut Tassies
        8: Jam Thumbprints
        9: Gingersnaps
        10: Meringues
        11: Pizzelles
        12: Snickerdoodles

    Select the cookie: 1

        Recipe for Lemon Square Bars
            Servings: 32
            Ingredients: butter, butter, eggs, flour, lemon juice, sugar
            Calories: 136

    ==============================================================

    Would you like to continue (y/n)?

    4. TEST CASES:
            Choice 1 (first)
            Choice 5 (something in the middle)
            Choice 12 (last)

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
        << "    e. Print cookie recipe and calories \n"
        << "    f. To exit \n";
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
            cout << "\nYour choice: ";
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
        case 'd':
            cout << "\n" << string(62, '-') << "\n"
                << "    MAXIMUM CALORIES    "
                << "\n" << string(62, '-') << "\n\n"
                << "What is the maximum # of calories (100-200)? ";
            size_t maxCalories;
            cin >> maxCalories;
            cout << "\n";
            cookieList.printLimitedCalories(maxCalories);
            cout << "\n" << string(62, '=') << "\n\n"
                 << "Would you like to continue (y/n)? ";
            break;
        case 'e':
            cout << "\n" << string(62, '-') << "\n"
                << "    COOKIE RECIPE AND CALORIES   "
                << "\n" << string(62, '-') << "\n\n"
                << "Choose a cookie # to view the recipe" 
                << "and number of calories.\n\n";
            cookieList.printCookiesSelection();
            cout << "\nYour choice: ";
            cin >> cookieSelection;
            cookieList.printRecipe(cookieSelection);
            cookieList.printCaloriesOnly(cookieSelection);
            cout << "\n" << string(62, '=') << "\n\n";
            cout << "Would you like to continue (y/n)? ";
            break;
        case 'f':
            keepGoing = false;
            cout << "\nThank you for using our software. Good bye!";
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
                cout << '\n';
                displayMenu();
                processChoice(cookieList);
            }
        }
    }

}
