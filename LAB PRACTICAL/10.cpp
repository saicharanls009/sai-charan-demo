 //Write a C++ Program to show access to Private Public and Protected using Inheritance.
#include<iostream>
using namespace std;

class Base{
    private:
    int privateVar = 10;
    protected:
    int protectedVar = 20;
    public:
    int publicVar = 30;
    int getprivateVar()
    {
        return privateVar;
    }
};
class Derived : public  Base{
    public:
    void display(){
        cout << "Private Variable:"<< getprivateVar()<<endl;
        cout << "Protected variable:"<< protectedVar<<endl;
        cout << "Public Variable:"<< publicVar<<endl;
    }
};
int main(){
    Derived obj;
    obj.display();


    cout << "Public Variable from Main:"<< obj.publicVar<<endl;
    return 0;
    
}