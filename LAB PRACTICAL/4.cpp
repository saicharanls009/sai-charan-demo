//Write a C++ program to add two integers using class.
#include <iostream>
using namespace std;

class Adder {
public:
    int add(int a, int b) {
        return a + b;
    }
};

int main() {
    Adder adder;
    int num1, num2;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    int result = adder.add(num1, num2);
    cout << "The sum of " << num1 << " and " 
    << num2 << " is: " << result << endl;

    return 0;
}
