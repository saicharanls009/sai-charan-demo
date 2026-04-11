// Write a C++ Program to find the area of circle, triangle and rectangle using functions overloading.
#include <iostream>
using namespace std;

double calculateArea(double radius) {
    return 3.14159 * radius * radius;
}

double calculateArea(double length, double width) {
    return length * width;
}

double calculateArea(double base, double height, bool isTriangle) {
    if (isTriangle) {
        return 0.5 * base * height;
    }
    return 0;
}

int main() {
    cout << "Area of Circle: " << calculateArea(5.0) << endl;
    cout << "Area of Rectangle: " << calculateArea(5.0, 10.0) << endl;
    cout << "Area of Triangle: " << calculateArea(6.0, 4.0, true) << endl;

    return 0;
}