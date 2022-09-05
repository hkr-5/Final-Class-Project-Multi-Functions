/*
    Raisin
              
    Yamamoto, Hikaru
              
    May 19, 2021
              
    CS A250
    Project 2
*/

#ifndef COOKIELIST_H
#define COOKIELIST_H

#include "../CookieType/CookieType.h"
#include "../Cookie/Cookie.h"

#include <iostream>
#include <string>
#include <list>

class CookieList
{
public:
	// Constructors
	CookieList();
	
	// Function addCookie
	void addCookie(const Cookie& aCookie);
	void addCookie(const std::string& newName, size_t newCalories,
		const std::set<std::string>& newIngredients, 
		size_t newServings);

	// Accessor function
	size_t getCount() const;

	// Boolean functions
	bool isEmpty() const;

	// Print functions
	void printAllCookies() const;

	// Function clearList
	void clearList();

	// The Big Three
	CookieList(const CookieList& otherCookieList);
	CookieList& operator=(const CookieList& otherCookieList);		
	~CookieList();

	// Another Print Functions
	void printCookiesSelection() const;
	void printRecipe(size_t location) const;
	void printCalories(size_t location) const;
	void printLimitedCalories(size_t maxCalories) const;
	void printAllergen(const std::string& allergen) const;

private:
	std::list<Cookie>* cookieList;
};

#endif
