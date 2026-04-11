#include <iostream>
#include <fstream>
using namespace std;

// Product Class
class Product
{
public:
    int id;
    string name;
    double price;

    void input()
    {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore(); // Clear buffer

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Price: ";
        cin >> price;
    }

    void display()
    {
        cout << "ID: " << id
             << " Name: " << name
             << " Price: " << price << endl;
    }
};

// Function to Add Product
void addProduct()
{
    Product p;
    ofstream fout("inventory.dat", ios::app);

    if (!fout)
    {
        cout << "Error opening file!\n";
        return;
    }

    p.input();
    fout << p.id << " " << p.name << " " << p.price << endl;

    fout.close();
    cout << "Product Added Successfully!\n";
}

// Function to View Products
void viewProducts()
{
    Product p;
    ifstream fin("inventory.dat");

    if (!fin)
    {
        cout << "File not found!\n";
        return;
    }

    cout << "\n--- Product List ---\n";
    while (fin >> p.id >> p.name >> p.price)
    {
        p.display();
    }

    fin.close();
}

// Function to Update Product
void updateProduct()
{
    int searchId;
    cout << "Enter Product ID to update: ";
    cin >> searchId;

    ifstream fin("inventory.dat");
    ofstream temp("temp.dat");

    Product p;
    bool found = false;

    while (fin >> p.id >> p.name >> p.price)
    {
        if (p.id == searchId)
        {
            cout << "Enter New Details:\n";
            p.input();
            found = true;
        }
        temp << p.id << " " << p.name << " " << p.price << endl;
    }

    fin.close();
    temp.close();

    remove("inventory.dat");
    rename("temp.dat", "inventory.dat");

    if (found)
        cout << "Record Updated!\n";
    else
        cout << "Product not found!\n";
}

// Main Menu
int main()
{
    int choice;

    do
    {
        cout << "\n--- Inventory System ---\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Update Product\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addProduct();
            break;
        case 2:
            viewProducts();
            break;
        case 3:
            updateProduct();
            break;
        }

    } while (choice != 4);

    return 0;
}