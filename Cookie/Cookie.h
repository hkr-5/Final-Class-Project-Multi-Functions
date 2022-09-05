/*
    Raisin
              
    Yamamoto, Hikaru
              
    May 19, 2021
              
    CS A250
    Project 2
*/

#ifndef COOKIE_H
#define COOKIE_H

#include "../CookieType/CookieType.h"
#include <string>
#include <set>
#include <vector>

class Cookie : public CookieType {
public:
    Cookie();
    Cookie(const std::string& myName, size_t myCalories,
        const std::set<std::string>& myIngredients, 
        size_t myServings);

    size_t getServings() const;
    std::set<std::string> getIngredients() const;
    const Cookie& getCookie() const;

    void setServings(size_t myServings);
    void setIngredients(
        const std::vector<std::string>& myIngredients);

    void printRecipe() const;
    void printIngredients() const;
    void printCalories() const;

    ~Cookie() {}

private:
    std::set<std::string> ingredients;
    size_t servings;
};

#endif