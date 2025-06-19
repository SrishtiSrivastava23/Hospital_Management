#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient {
public:
    int id;
    std::string name;
    int age;
    std::string gender;    
    std::string contact;  
    std::string disease;
    std::string doctor;

    void input();
    void display() const;
};

void addPatient();
void viewPatients();
void searchPatientByID(int searchID);
void exportPatientsToCSV();


#endif
