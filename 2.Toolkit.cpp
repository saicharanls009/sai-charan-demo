#include <iostream>
using namespace std;

#define CUBE(x) ((x) * (x) * (x))

inline int square(int x)
{
    return x * x;
}

// FUNCTION DECLARATIONS
int add(int, int);
int add(int, int, int);  
int power(int, int = 2); 
long long factorial(int);
bool isPrime(int);
int digitSum(int);
void swapNumbers(int &, int &); 

// FUNCTION DEFINITIONS

// Addition (Overloading)
int add(int a, int b)
{
    return a + b;
}

int add(int a, int b, int c)
{
    return a + b + c;
}

// Power
int power(int base, int exp)
{
    int result = 1;
    for (int i = 1; i <= exp; i++)
        result *= base;

    return result;
}

// Factorial
long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;

    return fact;
}

// Prime Check
bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

// Digit Sum
int digitSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

// Swap (Pass by Reference)
void swapNumbers(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// MAIN FUNCTION
int main()
{
    cout << "===== SIMPLE MATH TOOLKIT =====\n\n";

    cout << "Add(5,3) = " << add(5, 3) << endl;
    cout << "Add(1,2,3) = " << add(1, 2, 3) << endl;

    cout << "Power(5) = " << power(5) << endl;
    cout << "Power(2,3) = " << power(2, 3) << endl;

    cout << "Factorial(5) = " << factorial(5) << endl;

    if (isPrime(7))
        cout << "7 is Prime\n";
    else
        cout << "7 is Not Prime\n";

    cout << "Digit Sum of 123 = " << digitSum(123) << endl;

    cout << "Square(4) = " << square(4) << endl;
    cout << "Cube(3) = " << CUBE(3) << endl;

    int x = 10, y = 20;
    swapNumbers(x, y);
    cout << "After Swap: x = " << x << " y = " << y << endl;

    return 0;
}