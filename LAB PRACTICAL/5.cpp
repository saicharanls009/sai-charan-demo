//Write a C++ code for read and print student information using class.

#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
    string grade;
    void readInfo() {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter student age: ";
        cin >> age;
        cin.ignore(); // To ignore the newline character after age input
        cout << "Enter student grade: ";
        getline(cin, grade);
    }
    void printInfo() {
        cout << "Student Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }
};  
int main() {
    Student student;
    student.readInfo();
    student.printInfo();
    return 0;
}