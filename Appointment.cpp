#include "appointment.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addAppointment() {
    int id;
    string name, date, time;

    cout << "Enter Patient ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Patient Name: ";
    getline(cin, name);
    cout << "Enter Appointment Date (DD-MM-YYYY): ";
    getline(cin, date);
    cout << "Enter Appointment Time (HH:MM): ";
    getline(cin, time);

    ofstream file("appointments.txt", ios::app);
    file << id << "," << name << "," << date << "," << time << "\n";
    file.close();

    cout << "Appointment Scheduled!\n";
}

void viewAppointments() {
    ifstream file("appointments.txt");
    string line;
    cout << "\n All Appointments:\n";

    while (getline(file, line)) {
        int id;
        string name, date, time;

        size_t pos = line.find(","); id = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
        pos = line.find(","); name = line.substr(0, pos); line.erase(0, pos + 1);
        pos = line.find(","); date = line.substr(0, pos); line.erase(0, pos + 1);
        time = line;

        cout << "ID: " << id << "\nName: " << name << "\nDate: " << date << "\nTime: " << time << "\n---------------------\n";
    }

    file.close();
}
