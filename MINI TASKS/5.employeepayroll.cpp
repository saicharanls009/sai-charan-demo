#include <iostream>
using namespace std;

// Base Class
class Employee {
protected:
    string name;
    int id;
    double baseSalary;

public:
    Employee(string n, int i, double salary) {
        name = n;
        id = i;
        baseSalary = salary;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }

    double calculateSalary() {
        return baseSalary;
    }
};

// Derived Class: Manager
class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string n, int i, double salary, double b)
        : Employee(n, i, salary) {
        bonus = b;
    }

    double calculateSalary() {   // overriding
        return baseSalary + bonus;
    }

    void displayManager() {
        displayDetails();
        cout << "Role: Manager\n";
        cout << "Total Salary: " << calculateSalary() << endl;
    }
};

// Derived Class: Developer
class Developer : public Employee {
private:
    double overtimePay;

public:
    Developer(string n, int i, double salary, double ot)
        : Employee(n, i, salary) {
        overtimePay = ot;
    }

    double calculateSalary() {   // overriding
        return baseSalary + overtimePay;
    }

    void displayDeveloper() {
        displayDetails();
        cout << "Role: Developer\n";
        cout << "Total Salary: " << calculateSalary() << endl;
    }
};

// Main Function
int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    // Arrays of objects (fixed size for simplicity)
    Manager* managers[100];
    Developer* developers[100];

    int mCount = 0, dCount = 0;

    for (int i = 0; i < n; i++) {
        int choice;
        string name;
        int id;
        double salary;

        cout << "\nEmployee " << i + 1 << endl;
        cout << "1. Manager\n2. Developer\nChoose role: ";
        cin >> choice;

        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Base Salary: ";
        cin >> salary;

        if (choice == 1) {
            double bonus;
            cout << "Enter Bonus: ";
            cin >> bonus;

            managers[mCount++] = new Manager(name, id, salary, bonus);
        }
        else if (choice == 2) {
            double overtime;
            cout << "Enter Overtime Pay: ";
            cin >> overtime;

            developers[dCount++] = new Developer(name, id, salary, overtime);
        }
        else {
            cout << "Invalid choice!\n";
            i--; // retry
        }
    }

    // Display All
    cout << "\n===== Employee Details =====\n";

    cout << "\n--- Managers ---\n";
    for (int i = 0; i < mCount; i++) {
        managers[i]->displayManager();
        cout << endl;
    }

    cout << "\n--- Developers ---\n";
    for (int i = 0; i < dCount; i++) {
        developers[i]->displayDeveloper();
        cout << endl;
    }

    return 0;
}