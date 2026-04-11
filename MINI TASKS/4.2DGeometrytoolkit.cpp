#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Point
{
    int x,y;

public:

    Point(int a=0,int b=0)
    {
        x=a;
        y=b;
    }

    Point operator+(Point p)
    {
        return Point(x+p.x , y+p.y);
    }

    Point operator-(Point p)
    {
        return Point(x-p.x , y-p.y);
    }

    void display()
    {
        cout<<"("<<x<<","<<y<<")";
    }

    int getX(){return x;}
    int getY(){return y;}
};

class Line
{
    Point p1,p2;

public:

    Line(Point a,Point b)
    {
        p1=a;
        p2=b;
    }

    float length()
    {
        return sqrt(pow(p2.getX()-p1.getX(),2)+pow(p2.getY()-p1.getY(),2));
    }

    Point midpoint()
    {
        return Point((p1.getX()+p2.getX())/2 , (p1.getY()+p2.getY())/2);
    }

    float slope()
    {
        return (float)(p2.getY()-p1.getY())/(p2.getX()-p1.getX());
    }
};

int main()
{
    cout<<"\n=====================================\n";
    cout<<"        2D GEOMETRY TOOLKIT\n";
    cout<<"=====================================\n\n";

    Point p1(4,6);
    Point p2(2,3);

    cout<<"Points Information\n";
    cout<<"-------------------------------------\n";

    cout<<"Point 1 : ";
    p1.display();

    cout<<"\nPoint 2 : ";
    p2.display();

    cout<<"\n\nOperations on Points\n";
    cout<<"-------------------------------------\n";

    Point sum = p1 + p2;
    cout<<"Addition of Points : ";
    sum.display();

    Line L(p1,p2);

    cout<<"\nLength of Line     : "<<fixed<<setprecision(2)<<L.length();
    cout<<"\nSlope of Line      : "<<L.slope();

    cout<<"\nMidpoint of Line   : ";
    L.midpoint().display();

    cout<<"\n\n=====================================\n";
    cout<<"        Calculation Completed\n";
    cout<<"=====================================\n";

}