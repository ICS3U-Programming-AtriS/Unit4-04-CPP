// Copyright (c) 2025 Atri Sarker All rights reserved.
// .
// Created By: Atri S
// Date: April 23, 2025
// Random number guessing program
// that keeps on looping until the user guesses the number

#include <iostream>
#include <random>
#include <string>
#include <cstdio>

int main() {
    /*
    # Generate a random number between 0 and 9 [INCLUSIVE] #
    */
    // declare integer to hold random number
    int correctNum;
    // Generate random seed for generator
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    // Integer Range that contains 0-9 [INCLUSIVE]
    std::uniform_int_distribution<int> idist(0, 9);
    // Generate a random number from the range
    correctNum = idist(rgen);

    // LOOP
    while (true) {
        // Get the user's guess as a string
        std::string userInput;
        std::cout << "Enter a number (0-9): ";
        // using getline() since "cin >> userInput" can't handle multiple words
        std::getline(std::cin, userInput);

        try {
            size_t pos;
            // Convert the user's guess to an integer
            // pos will be equal to the length of the input converted
            int userNum = std::stoi(userInput, &pos);

            // REFUSE FLOATS
            if (pos != userInput.length()) {
                throw std::invalid_argument("NO FLOATS");
            }

            // Check if the user's guess is the same as the correct number
            if (userNum == correctNum) {
                // Tell the user that they guessed correctly
                std::cout << "You guessed correctly!\n";
                // Break the Loop
                break;
            } else /*If it isn't, tell the user that they guessed wrong*/ {
                // Tell the user that they guessed wrong
                std::cout << "Wrong! Try again.\n";
            }
        } catch (std::invalid_argument) {
            // Tell the user that their input wasn't an integer
            std::cout << userInput;
            std::cout << " is not an integer. Please try again!\n";
        }
    }
    // Program completion message
    printf("Thanks for playing!\n");
}
