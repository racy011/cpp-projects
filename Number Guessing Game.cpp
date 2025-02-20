#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));                // Seed the random number generator
    int secret = rand() % 100 + 1;   // Random number between 1 and 100
    int guess;

    cout << "Guess the number between 1 and 100!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        if(guess > secret)
            cout << "Too high!" << endl;
        else if(guess < secret)
            cout << "Too low!" << endl;
        else
            cout << "Congratulations! You guessed the number." << endl;
    } while(guess != secret);

    return 0;
}
