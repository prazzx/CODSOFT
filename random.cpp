#include <iostream>
#include<time.h>
#include <cstdlib>  
using namespace std;

int main() {
    srand(time(0)); // random seed
    int number = rand() % 100 + 1; // random num 1 to 100
    int guess;

    cout << "  pick a number between 1 and 100.\n";
    cout << "Can you guess it?)\n";

    while (true) {  // infinite loop till correct guess
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < number) {
            cout << " Too low.\n";
        } else if (guess > number) {
            cout << "Too high.\n";
        } else {
            cout << " you gussed it right the number was " << number << "!\n";
            break;  // exit loop
        }
    }

    cout << "the end \n";
    return 0;
}
