//Write a C++ Program to Read and Write File Opera on in File Handling.

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filename = "example.txt";
    string data;

    // Writing to file
    ofstream outFile(filename, ios::out); // open file in write mode

    if (!outFile) {
        cout << "Error: Unable to open file for writing." << endl;
        return 1;
    }

    outFile << "Hello, this is a file handling example in C++." << endl;
    outFile << "File handling allows reading and writing to files." << endl;

    outFile.close(); // close file after writing
    cout << "Data written to file successfully." << endl;

    // Reading from file
    ifstream inFile(filename); // open file in read mode

    if (!inFile) {
        cout << "Error: File does not exist or cannot be opened." << endl;
        return 1;
    }

    cout << "\nReading from file:" << endl;

    while (getline(inFile, data)) {
        cout << data << endl;
    }

    inFile.close(); // close file after reading

    return 0;
}