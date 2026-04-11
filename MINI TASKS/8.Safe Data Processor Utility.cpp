#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Function Templates
template <typename T>
T add(T a, T b) { return a + b; }

template <typename T>
T subtract(T a, T b) { return a - b; }

template <typename T>
T multiply(T a, T b) { return a * b; }

template <typename T>
T divide(T a, T b) {
    if (b == 0)
        throw "Error: Division by zero!";
    return a / b;
}

// Structure to store operation history
struct Record {
    string operation;
    double result;
};

int main() {
    vector<Record> history;

    int choice;
    double a, b;

    do {
        cout << "\n--- Safe Data Processor ---\n";
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
        cout << "5. Show History\n6. Show Statistics\n7. Clear Data\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if (choice >= 1 && choice <= 4) {
                cout << "Enter two numbers: ";

                if (!(cin >> a >> b)) {
                    throw "Invalid input! Enter numbers only.";
                }

                double res;
                string op;

                switch (choice) {
                    case 1:
                        res = add(a, b);
                        op = "Add";
                        break;
                    case 2:
                        res = subtract(a, b);
                        op = "Subtract";
                        break;
                    case 3:
                        res = multiply(a, b);
                        op = "Multiply";
                        break;
                    case 4:
                        res = divide(a, b);
                        op = "Divide";
                        break;
                }

                history.push_back({op, res});
                cout << "Result: " << res << endl;
            }

            else if (choice == 5) {
                cout << "\n--- History ---\n";
                for (auto &rec : history) {
                    cout << rec.operation << " → " << rec.result << endl;
                }
            }

            else if (choice == 6) {
                double sum = 0;
                for (auto &rec : history) {
                    sum += rec.result;
                }

                if (history.size() == 0)
                    throw "No data available!";

                cout << "Total Results: " << history.size() << endl;
                cout << "Sum: " << sum << endl;
                cout << "Average: " << sum / history.size() << endl;
            }

            else if (choice == 7) {
                history.clear();
                cout << "All data cleared!\n";
            }

        }
        catch (const char* msg) {
            cout << msg << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (...) {
            cout << "Unknown error occurred!\n";
        }

    } while (choice != 8);

    return 0;
}