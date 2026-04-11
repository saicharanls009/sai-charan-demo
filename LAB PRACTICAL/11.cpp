//Write a C++ Program to show access to Private Public and Protected using Inheritance.

#include <iostream>
using namespace std;

class Animal{
    public:
    virtual void sound(){
        cout << "This is a generic animal sound"<< endl;
        }
};
class Dog : public Animal{
    public:
    void sound()override{
        cout << "The dog saya: Woof Woof!\n";
    }
};
class Cat : public Animal{
    public:
    void sound() override{
        cout << "The cat says : Meow Meow!\n";
    
    }
};
int main(){
    Animal* animalptr;
    Dog dog;
    Cat cat;
    animalptr = &dog;
    animalptr ->sound();
    animalptr = &cat;
    animalptr ->sound();
    return 0;
}