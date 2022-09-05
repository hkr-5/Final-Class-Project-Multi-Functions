/*           
    Yamamoto, Hikaru
              
    May 19, 2021
              
    CS A250
    Project 2
*/

#ifndef COOKIETYPE_H
#define COOKIETYPE_H

#include <iostream>
#include <string>

class CookieType {
public:
    CookieType();
    CookieType(const std::string& myName, size_t myCalories);

    std::string getName() const;
    size_t getCalories() const;

    void setName(const std::string& myName);
    void setCalories(size_t myCalories);

    ~CookieType() {}

private:
    std::string name;
    size_t calories;
};

#endif