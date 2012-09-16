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
    
    double numberOne; //Double for numbers from 10^-308 to to 10^308, including decimal numbers.

    long double number_on_screen; //Long double for numbers from 10^-4932 to 10^4932 including decimals.
    
    cout << "*********************************************************************************\n";
    cout << "*                                                                               *\n";
    cout << "*                       Welcome to calculator Awesome!                          *\n"; //Welcome statement is printed to screen.
    cout << "*                                                                               *\n";
    cout << "*********************************************************************************\n";
    
    cout << "\nIf the result is a decimal number how many decimals do you want after the comma?\n"; //Asks the user how many decimals it want.
    
    cin >> decimalNumber; //User input for number fo decimals. Stored as int since you cant have half a decimal.
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);      //Choose how many decimals we want.
    cout.precision(decimalNumber);  //Number in brackets (decimalNumber) chooses the number of decimals we want.
    
    cout << "\nDo you want to start with a random number from 0+100?\n" //Let the user have a random number from 0 to 100 to start with.
         << "y or n\n";
    
    cin >> keyPressRandom;  //Regristrer the userinput for y or n.
    
    srand(time(NULL));  //Using sran to get a better random, so we are not stuck with the same random number each time we run the program.
    
    switch (keyPressRandom) {   //Switch statement for checking if the user want a random number or not.
        case 'y':   //User is able to choose lowercase y or uppercase Y for yes.
        case 'Y':
            number_on_screen = rand()%100; //The number_on_screen is set to a random number from 0-100.
            break;
        case 'n':   //User is able to choose lowercase n or uppercase N for no.
        case 'N':
            number_on_screen = (0.0); //The number_on_screen is set to 0, with decimals matching the number chosen earlier.
            break;
        default:
            cout << "Choose y for yes, n for no\n"; //If the user does not choose any of the options it is promted with this message.
            break;
    }
    
    cout << "Choose what you want to do:\n" //Writes to the user what is possible with this calculator.
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
    
    cout.width(20); //We want the next line of text in cout to be 20 places away.
        
    cout << right << number_on_screen << " ]] \n"; //We choose the right side and print out number to the right.
    
    
    do { //Created a do-while loop to run as long as the user does not press q (for quit).
        
        cin >> keyPress; //Checks the user input. 

        switch (keyPress) { //Switch statement for each math operator.
            case '+': //If the user press + 
                cin >> numberOne; //User input
                number_on_screen = number_on_screen + numberOne; //The number on the screen is added to the user input and displayed on the screen.
                break;
            
            case '-': //If the user press -
                cin >> numberOne; //User input
                number_on_screen = number_on_screen - numberOne; //The number on the screen is substracted with the user input and displayed on the screen.
                break;

            case '*': //If the user press *
                cin >> numberOne; //User input
                number_on_screen = number_on_screen * numberOne; //The number on the screen is multiplied with the user input and displayed on the screen.
                break;
                
            case '/': //If the user press /
                cin >> numberOne; //User input
                number_on_screen = number_on_screen / numberOne; //The number on the screen is divided with the user input and displayed on the screen.
                break;
                
            case '%':  //If the user press %
                cin >> numberOne; //User input
                number_on_screen = int(number_on_screen) % int(numberOne); //We cant use double with modulus so we convert the numbers to int, thereby removing their decimals. The number on the screen is divided with the user input and the rest is displayed on the screen.
                break;
            
            case 's': //If the user press s
                number_on_screen = sin(number_on_screen); //We take sine of the number on the screen.
                break;
                
            case 'c': //If the user press c
                number_on_screen = cos(number_on_screen); //We take cosine of the number on the screen.
                break;
                
            case 't': //If the user press t
                number_on_screen = tan(number_on_screen);  //We take tangent of the number on the screen.
                break;
                
            case 'r': //If the user press r
                number_on_screen = sqrt(number_on_screen); //We take the squareroot of the number on the screen.
                break;
                
            case '^': //If the user press ^
                cin >> numberOne; //User input
                number_on_screen = pow(number_on_screen, numberOne); //We take the number on the screen in the power of the user input.
                break;
                
            case 'd':  //If the user press d
                number_on_screen = double(int(number_on_screen)); //If the number on the screen have decimals. We remove those decimals without rounding up or down.
                                                                  //This is done by first converting out number to an int, thereby removing the deciamls and then
                                                                  //converting back to double, adding .00 as decimals.
                break;
            
            
            case 'e': //If the user press e
                number_on_screen=0; //Replace the number on the screen with 0.
                break;
                
                
            default: //If the user does none of the above.
                
                if (keyPress == 'q') { //If the user press q
                    cout << "Exiting!\n"; //Exiting is printed out to the screen.
                }
                
                else { //Else print out what can be pressed.
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
     
        if (keyPress !='q') { //If q is not pressed then we print out display.
            cout << "\n[[ "; //First square brackets
            cout.width(20); //Move the number 20 steps to the right.
            cout << right << number_on_screen << " ]] \n"; //Print the number on the screen and close the brackets.

        }
                
    } while (keyPress !='q'); //Our do-while loop will quit when the user press q.
    
}