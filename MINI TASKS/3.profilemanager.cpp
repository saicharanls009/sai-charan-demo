#include <iostream>
using namespace std;

class Student {
private:
    string rollNo;
    string name;
    int age;
    string course;
    float cgpa;
    string hostel;
    string grade;

public:
    // Constructor
    Student(string r, string n, int a, string c, float cg, string h) {
        rollNo = r;
        name = n;
        age = a;
        course = c;
        cgpa = cg;
        hostel = h;

        // Grade Calculation
        if (cgpa >= 9)
            grade = "O";
        else if (cgpa >= 8)
            grade = "A";
        else if (cgpa >= 7)
            grade = "B";
        else if (cgpa >= 6)
            grade = "C";
        else if (cgpa >= 5)
            grade = "D";
        else
            grade = "F";
    }

    void display() {
        cout << "\n----- Student Profile -----" << endl;
        cout << "Roll No : " << rollNo << endl;
        cout << "Name    : " << name << endl;
        cout << "Age     : " << age << endl;
        cout << "Course  : " << course << endl;
        cout << "CGPA    : " << cgpa << endl;
        cout << "Grade   : " << grade << endl;
        cout << "Hostel  : " << hostel << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    Student* students[n];

    for (int i = 0; i < n; i++) {

        string roll, name, course, hostel;
        int age;
        float cgpa;

        cout << "\nEnter details for Student " << i + 1 << endl;

        // Roll number validation using for loop
        for (;;) {
            cout << "Enter 10-digit Roll No: ";
            cin >> roll;

            if (roll.length() == 10)
                break;
            else
                cout << "Invalid! Roll number must be exactly 10 digits.\n";
        }

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Course: ";
        getline(cin, course);

        // CGPA validation using for loop
        for (;;) {
            cout << "Enter CGPA (0 - 10): ";
            cin >> cgpa;

            if (cgpa >= 0 && cgpa <= 10)
                break;
            else
                cout << "Invalid CGPA! Enter between 0 and 10.\n";
        }

        cout << "Hostel (Yes/No): ";
        cin >> hostel;

        students[i] = new Student(roll, name, age, course, cgpa, hostel);
    }

    cout << "\n===== All Student Profiles =====" << endl;

    for (int i = 0; i < n; i++) {
        students[i]->display();
    }

    return 0;
}