/*
	Guild, Ryan (team lead)
	Tran, Lily
	Nguyen, Jordan
	Aljaffan, Maha

	CS A250
	Project (Part B)
*/

#include "Cookie.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	Cookie aCookie;
	aCookie.printRecipe();
	aCookie.printCalories();
	aCookie.printIngredients();
	
	aCookie.setName("Lemon Square Bars");
	aCookie.setCalories(140);
	aCookie.setServings(30);

	vector<string> newSteps{ "Flour", "Sugar", "Butter", "Eggs", "Lemon Juice" };
	aCookie.setIngredients(newSteps);

	aCookie.printRecipe();
	aCookie.printCalories();
	aCookie.printIngredients();

	Cookie aCookieTwo("Chocolate Chip", 1000, 20, { "Flour", "Sugar", "Eggs", "Butter", "Chocolate" });
	aCookieTwo.printRecipe();
	aCookieTwo.printCalories();
	aCookieTwo.printIngredients();

	return 0;
}