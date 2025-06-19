#include "billing.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void generateBill() {
    int id;
    string name;
    float consultation, tests, medicine, total;

    cout << "Enter Patient ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Patient Name: ";
    getline(cin, name);
    cout << "Consultation Fees: Rupees ";
    cin >> consultation;
    cout << "Test Charges: Rupees ";
    cin >> tests;
    cout << "Medicine Charges: Rupees ";
    cin >> medicine;

    total = consultation + tests + medicine;

    ofstream file("bills.txt", ios::app);
    file << id << "," << name << "," << consultation << "," << tests << "," << medicine << "," << total << "\n";
    file.close();

    cout << " Bill Generated. Total: Rupees " << total << "\n";
}
