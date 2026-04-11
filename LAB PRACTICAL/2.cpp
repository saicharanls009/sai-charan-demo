// Write a C++ Program for doing arithmetic operations using function that program includes the following functions – Addition, Subtraction, Multiplication, Division and Modulus.
#include <iostream>
using namespace std;
int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Addition
    int sum = num1 + num2;
    cout << "Addition: " << sum << endl;

    // Subtraction
    int difference = num1 - num2;
    cout << "Subtraction: " << difference << endl;

    // Multiplication
    int product = num1 * num2;
    cout << "Multiplication: " << product << endl;

    // Division
    if (num2 != 0) {
        double quotient = static_cast<double>(num1) / num2;
        cout << "Division: " << quotient << endl;
    } else {
        cout << "Division by zero is not allowed." << endl;
    }

    // Modulus
    if (num2 != 0) {
        int modulus = num1 % num2;
        cout << "Modulus: " << modulus << endl;
    } else {
        cout << "Modulus by zero is not allowed." << endl;
    }

    return 0;
}