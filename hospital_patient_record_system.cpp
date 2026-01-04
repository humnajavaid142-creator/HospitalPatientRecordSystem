#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// patient record
void addPatient() {
    int id;
    int age;
    string name;
    string disease;

    cout << "\nEnter Patient ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, name);

    cout << "Enter Patient Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Disease: ";
    getline(cin, disease);

    ofstream file("patients.csv", ios::app);

    // patient informatiom
    if (file.tellp() == 0) {
        file << "ID,Name,Age,Disease\n";
    }

    file << id << "," << name << "," << age << "," << disease << "\n";
    file.close();

    cout << "\nPatient record saved successfully.\n";
}

//  all records (cvs file)
void displayPatients() {
    ifstream file("patients.csv");
    string line;

    if (!file) {
        cout << "\nNo patient records found.\n";
        return;
    }

    cout << "\n--- Patient Records ---\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

// search patient by ID
void searchPatient() {
    ifstream file("patients.csv");
    string line, searchID;
    bool found = false;

    if (!file) {
        cout << "\nNo patient records found.\n";
        return;
    }

    cout << "\nEnter Patient ID to search: ";
    cin >> searchID;

    getline(file, line);

    while (getline(file, line)) {
        string id = line.substr(0, line.find(','));

        if (id == searchID) {
            cout << "\nPatient Found:\n";
            cout << "ID,Name,Age,Disease\n";
            cout << line << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nPatient not found.\n";
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n Hospital Patient Record System\n";
        cout << "1. Add Patient Record\n 2.View Patients\n  3.Search Patient\n  4.Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addPatient();
        }
        else if (choice == 2) {
            displayPatients();
        }
        else if (choice == 3) {
            searchPatient();
        }
        else if (choice == 4) {
            cout << "\nExiting program...\n";
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
