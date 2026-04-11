//Write a C++ Program to illustrate the use of pure virtual function in Polymorphism.

#include <iostream>
using namespace std;

class Shape{
    public:
    virtual void draw()=0;
};
class Circle :  public Shape{
    public:
    void draw()override{
        cout << "Drawing a circle\n";
    }
};
class Rectangle : public Shape {
    public:
    void draw() override {
        cout << "Drawing a Recangle ";
    }
};
int main(){
    Shape* shape;
    Circle circle;
    Rectangle rectangle;
    shape = &circle;
    shape -> draw();
    shape = &rectangle;
    shape ->draw();
    return 0;

}
