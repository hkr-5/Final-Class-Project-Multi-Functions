/*        
    Yamamoto, Hikaru
              
    May 19, 2021
              
    CS A250
    Project 2
*/

#include <iostream>

#include "./Cookie/Cookie.h"
#include "./Testing/Testing.h"
#include "./CookieDB/CookieDB.h"
#include "./Interface/Interface.h"
#include "./CookieList/CookieList.h"
#include "./CookieType/CookieType.h"
#include "./Cookie/Cookie.cpp"
#include "./Testing/Testing.cpp"
#include "./CookieDB/CookieDB.cpp"
#include "./Interface/Interface.cpp"
#include "./CookieList/CookieList.cpp"
#include "./CookieType/CookieType.cpp"

using namespace std;

int main() {
    CookieList ourList;
    createCookieList(ourList);
    displayMenu();
    ourList.printAllCookies();
    processChoice(ourList);

    CookieList mine(ourList);
    processChoice(mine);

/*
    CookieType a;
    CookieType b("Red", 250);
    cout << b.getCalories() << " " << b.getName() << endl;
    a.setCalories(300);
    a.setName("Blue");
    cout << a.getCalories() << " " << a.getName() << endl;

    set<string> ingredientsD;
    ingredientsD.insert("egg");
    ingredientsD.insert("milk");
    Cookie c;
    Cookie d("yellow", 320, ingredientsD, 10);
    auto iter = d.getIngredients().begin();
    iter++;
    cout << *iter << " " << endl;
    d.printRecipe();
    d.printIngredients();
    d.printCalories();

   CookieList myList;
   CookieList yourList;
   //createCookieList(myList);
   set<string> ingredientsD;
    ingredientsD.insert("egg");
    ingredientsD.insert("milk");
   Cookie test;
   myList.addCookie(test);
   myList.addCookie("test", 330, ingredientsD, 20);
   yourList = myList;

   createCookieList(yourList);
   //yourList.printAllCookies();
   CookieList herList(yourList);
   herList.printAllCookies();
   cout << endl;
   yourList.printAllCookies();
*/
    return 0;
}