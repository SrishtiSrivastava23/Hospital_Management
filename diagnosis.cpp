#include "diagnosis.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addDiagnosis() {
    int id;
    string name, diagnosis, prescription;

    cout << "Enter Patient ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Patient Name: ";
    getline(cin, name);
    cout << "Diagnosis: ";
    getline(cin, diagnosis);
    cout << "Prescription: ";
    getline(cin, prescription);

    ofstream file("diagnosis.txt", ios::app);
    file << id << "," << name << "," << diagnosis << "," << prescription << "\n";
    file.close();

    cout << "Diagnosis recorded.\n";
}

void viewDiagnoses() {
    ifstream file("diagnosis.txt");
    string line;

    cout << "\nDiagnosis Records:\n";

    while (getline(file, line)) {
        int id;
        string name, diag, pres;

        size_t pos = line.find(","); id = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
        pos = line.find(","); name = line.substr(0, pos); line.erase(0, pos + 1);
        pos = line.find(","); diag = line.substr(0, pos); line.erase(0, pos + 1);
        pres = line;

        cout << "ID: " << id << "\nName: " << name << "\nDiagnosis: " << diag << "\nPrescription: " << pres << "\n-----------------\n";
    }

    file.close();
}
