// PHARMACY MANAGEMENT SYSTEM 

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

string adminPassword = "admin123";

// ---------------- PASSWORD CHECK ----------------
bool checkPassword()
{
    string pass;
    cout << "Enter Admin Password: ";
    cin >> pass;

    if(pass == adminPassword)
    {
        cout << "Access Granted\n";
        return true;
    }
    else
    {
        cout << "Wrong Password! Access Denied\n";
        return false;
    }
}

// ---------------- GET CURRENT DATE ----------------
void getCurrentDate(int &day, int &month, int &year)
{
    time_t t = time(0);
    tm *now = localtime(&t);

    day = now->tm_mday;
    month = now->tm_mon + 1;
    year = now->tm_year + 1900;
}

// ---------------- EXTRACT DATE ----------------
void extractDate(string expiry, int &day, int &month, int &year)
{
    // Format: DD/MM/YYYY
    day = stoi(expiry.substr(0,2));
    month = stoi(expiry.substr(3,2));
    year = stoi(expiry.substr(6,4));
}

// ---------------- MEDICINE CLASS ----------------
class Medicine
{
private:
    int id;
    string name;
    int stock;
    double price;
    string expiry;

public:
    Medicine()
    {
        id = 0;
        name = "";
        stock = 0;
        price = 0;
        expiry = "";
    }

    void addMedicine(int i, string n, int s, double p, string e)
    {
        id = i;
        name = n;
        stock = s;
        price = p;
        expiry = e;
    }

    int getId(){ return id; }
    string getName(){ return name; }
    int getStock(){ return stock; }
    double getPrice(){ return price; }
    string getExpiry(){ return expiry; }

    void reduceStock(int qty){ stock -= qty; }
    void updateStock(int s){ stock = s; }
    void updateExpiry(string e){ expiry = e; }

    void display()
    {
        cout << left << setw(6) << id
             << setw(15) << name
             << setw(10) << stock
             << setw(10) << price
             << setw(12) << expiry << endl;
    }
};

// ---------------- MAIN ----------------
int main()
{
    Medicine med[100];
    int count = 0;
    int choice;

    do
    {
        cout << "\n====== PHARMACY MANAGEMENT SYSTEM ======\n";
        cout << "1. Add Medicine\n";
        cout << "2. Display Medicines\n";
        cout << "3. Edit Medicine (Admin)\n";
        cout << "4. Remove Medicine (Admin)\n";
        cout << "5. Customer Billing\n";
        cout << "6. Search Medicine\n";
        cout << "7. Expiry Alert System\n";
        cout << "8. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        // -------- ADD MEDICINE --------
        if(choice == 1)
        {
            int n;
            cout<<"How many medicines do you want to add: ";
            cin>>n;

            for(int k=0; k<n; k++)
            {
                int id, stock;
                string name, expiry;
                double price;

                cout<<"\nEnter details for Medicine "<<k+1<<endl;

                cout<<"Enter ID: ";
                cin>>id;

                cout<<"Enter Name: ";
                cin.ignore();
                getline(cin,name);

                cout<<"Enter Stock: ";
                cin>>stock;

                cout<<"Enter Price: ";
                cin>>price;

                cout<<"Enter Expiry Date (DD/MM/YYYY): ";
                cin>>expiry;

                med[count].addMedicine(id,name,stock,price,expiry);
                count++;
            }

            cout<<"\nAll Medicines Added Successfully!\n";
        }

        // -------- DISPLAY --------
        else if(choice == 2)
        {
            cout<<"\nID    Name           Stock     Price     Expiry\n";
            cout<<"-----------------------------------------------\n";

            for(int i=0;i<count;i++)
                med[i].display();
        }

        // -------- EDIT --------
        else if(choice == 3)
        {
            if(checkPassword())
            {
                int id,newStock;
                string newExpiry;

                cout<<"Enter Medicine ID to edit: ";
                cin>>id;

                for(int i=0;i<count;i++)
                {
                    if(med[i].getId()==id)
                    {
                        cout<<"Enter New Stock: ";
                        cin>>newStock;

                        cout<<"Enter New Expiry Date (DD/MM/YYYY): ";
                        cin>>newExpiry;

                        med[i].updateStock(newStock);
                        med[i].updateExpiry(newExpiry);

                        cout<<"Medicine Updated!\n";
                    }
                }
            }
        }

        // -------- REMOVE --------
        else if(choice == 4)
        {
            if(checkPassword())
            {
                int id;
                cout<<"Enter Medicine ID to remove: ";
                cin>>id;

                for(int i=0;i<count;i++)
                {
                    if(med[i].getId()==id)
                    {
                        for(int j=i;j<count-1;j++)
                            med[j]=med[j+1];

                        count--;
                        cout<<"Medicine Removed!\n";
                        break;
                    }
                }
            }
        }

        // -------- BILLING --------
        else if(choice == 5)
        {
            int id, qty;
            double total = 0;

            cout<<"\n========== BILL ==========\n";

            while(true)
            {
                cout<<"Enter Medicine ID (0 to stop): ";
                cin>>id;
                if(id==0) break;

                cout<<"Enter Quantity: ";
                cin>>qty;

                for(int i=0;i<count;i++)
                {
                    if(med[i].getId()==id)
                    {
                        if(qty <= med[i].getStock())
                        {
                            double bill = qty * med[i].getPrice();
                            total += bill;

                            cout<<med[i].getName()<<" x "<<qty<<" = "<<bill<<endl;

                            med[i].reduceStock(qty);
                        }
                        else
                            cout<<"Insufficient Stock\n";
                    }
                }
            }

            cout<<"Total Amount: "<<total<<endl;
        }

        // -------- SEARCH --------
        else if(choice == 6)
        {
            int id;
            cout<<"Enter Medicine ID to search: ";
            cin>>id;

            bool found=false;

            for(int i=0;i<count;i++)
            {
                if(med[i].getId()==id)
                {
                    cout<<"\nMedicine Found\n";
                    med[i].display();
                    found=true;
                }
            }

            if(!found)
                cout<<"Medicine not found\n";
        }

        // -------- EXPIRY ALERT SYSTEM --------
        else if(choice == 7)
        {
            int cDay, cMonth, cYear;
            getCurrentDate(cDay, cMonth, cYear);

            cout<<"\n⚠ EXPIRY ALERT SYSTEM ⚠\n";

            for(int i=0;i<count;i++)
            {
                int eDay, eMonth, eYear;
                extractDate(med[i].getExpiry(), eDay, eMonth, eYear);

                // EXPIRED
                if(eYear < cYear ||
                  (eYear == cYear && eMonth < cMonth) ||
                  (eYear == cYear && eMonth == cMonth && eDay < cDay))
                {
                    cout<<"\n❌ EXPIRED:\n";
                    med[i].display();
                }

                // NEAR EXPIRY (within 30 days)
                else if(eYear == cYear && eMonth == cMonth && (eDay - cDay <= 30))
                {
                    cout<<"\n⚠ EXPIRING SOON:\n";
                    med[i].display();
                }
            }
        }

    } while(choice != 8);

    cout<<"\nThank You for Using Pharmacy System\n";
    return 0;
}