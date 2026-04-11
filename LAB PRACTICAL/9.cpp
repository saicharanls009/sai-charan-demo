//Write a C++ Program for Enter Patient details   Inheritance.

#include<iostream>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;
    string gender;

public:
    void enterDetails() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

// Derived Class
class Patient : public Person {
private:
    string disease;
    string doctor;

public:
    void enterPatientDetails() {
        enterDetails(); // call base class function
        cout << "Enter Disease: ";
        cin >> disease;
        cout << "Enter Doctor Assigned: ";
        cin >> doctor;
    }

    void displayPatientDetails() {
        displayDetails(); // call base class function
        cout << "Disease: " << disease << endl;
        cout << "Doctor Assigned: " << doctor << endl;
    }
};

// Main Function
int main() {
    Patient p;

    cout << "Enter Patient Details:\n";
    p.enterPatientDetails();

    cout << "\nPatient Details:\n";
    p.displayPatientDetails();

    return 0;
}