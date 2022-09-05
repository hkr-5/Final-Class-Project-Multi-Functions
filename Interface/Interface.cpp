/* 
    Yamamoto, Hikaru
              
    May 27, 2021
              
    CS A250
    Project 2
*/
/*
    1. The name of your new selection: Allergen check
    2. What your new selection does:
        It prints cookie names that do not contain selected allergen
        with the ingredients. Selections are: milk, walnuts, eggs, 
        flour, and peanuts. (Selected based on 8 major food 
        allergens.) Assumed list is not empty.
    3. What the expected output:
        All cookie names that do not contain selected allergen and
        the cookies' ingredients. If no cookies contain selected 
        allergen, print message "No cookies contain allergen!".
        If all cookies contain the allergen, print message
        "We couldn't find cookies that do not contain allergen.".
    4. Which test cases you used:
        - test allergen is walnuts
        - test allergen is eggs
        - test allergen is flour
        - test allergen is peanuts
        - test allergen is milk, but no cookies contain milk
        - test allergen is flour, but all cookies contain flour
*/

#include "Interface.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu() {
        string star(62, '*');
        string space(24, ' ');
        cout << star << endl
            << space << "COOKIE RECIPES" << endl
            << star << endl
            << endl << "Select one of the following:" << endl
            << endl << "    a. Print all recipes" << endl
            << "    b. Print cookie recipe" << endl
            << "    c. Print cookie calories" << endl
            << "    d. Print limited calories" << endl
            << "    e. Allergen check" << endl
            << "    f. To exit" << endl;
}

void processChoice(CookieList& cookieList) {
    bool loop = true;
    char choice = 'a';
    string doubleLine(62, '=');

    while(loop) {
        displayMenu();
        cout << endl << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        string line(62, '-');
        
        switch(choice) {
            case 'a': {
                if(cookieList.isEmpty()) {
                    cout << "  => "
                        << "There are no recipes in the list."
                        << endl;
                    loop = false;
                }
                else {
                    cout << line << endl 
                        << "    COOKIE RECIPES" << endl
                        << line << endl << endl;
                    cookieList.printAllCookies();
                }
                break;
            }

            case 'b': {
                cout << line << endl 
                    << "    COOKIE RECIPE" << endl
                    << line << endl << endl
                    << "Choose a cookie to view the recipe." 
                    << endl << endl;
                cookieList.printCookiesSelection();
                size_t choiceB;
                cin >> choiceB;
                cout << endl;
                cookieList.printRecipe(choiceB);
                break;
            }

            case 'c': {
                cout << line << endl 
                    << "    COOKIE CALORIES" << endl
                    << line << endl << endl
                    << "Choose a cookie # "
                    << "to view number of calories." 
                    << endl << endl;
                cookieList.printCookiesSelection();
                size_t choiceC;
                cin >> choiceC;
                cout << endl;
                cookieList.printCalories(choiceC);
                break;
            }

            case 'd': {
                cout << line << endl 
                    << "    MAXIMUM CALORIES" << endl
                    << line << endl << endl
                    << "What is the maximum # of calories "
                    << "(100-200)? ";
                size_t maxCalories;
                cin >> maxCalories;
                cout << endl;
                cookieList.printLimitedCalories(maxCalories);
                break;
            }

            case 'e': {
                cout << line << endl 
                    << "    ALLERGEN CHECK" << endl
                    << line << endl << endl
                    << "Select your allergen "
                    << "(walnuts, eggs, flour, or peanuts): ";
                string allergen;
                cin >> allergen;
                cout << endl;
                cookieList.printAllergen(allergen);
                break;
            } 

            case 'f': {
                loop = false;
                break;
            }

            default: {
                cout << "  => Sorry. That is not a selection." 
                    << endl;
                break;
            }
        }

        if(loop) {
            cout << endl << doubleLine << endl << endl;
            if(choice == 'a' || choice == 'b' || choice == 'c' 
                || choice == 'd' || choice == 'e')
                cout << "Would you like to continue (y/n)? ";
            else
                cout << "Would you like to try again (y/n)? ";
            char temp = 'y';
            cin >> temp;
            loop = (temp == 'n') ? false : true;
            cout << endl;
        }
    }

    if(cookieList.isEmpty())
        cout << endl << doubleLine << endl << endl
            << "Please contact your administrator. ";
    else
        cout << "Thank you for using our software. ";
    cout << "Good bye!" << endl;
}