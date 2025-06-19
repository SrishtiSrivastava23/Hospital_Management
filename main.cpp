#include <iostream>
#include "patient.h"
#include "appointment.h"
#include "billing.h"
#include "diagnosis.h"

using namespace std;

//  Optional Admin Login
bool login() {
    string username, password;
    cout << "=== Admin Login ===\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "pass123") {
        cout << "Login Successful!\n";
        return true;
    } else {
        cout << "Login Failed. Exiting...\n";
        return false;
    }
}

int main() {
    if (!login()) return 0;

    int choice;
    do {
        cout << "\n=== Hospital Management System ===\n";
        cout << "1. Add Patient\n";
        cout << "2. View All Patients\n";
        cout << "3. Search Patient by ID\n";
        cout << "4. Add Appointment\n";
        cout << "5. View Appointments\n";
        cout << "6. Generate Bill\n";
        cout << "7. Add Diagnosis\n";
        cout << "8. View Diagnosis\n";
        cout << "9. Export Patients to CSV\n";

        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3: {
                int id;
                cout << "Enter Patient ID to search: ";
                cin >> id;
                searchPatientByID(id);
                break;
            }
            case 4:
                addAppointment();
                break;
            case 5:
                viewAppointments();
                break;
            case 6:
                generateBill();
                break;
            case 7:
                addDiagnosis();
                break;
            case 8:
                viewDiagnoses();
                break;
            case 9:
                exportPatientsToCSV();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
