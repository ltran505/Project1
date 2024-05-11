/*
	Guild, Ryan (team leader)
	Tran, Lily
	Nguyen, Jordan
	Aljaffan, Maha

	CS A250
	Project (Part B)
*/

#include "Cookie.h"

#include <iostream>

using namespace std;

string Cookie::getName() const
{
	return name;
}

size_t Cookie::getCalories() const
{
	return calories;
}

size_t Cookie::getServings() const
{
	return servings;
}

set<string> Cookie::getIngredients() const
{
	return ingredients;
}

Cookie Cookie::getCookie() const
{
	return *this;
}

void Cookie::setName(const string& newName)
{
	name = newName;
}

void Cookie::setCalories(size_t newCalories)
{
	calories = newCalories;
}

void Cookie::setServings(size_t newServings)
{
	servings = newServings;
}

void Cookie::setIngredients(const vector<string>& newIngredients)
{
	if (!ingredients.empty())
	{
		ingredients.clear();
	}

	size_t size = newIngredients.size();
	for (size_t i = 0; i < size; ++i)
	{
		ingredients.insert(newIngredients[i]);
	}
}

void Cookie::printRecipe() const
{
	cout << "\n    Recipe for " << name << "\n"
		<< "    Servings: " << getServings() << "\n";
	printIngredients();
}

void Cookie::printIngredients() const
{
	cout << "    Ingredients: " << *getIngredients().begin();
	for (string element : ingredients)
	{
		cout << ", " << element;
	}
	cout << "\n";
}

void Cookie::printCalories() const
{
	cout << calories << endl;
}
