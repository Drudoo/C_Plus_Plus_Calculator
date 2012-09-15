//
//  Copyright 2012 the original author or authors.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
//
//  main.cpp
//  Calculator
//
//  Created by Frederik Vanggaard on 9/14/12.
//
//  Contact: contact@drudoo.com
//
//

#include <iostream> //Added for In / Out support. We are able to use cin and cout.
#include <math.h> //Added for the calculations.
#include "time.h" //Added for random number (sran)

using namespace std; //Using the standard namespace.

int main() { //Main function for C++ program.
    
    char keyPress, keyPressRandom; //Char variables for letters such as 'a' and '+'.
    
    int decimalNumber(0); /* ,withoutRemainder(0);*/ //Int for whole numbers such as '1' and '12'
    
    double numberOne; //Double for numbers from 10^-308 to to^308, including decimal numbers.

    long double number_on_screen; //Long double for numbers from 10^-4932 to 10^4932 including decimals.
    
    cout << "*********************************************************************************\n";
    cout << "*                                                                               *\n";
    cout << "*                       Welcome to calculator Awesome!                          *\n"; //Welcome statement is printed to screen.
    cout << "*                                                                               *\n";
    cout << "*********************************************************************************\n";
    
    cout << "\nIf the result is a decimal number how many decimals do you want after the comma?\n";
    
    cin >> decimalNumber;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(decimalNumber);
    
    cout << "\nDo you want to start with a random number from 0+100?\n"
         << "y or n\n";
    
    cin >> keyPressRandom;
    
    srand(time(NULL));
    
    switch (keyPressRandom) {
        case 'y':
        case 'Y':
            number_on_screen = rand()%100;
            break;
        case 'n':
        case 'N':
            number_on_screen = (0.0);
            break;
        default:
            break;
    }
    
    cout << "Choose what you want to do:\n"
         << "Press + for +\n"
         << "Press - for -\n"
         << "Press * for *\n"
         << "Press / for /\n"
         << "Press % for %\n"
         << "Press s for sin\n"
         << "Press c for cos\n"
         << "Press t for tan\n"
         << "Press r for square root\n"
         << "Press ^ for Y in the power of X\n"
         << "Press d for delete remainder\n"
         << "Press e for clear\n\n"
         << "[[ ";
    
    cout.width(20);
        
    cout << right << number_on_screen << " ]] \n";
    
    
    do {
        
        cin >> keyPress;

        switch (keyPress) {
            case '+':
                cin >> numberOne;
                number_on_screen = number_on_screen + numberOne;
                break;
            
            case '-':
                cin >> numberOne;
                number_on_screen = number_on_screen - numberOne;
                break;

            case '*':
                cin >> numberOne;
                number_on_screen = number_on_screen * numberOne;
                break;
                
            case '/':
                cin >> numberOne;
                number_on_screen = number_on_screen / numberOne;
                break;
                
            case '%': 
                cin >> numberOne;
                number_on_screen = int(number_on_screen) % int(numberOne);
                break;
            
            case 's':
                number_on_screen = sin(number_on_screen);
                break;
                
            case 'c':
                number_on_screen = cos(number_on_screen);
                break;
                
            case 't':
                number_on_screen = tan(number_on_screen);
                break;
                
            case 'r':
                number_on_screen = sqrt(number_on_screen);
                break;
                
            case '^':
                cin >> numberOne;
                number_on_screen = pow(number_on_screen, numberOne);
                break;
                
            case 'd': 
                number_on_screen = double(int(number_on_screen));
                
//                withoutRemainder = number_on_screen;
//                double(number_on_screen) = withoutRemainder;
                break;
            
            
            case 'e':
                number_on_screen=0;
                break;
                
                
            default:
                
                if (keyPress == 'q') {
                    cout << "Exitting!\n\n";
                }
                
                else {
                    cout << "Choose what you want to do:\n"
                    << "Press + for +\n"
                    << "Press - for -\n"
                    << "Press * for *\n"
                    << "Press / for /\n"
                    << "Press % for %\n"
                    << "Press s for sin\n"
                    << "Press c for cos\n"
                    << "Press t for tan\n"
                    << "Press r for square root\n"
                    << "Press ^ for Y in the power of X\n"
                    << "Press d for delete remainder\n"
                    << "Press e for clear\n";
                }
                
                break;
        }
        
//        if (keyPress == 'd') {
//            number_on_screen = withoutRemainder;
//        }
     
        if (keyPress !='q') {
            cout << "\n[[ ";
            cout.width(20);
            cout << right << double(number_on_screen) << " ]] \n";
        }
                
    } while (keyPress !='q');

    number_on_screen=0.0;
    
    cout << "[[ ";
    cout.width(20);
    cout << right << number_on_screen << " ]] \n";
    
}