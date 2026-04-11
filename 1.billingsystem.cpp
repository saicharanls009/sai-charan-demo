#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string name;
    string itemname; // we can add customer name,mobile no.,membership details,
    int i,mobileno, n, quantity;
    float itemprice, finalbill = 0, finalamount, tax, discount;

    cout << "Enter Customer's Name:";
    cin >> name;

    cout << "Enter Customer's Mobile no.:";
    cin >> mobileno;

    cout << "Enter No.of Items: ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cout << "\nItem " << i << ":" << endl;
        cout << "Enter Name: ";
        cin >> itemname;

        cout << "Enter Price: ";
        cin >> itemprice;

        cout << "Enter Quantity: ";
        cin >> quantity;

        float itemtotal = itemprice * quantity;
        finalbill += itemtotal;

        cout << fixed << setprecision(2);
        cout << "current subtotal: ₹" << finalbill << endl;
    }

    discount = finalbill * 0.05;
    float afterDiscount = finalbill - discount;
    tax = afterDiscount * 0.18;
    finalamount = afterDiscount + tax;

    cout << "\n ***********************************" << endl; // we can print the output like bills in shopping mall also
    cout << "\n Name :           " << name << endl;
    cout << "\n Mobile no.       " << mobileno <<endl;
    cout << "Subtotal :         ₹" << finalbill << endl;
    cout << "Discount (5%):    -₹" << discount << endl;
    cout << "Tax (18%):        +₹" << tax << endl;
    cout << "GRAND TOTAL :      ₹" << finalamount << endl;
    cout << "\n ***********************************" << endl;

    cout << "\n----------------------------------------" << endl;
    cout << "\nTOTAL PAYABLE : ₹" << finalamount << endl;

    cout << "\n==========================================" << endl;
    cout << " \nTHANK YOU! VISIT AGAIN" << endl;

    return 0;
}