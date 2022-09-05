/*        
    Yamamoto, Hikaru
              
    May 19, 2021
              
    CS A250
    Project 2
*/

#include "CookieList.h"
#include <algorithm>

using namespace std;

CookieList::CookieList() {
    cookieList = new list<Cookie>;
}
	
void CookieList::addCookie(const Cookie& aCookie) {
    cookieList->push_back(aCookie);
}

void CookieList::addCookie(const string& newName, 
    size_t newCalories, const set<string>& newIngredients,
    size_t newServings) {
    Cookie temp(newName, newCalories, newIngredients, newServings);
    cookieList->push_back(temp);
}

size_t CookieList::getCount() const {
    return cookieList->size();
}

bool CookieList::isEmpty() const {
    return cookieList->empty();
}

void CookieList::printAllCookies() const {
    for(const auto i : *cookieList)
        cout << "    " << i.getName() << endl;
}

void CookieList::clearList() {
    cookieList->clear();
}

CookieList::~CookieList() {
    delete cookieList;
    cookieList = nullptr;
}

CookieList::CookieList(const CookieList& otherCookieList) {
    cookieList = new list<Cookie>(*otherCookieList.cookieList);
}

CookieList& CookieList::operator=(const CookieList& otherCookieList) {
    if(&otherCookieList != this) 
        *cookieList = *otherCookieList.cookieList;
    else 
        cerr << "Error: attempted self-assignment" << endl;
    return *this;
}

void CookieList::printCookiesSelection() const {
    int number = 1;
    for(const auto i : *cookieList) {
        cout << "    " << number << ": " << i.getName() << endl;
        ++number;
    }
    cout << endl << "Your choice: ";
}

void CookieList::printRecipe(size_t location) const {
    auto iter = cookieList->begin();
    for(int i = 1; i < location; ++i)
        ++iter;

    iter->printRecipe();
    iter->printIngredients();
}

void CookieList::printCalories(size_t location) const {
    auto iter = cookieList->begin();
    for(int i = 1; i < location; ++i)
        ++iter;
    iter->printCalories();
}

void CookieList::printLimitedCalories(size_t maxCalories) const {
    for(const auto i : *cookieList) {
        if(i.getCalories() <= maxCalories)
            i.printCalories();
    }
}

void CookieList::printAllergen(const string& allergen) const {
    cout << "Cookie(s) without " << allergen << ": " << endl;
    int numberOfCookies = 0;
    for(const auto i : *cookieList) {
        if(i.getIngredients().count(allergen) == 0) {
            cout << "- " << i.getName() << endl;
            i.printIngredients();
            ++numberOfCookies;
        }
    }

    if(numberOfCookies == 0)
        cout << "We couldn't find cookies that do not contain "
            << allergen  << "." << endl;
    else if(numberOfCookies == getCount())
        cout << endl << "No cookies contain " 
            << allergen << "!" << endl;
}