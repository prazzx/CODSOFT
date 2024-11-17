#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Welcome to My First Calculator!\n";
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    if (operation == '+') {
        cout << "The result is: " << num1 + num2 << endl;
    } else if (operation == '-') {
        cout << "The result is: " << num1 - num2 << endl;
    } else if (operation == '*') {
        cout << "The result is: " << num1 * num2 << endl;
    } else if (operation == '/') {
        if (num2 != 0) {
            cout << "The result is: " << num1 / num2 << endl;
        } else {
            cout << "Error: Division by zero is not allowed.\n";
        }
    } else {
        cout << "Invalid operation. Please try again.\n";
    }

    return 0;
}
