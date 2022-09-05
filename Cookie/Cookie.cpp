/*
    Yamamoto, Hikaru
              
    May 19, 2021
              
    CS A250
    Project 2
*/

#include "Cookie.h"

using namespace std;

Cookie::Cookie() {
    servings = 0;
}

Cookie::Cookie(const string& myName, size_t myCalories, 
    const set<string>& myIngredients, size_t myServings)
        :CookieType(myName, myCalories) {
    ingredients = myIngredients;
    servings = myServings;
}

size_t Cookie::getServings() const {
    return servings;
}

set<string> Cookie::getIngredients() const {
    return ingredients;
}

const Cookie& Cookie::getCookie() const {
    return *this;
}

void Cookie::setServings(size_t myServings) {
    servings = myServings;
}

void Cookie::setIngredients(const vector<string>& myIngredients) {
    ingredients.clear();
    ingredients.insert(myIngredients.begin(), myIngredients.end());
}

void Cookie::printRecipe() const {
    cout << "    Recipe for " << getName() << endl 
        << "        Servings: " << servings << endl;
}

void Cookie::printIngredients() const {
    auto iter = ingredients.begin();
    auto iterEnd = ingredients.end();
    cout << "        Ingredients: ";

    while(iter != iterEnd) {
        cout << *iter;
        ++iter;
        if(iter != iterEnd)
            cout << ", ";
    }
    cout << endl;
}

void Cookie::printCalories() const {
    cout << "    " << getName() 
        << " (calories: " << getCalories() << ")" << endl;
}