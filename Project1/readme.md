Project (Part B1)

Implementation of the CookieList Class	(Ryan)

These are the functions we need to implement in the CookieList class:

Default constructor (Lily)
	Use a member initializer list constructor to initialize the member variables to default values.

Function addCookie (Jordan)
	Parameter: an object of the Cookie class.
	Inserts a new node at the end of the list.

Function addCookie (overloaded) (Maha)
	Parameters (in this order): a string storing the cookie name, a variable of size_t storing the number of calories, a variable of size_t storing the number of servings, and an STL set of type string storing all ingredients, and Inserts a new node at the end of the list.

Function getCount (Ryan)
	Returns the number of nodes in the list.

Function isEmpty (Lily)
	Returns true if the list is empty and false otherwise.

Function searchCookie (Jordan)
	Parameter: a string storing a cookie name.
	Traverses the list and returns true if the cookie is in the list and false otherwise. Make sure you exit the loop as soon as the cookie is found. How can you do that? Which type of loop should you use?
	Assumption: The list is non-empty.

Function printAllCookies (Maha)
	Prints all cookies by name. Do not worry about other printing details; those will be addressed later.

Function clearList (Ryan)
	Deletes all the nodes in the list and resets the member variables to their default value. Note that the object still exists; you are just emptying it by deleting the nodes. 

Destructor (Lily)
	If the list is not empty, it calls the clearList function.

Copy constructor (Jordan)
	Parameter: an object of the CookieList class.
	Using the member function addCookie() that passes a Cookie object, copy each Cookie object from the parameter list into the calling list. Do NOT forget that this is a constructor. What does this mean? It means that you need to initialize the member variables before you can start copying.

Overloaded assignment operator (Maha)
	Parameter: an object of the CookieList class
		Go back to the Big Three lesson to see how this function should be implemented. What is the return value? What else do you need to consider?
		The required implementation is not optimal in terms of efficiency. The best way to do this would be copying the data into the calling object’s existing nodes, and then either delete unneeded nodes (when the parameter list is shorter than the calling list), or add more nodes (when the parameter list is longer than the calling list). 
