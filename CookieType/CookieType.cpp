/*        
    Yamamoto, Hikaru
              
    May 19, 2021
              
    CS A250
    Project 2
*/

#include "CookieType.h"

using namespace std;

CookieType::CookieType() {
    calories = 0;
}

CookieType::CookieType(const string& myName, size_t myCalories) {
    name = myName;
    calories = myCalories;
}

string CookieType::getName() const{
    return name;
}

size_t CookieType::getCalories() const {
    return calories;
}

void CookieType::setName(const string& myName) {
    name = myName;
}

void CookieType::setCalories(size_t myCalories) {
    calories = myCalories;
}