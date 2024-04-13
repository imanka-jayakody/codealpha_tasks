#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // for numeric_limits

using namespace std;

int main() {
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Can you guess what it is?" << endl;

    // Generate a random number between 1 and 100
    srand(time(0));
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    while (true) {
        cout << "Enter your guess (between 1 and 100): ";

        // Input validation: Check if the input is a valid integer
        while (!(cin >> guess)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

        attempts++;

        if (guess < 1 || guess > 100) {
            cout << "Your guess is out of range. Please guess between 1 and 100." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try guessing higher." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try guessing lower." << endl;
        } else {
            cout << "Congratulations! You've guessed the correct number " << secretNumber << " in " << attempts << " attempts." << endl;
            break;
        }
    }

    return 0;
}
