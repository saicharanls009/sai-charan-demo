#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    // Constructor
    Complex() : real(0), imag(0) {}

    // Input function
    void input() {
        cout << "Enter real and imaginary parts: ";
        cin >> real >> imag;
    }

    // Output function
    void output() {
        cout << real << " + " << imag << "i" << endl;
    }

    // Friend function declaration
    friend Complex addComplex(Complex c1, Complex c2);
};

// Friend function definition
Complex addComplex(Complex c1, Complex c2) {
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

// Main function
int main() {
    Complex c1, c2, result;

    cout << "Enter first complex number:\n";
    c1.input();

    cout << "Enter second complex number:\n";
    c2.input();

    result = addComplex(c1, c2);

    cout << "Sum of complex numbers:\n";
    result.output();

    return 0;
}