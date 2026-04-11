#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

// ---------------- UTILITY ----------------
void line() {
    cout << "\n====================================\n";
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// ---------------- BASE CLASS ----------------
class Person {
protected:
    string name;
    int age;
    string contact;

public:
    void setPerson(string n, int a, string c) {
        name = n;
        age = a;
        contact = c;
    }
};

// ---------------- PATIENT ----------------
class Patient : public Person {
private:
    int patientID;
    string disease;

public:
    void setPatient(int id, string n, int a, string c, string d) {
        patientID = id;
        disease = d;
        setPerson(n, a, c);
    }

    int getID() { return patientID; }
    string getName() { return name; }

    void display() {
        cout << "\n---------------------------------\n";
        cout << "Patient ID   : " << patientID << endl;
        cout << "Name         : " << name << endl;
        cout << "Age          : " << age << endl;
        cout << "Contact      : " << contact << endl;
        cout << "Disease      : " << disease << endl;
        cout << "---------------------------------\n";
    }

    void save() {
        ofstream file("patients.txt", ios::app);
        file << patientID << "|" << name << "|" << age
             << "|" << contact << "|" << disease << endl;
        file.close();
    }
};

// ---------------- DOCTOR ----------------
class Doctor : public Person {
private:
    int doctorID;
    string specialization;
    bool available;

public:
    void setDoctor(int id, string n, int a, string c, string s) {
        doctorID = id;
        specialization = s;
        available = true;
        setPerson(n, a, c);
    }

    int getID() { return doctorID; }

    bool isAvailable() { return available; }

    void setAvailability(bool status) { available = status; }

    void display() {
        cout << "\n---------------------------------\n";
        cout << "Doctor ID    : " << doctorID << endl;
        cout << "Name         : " << name << endl;
        cout << "Age          : " << age << endl;
        cout << "Contact      : " << contact << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Available    : " << (available ? "Yes" : "No") << endl;
        cout << "---------------------------------\n";
    }

    void save() {
        ofstream file("doctors.txt", ios::app);
        file << doctorID << "|" << name << "|" << age
             << "|" << contact << "|" << specialization << endl;
        file.close();
    }
};

// ---------------- APPOINTMENT ----------------
class Appointment {
public:
    int patientID;
    int doctorID;
    string time;
};

// ---------------- PHARMACY ----------------
class Medicine {
private:
    int id;
    string name;
    int stock;
    double price;

public:
    void addMedicine(int i, string n, int s, double p) {
        id = i;
        name = n;
        stock = s;
        price = p;
    }

    int getId() { return id; }
    int getStock() { return stock; }
    double getPrice() { return price; }
    string getName() { return name; }

    void reduceStock(int qty) { stock -= qty; }

    void display() {
        cout << left << setw(6) << id
             << setw(20) << name
             << setw(10) << stock
             << setw(10) << price << endl;
    }
};

// ---------------- PATIENT MEDICINE RECORD ----------------
// Tracks medicine costs per patient for integrated billing
struct PatientMedicineCost {
    int patientID;
    double medicineCost;
};

// ---------------- BILLING ----------------
class Billing {
public:
    virtual double calculate() {
        return 0;
    }
};

class PatientBill : public Billing {
private:
    double consultation;
    double medicine;

public:
    void set(double c, double m) {
        consultation = c;
        medicine = m;
    }

    double calculate() override {
        return consultation + medicine;
    }

    void printBreakdown(int pid, string patientName) {
        cout << "\n========================================\n";
        cout << "            FINAL BILL RECEIPT          \n";
        cout << "========================================\n";
        cout << "Patient ID        : " << pid << endl;
        cout << "Patient Name      : " << patientName << endl;
        cout << "----------------------------------------\n";
        cout << left << setw(28) << "Consultation Fee"
             << ": Rs. " << fixed << setprecision(2) << consultation << endl;
        cout << left << setw(28) << "Medicine Cost (Pharmacy)"
             << ": Rs. " << fixed << setprecision(2) << medicine << endl;
        cout << "----------------------------------------\n";
        cout << left << setw(28) << "TOTAL AMOUNT"
             << ": Rs. " << fixed << setprecision(2) << calculate() << endl;
        cout << "========================================\n";
    }

    void save(int pid, string patientName, double med) {
        ofstream file("bills.txt", ios::app);
        file << "PatientID: " << pid
             << " | Name: " << patientName
             << " | Consultation: " << consultation
             << " | Medicine: " << med
             << " | Total: " << calculate() << endl;
        file.close();
    }
};

// ====================== MAIN ======================
int main() {

    Patient patients[100];
    Doctor doctors[50];
    Appointment appointments[100];
    Medicine meds[100];

    // Tracks accumulated pharmacy costs per patient
    PatientMedicineCost patMedCosts[100];
    int pmcCount = 0;

    int mCount = 0;
    int pCount = 0, dCount = 0;
    int front = 0, rear = -1;

    int choice;

    do {
        line();
        cout << "      HOSPITAL MANAGEMENT SYSTEM";
        line();

        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Book Appointment\n";
        cout << "4. Process Appointment\n";
        cout << "5. Show Patients\n";
        cout << "6. Show Doctors\n";
        cout << "7. Pharmacy System\n";   // <-- moved to 7
        cout << "8. Generate Final Bill\n"; // <-- billing at 8 (includes pharmacy)
        cout << "0. Exit\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        // -------- ADD PATIENT --------
        if (choice == 1) {
            int id, age;
            string name, contact, disease;

            line();
            cout << "ADD NEW PATIENT";
            line();

            cout << "Enter Patient ID   : ";
            cin >> id;
            cin.ignore();

            cout << "Enter Full Name    : ";
            getline(cin, name);

            cout << "Enter Age          : ";
            cin >> age;
            cin.ignore();

            cout << "Enter Contact No   : ";
            getline(cin, contact);

            cout << "Enter Disease      : ";
            getline(cin, disease);

            patients[pCount].setPatient(id, name, age, contact, disease);
            patients[pCount].save();
            pCount++;

            cout << "\n✅ Patient added successfully!\n";
            pauseScreen();
        }

        // -------- ADD DOCTOR --------
        else if (choice == 2) {
            int id, age;
            string name, contact, spec;

            line();
            cout << "ADD NEW DOCTOR";
            line();

            cout << "Enter Doctor ID    : ";
            cin >> id;
            cin.ignore();

            cout << "Enter Full Name    : ";
            getline(cin, name);

            cout << "Enter Age          : ";
            cin >> age;
            cin.ignore();

            cout << "Enter Contact No   : ";
            getline(cin, contact);

            cout << "Enter Specialization: ";
            getline(cin, spec);

            doctors[dCount].setDoctor(id, name, age, contact, spec);
            doctors[dCount].save();
            dCount++;

            cout << "\n✅ Doctor added successfully!\n";
            pauseScreen();
        }

        // -------- BOOK APPOINTMENT --------
        else if (choice == 3) {
            int pid, did;
            string time;

            line();
            cout << "BOOK APPOINTMENT";
            line();

            cout << "Enter Patient ID : ";
            cin >> pid;

            cout << "Enter Doctor ID  : ";
            cin >> did;
            cin.ignore();

            cout << "Enter Time       : ";
            getline(cin, time);

            bool found = false;

            for (int i = 0; i < dCount; i++) {
                if (doctors[i].getID() == did && doctors[i].isAvailable()) {
                    rear++;
                    appointments[rear].patientID = pid;
                    appointments[rear].doctorID = did;
                    appointments[rear].time = time;

                    doctors[i].setAvailability(false);

                    cout << "\n✅ Appointment booked!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\n❌ Doctor not available!\n";

            pauseScreen();
        }

        // -------- PROCESS APPOINTMENT --------
        else if (choice == 4) {
            line();
            cout << "PROCESS APPOINTMENT";
            line();

            if (front <= rear) {
                Appointment a = appointments[front++];
                cout << "Patient ID : " << a.patientID << endl;
                cout << "Doctor ID  : " << a.doctorID << endl;
                cout << "Time       : " << a.time << endl;

                for (int i = 0; i < dCount; i++) {
                    if (doctors[i].getID() == a.doctorID)
                        doctors[i].setAvailability(true);
                }

                cout << "\n✅ Appointment completed!\n";
            } else {
                cout << "No appointments in queue!\n";
            }

            pauseScreen();
        }

        // -------- SHOW PATIENTS --------
        else if (choice == 5) {
            line();
            cout << "PATIENT LIST";
            line();

            if (pCount == 0)
                cout << "No patients registered.\n";

            for (int i = 0; i < pCount; i++)
                patients[i].display();

            pauseScreen();
        }

        // -------- SHOW DOCTORS --------
        else if (choice == 6) {
            line();
            cout << "DOCTOR LIST";
            line();

            if (dCount == 0)
                cout << "No doctors registered.\n";

            for (int i = 0; i < dCount; i++)
                doctors[i].display();

            pauseScreen();
        }

        // -------- PHARMACY SYSTEM (Choice 7) --------
        else if (choice == 7) {

            int ch;
            do {
                line();
                cout << "PHARMACY SYSTEM";
                line();

                cout << "1. Add Medicine\n";
                cout << "2. Display Medicines\n";
                cout << "3. Dispense Medicine to Patient\n";
                cout << "0. Back\n";
                cout << "------------------------------------\n";
                cout << "Enter choice: ";
                cin >> ch;
                cin.ignore();

                // ADD MEDICINE
                if (ch == 1) {
                    int id, stock;
                    double price;
                    string name;

                    line();
                    cout << "ADD MEDICINE";
                    line();

                    cout << "Enter Medicine ID   : ";
                    cin >> id;
                    cin.ignore();

                    cout << "Enter Medicine Name : ";
                    getline(cin, name);

                    cout << "Enter Stock         : ";
                    cin >> stock;

                    cout << "Enter Price per Unit: ";
                    cin >> price;

                    meds[mCount].addMedicine(id, name, stock, price);
                    mCount++;

                    cout << "\n✅ Medicine added successfully!\n";
                }

                // DISPLAY MEDICINES
                else if (ch == 2) {
                    line();
                    cout << "MEDICINE INVENTORY";
                    line();

                    if (mCount == 0) {
                        cout << "No medicines in inventory.\n";
                    } else {
                        cout << left << setw(6)  << "ID"
                             << setw(20) << "Name"
                             << setw(10) << "Stock"
                             << setw(10) << "Price" << endl;
                        cout << "----------------------------------------------\n";

                        for (int i = 0; i < mCount; i++)
                            meds[i].display();
                    }
                }

                // DISPENSE MEDICINE TO PATIENT (cost tracked per patient)
                else if (ch == 3) {
                    int pid;
                    double sessionTotal = 0;

                    line();
                    cout << "DISPENSE MEDICINE TO PATIENT";
                    line();

                    cout << "Enter Patient ID: ";
                    cin >> pid;

                    // Verify patient exists
                    bool patFound = false;
                    string patName = "";
                    for (int i = 0; i < pCount; i++) {
                        if (patients[i].getID() == pid) {
                            patFound = true;
                            patName = patients[i].getName();
                            break;
                        }
                    }

                    if (!patFound) {
                        cout << "\n❌ Patient ID not found!\n";
                        pauseScreen();
                        continue;
                    }

                    cout << "Patient: " << patName << "\n";
                    cout << "\n--- Dispense Medicines (Enter 0 to stop) ---\n";

                    while (true) {
                        int mid, qty;
                        cout << "Enter Medicine ID (0 to stop): ";
                        cin >> mid;
                        if (mid == 0) break;

                        cout << "Enter Quantity: ";
                        cin >> qty;

                        bool medFound = false;
                        for (int i = 0; i < mCount; i++) {
                            if (meds[i].getId() == mid) {
                                medFound = true;
                                if (qty <= meds[i].getStock()) {
                                    double cost = qty * meds[i].getPrice();
                                    sessionTotal += cost;
                                    meds[i].reduceStock(qty);

                                    cout << "  ✅ " << meds[i].getName()
                                         << " x " << qty
                                         << " = Rs. " << fixed << setprecision(2) << cost << endl;
                                } else {
                                    cout << "  ❌ Insufficient stock! Available: "
                                         << meds[i].getStock() << "\n";
                                }
                                break;
                            }
                        }
                        if (!medFound)
                            cout << "  ❌ Medicine ID not found.\n";
                    }

                    cout << "\nTotal Medicine Cost for this session: Rs. "
                         << fixed << setprecision(2) << sessionTotal << endl;

                    // Store / accumulate medicine cost for this patient
                    bool found = false;
                    for (int i = 0; i < pmcCount; i++) {
                        if (patMedCosts[i].patientID == pid) {
                            patMedCosts[i].medicineCost += sessionTotal;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        patMedCosts[pmcCount].patientID = pid;
                        patMedCosts[pmcCount].medicineCost = sessionTotal;
                        pmcCount++;
                    }

                    cout << "\n✅ Medicine cost of Rs. " << fixed << setprecision(2)
                         << sessionTotal << " recorded for Patient ID " << pid << ".\n";
                    cout << "   This will be included in the Final Bill (Option 8).\n";

                    pauseScreen();
                }

            } while (ch != 0);
        }

        // -------- FINAL BILLING (Choice 8) — includes pharmacy --------
        else if (choice == 8) {
            PatientBill bill;
            int pid;
            double consultFee;

            line();
            cout << "GENERATE FINAL BILL";
            line();

            cout << "Enter Patient ID        : ";
            cin >> pid;
            cin.ignore();

            // Find patient name
            string patientName = "Unknown";
            bool patFound = false;
            for (int i = 0; i < pCount; i++) {
                if (patients[i].getID() == pid) {
                    patientName = patients[i].getName();
                    patFound = true;
                    break;
                }
            }

            if (!patFound) {
                cout << "\n❌ Patient ID not found!\n";
                pauseScreen();
                continue;
            }

            cout << "Patient Name            : " << patientName << endl;

            cout << "Enter Consultation Fee  : Rs. ";
            cin >> consultFee;

            // Fetch accumulated medicine cost for this patient
            double medCost = 0.0;
            for (int i = 0; i < pmcCount; i++) {
                if (patMedCosts[i].patientID == pid) {
                    medCost = patMedCosts[i].medicineCost;
                    break;
                }
            }

            cout << "\nMedicine Cost (from Pharmacy): Rs. "
                 << fixed << setprecision(2) << medCost << endl;

            bill.set(consultFee, medCost);
            bill.printBreakdown(pid, patientName);
            bill.save(pid, patientName, medCost);

            cout << "\n✅ Bill generated and saved to bills.txt\n";
            pauseScreen();
        }

    } while (choice != 0);

    cout << "\nThank you for using the Hospital Management System!\n";
    return 0;
}