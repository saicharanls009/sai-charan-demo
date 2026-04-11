#include <iostream>
using namespace std;

// Abstract Base Class
class Shape {
public:
    virtual void area() = 0;
    virtual void perimeter() = 0;
    virtual void display() = 0;

    virtual ~Shape() {}
};

// Circle Class
class Circle : public Shape {
    double r;
public:
    Circle(double radius) { r = radius; }

    void area() {
        cout << "Area: " << 3.14 * r * r << endl;
    }

    void perimeter() {
        cout << "Perimeter: " << 2 * 3.14 * r << endl;
    }

    void display() {
        cout << "Shape: Circle | Radius: " << r << endl;
    }
};

// Rectangle Class
class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double length, double width) {
        l = length; w = width;
    }

    void area() {
        cout << "Area: " << l * w << endl;
    }

    void perimeter() {
        cout << "Perimeter: " << 2 * (l + w) << endl;
    }

    void display() {
        cout << "Shape: Rectangle | L: " << l << " W: " << w << endl;
    }
};

// Triangle Class
class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double x, double y, double z) {
        a = x; b = y; c = z;
    }

    void area() {
        double s = (a + b + c) / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        cout << "Area: " << area << endl;
    }

    void perimeter() {
        cout << "Perimeter: " << a + b + c << endl;
    }

    void display() {
        cout << "Shape: Triangle | Sides: " << a << "," << b << "," << c << endl;
    }
};

// Main Function
int main() {
    Shape* shapes[100];
    int count = 0;

    int choice;

    do {
        cout << "\n--- Shape Menu ---\n";
        cout << "1. Add Circle\n";
        cout << "2. Add Rectangle\n";
        cout << "3. Add Triangle\n";
        cout << "4. Display All Shapes\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            shapes[count++] = new Circle(r);
        }
        else if (choice == 2) {
            double l, w;
            cout << "Enter length and width: ";
            cin >> l >> w;
            shapes[count++] = new Rectangle(l, w);
        }
        else if (choice == 3) {
            double a, b, c;
            cout << "Enter 3 sides: ";
            cin >> a >> b >> c;
            shapes[count++] = new Triangle(a, b, c);
        }
        else if (choice == 4) {
            cout << "\n--- All Shapes ---\n";
            for (int i = 0; i < count; i++) {
                shapes[i]->display();
                shapes[i]->area();
                shapes[i]->perimeter();
                cout << endl;
            }
        }

    } while (choice != 5);

    // Cleanup
    for (int i = 0; i < count; i++) {
        delete shapes[i];
    }

    return 0;
}