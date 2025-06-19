#include "patient.h"
#include <iostream>
#include <fstream>
#include <iomanip> // for setw

using namespace std;

void Patient::input() {
    cout << "Enter Patient ID: ";
    while (!(cin >> id) || id <= 0) {
        cout << "Invalid ID. Enter again: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cin.ignore(); 

    cout << "Enter Name: ";
    getline(cin, name);
    if (name.empty()) name = "Unknown";

    cout << "Enter Age: ";
    while (!(cin >> age) || age <= 0) {
        cout << " Invalid Age. Enter again: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cin.ignore();

    cout << "Enter Gender (M/F): ";
    getline(cin, gender);
    if (gender.empty()) gender = "N/A";

    cout << "Enter Contact Number: ";
    getline(cin, contact);
    if (contact.empty()) contact = "N/A";

    cout << "Enter Disease: ";
    getline(cin, disease);
    if (disease.empty()) disease = "N/A";

    cout << "Enter Doctor Assigned: ";
    getline(cin, doctor);
    if (doctor.empty()) doctor = "Not Assigned";
}

void Patient::display() const {
    cout << "\nID: " << id
         << "\nName: " << name
         << "\nAge: " << age
         << "\nGender: " << gender
         << "\nContact: " << contact
         << "\nDisease: " << disease
         << "\nDoctor: " << doctor
         << "\n---------------------------\n";
}

void addPatient() {
    Patient p;
    p.input();

    if (p.name == "Unknown") {
        cout << "Patient data incomplete. Not saved.\n";
        return;
    }

    ofstream file("patients.txt", ios::app);
    file << p.id << "," << p.name << "," << p.age << "," << p.gender << ","
         << p.contact << "," << p.disease << "," << p.doctor << "\n";
    file.close();

    cout << "Patient added successfully!\n";
}

void viewPatients() {
    ifstream file("patients.txt");
    if (!file.is_open()) {
        cout << "No patient records found.\n";
        return;
    }

    // Print header
    cout << left
         << setw(10) << "ID" << " | "
         << setw(15) << "Name" << " | "
         << setw(5) << "Age" << " | "
         << setw(7) << "Gender" << " | "
         << setw(12) << "Contact" << "\n";
    cout << string(60, '-') << "\n";

    string line;
    while (getline(file, line)) {
        Patient p;
        size_t pos = 0;

        pos = line.find(","); p.id = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
        pos = line.find(","); p.name = line.substr(0, pos); line.erase(0, pos + 1);
        pos = line.find(","); p.age = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
        pos = line.find(","); p.gender = line.substr(0, pos); line.erase(0, pos + 1);
        pos = line.find(","); p.contact = line.substr(0, pos); line.erase(0, pos + 1);
        pos = line.find(","); p.disease = line.substr(0, pos); line.erase(0, pos + 1);
        p.doctor = line;

        // Display row in table
        cout << left
             << setw(10) << p.id << " | "
             << setw(15) << p.name << " | "
             << setw(5) << p.age << " | "
             << setw(7) << p.gender << " | "
             << setw(12) << p.contact << "\n";
    }

    file.close();
}

void searchPatientByID(int searchID) {
    ifstream file("patients.txt");
    if (!file.is_open()) {
        cout << "⚠️ No patient records found.\n";
        return;
    }

    bool found = false;
    string line;
    while (getline(file, line)) {
        Patient p;
        size_t pos = 0;

        pos = line.find(","); p.id = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
        pos = line.find(","); p.name = line.substr(0, pos); line.erase(0, pos + 1);
        pos = line.find(","); p.age = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
        pos = line.find(","); p.gender = line.substr(0, pos); line.erase(0, pos + 1);
        pos = line.find(","); p.contact = line.substr(0, pos); line.erase(0, pos + 1);
        pos = line.find(","); p.disease = line.substr(0, pos); line.erase(0, pos + 1);
        p.doctor = line;

        if (p.id == searchID) {
            cout << "✅ Patient Found:\n";
            p.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Patient with ID " << searchID << " not found.\n";
    }

    file.close();
}
void exportPatientsToCSV() {
    ifstream file("patients.txt");
    ofstream csvFile("patients.csv");

    if (!file.is_open()) {
        cout << "No patient records found.\n";
        return;
    }

    // Write CSV header
    csvFile << "ID,Name,Age,Gender,Contact,Disease,Doctor\n";

    string line;
    while (getline(file, line)) {
        csvFile << line << "\n";
    }

    file.close();
    csvFile.close();

    cout << "Patient data exported to 'patients.csv'.\n";
}
