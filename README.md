# Hospital_Management

A simple Hospital Management System built in **C++**, designed to run in the terminal. It manages patients, appointments, diagnosis records, and billing using modular classes and stores all data in **CSV-like text files**.

---

## 📁 Project Structure

 main.cpp
├── patient.h / patient.cpp
├── appointment.h / appointment.cpp
├── diagnosis.h / diagnosis.cpp
├── billing.h / billing.cpp
├── patients.txt # Stores patient records
├── appointments.txt # Stores appointment records
├── diagnoses.txt # Stores diagnosis details
├── bills.txt # Stores billing information
└── patients.csv # Exported version of patient records (optional)


---

## 🚀 Features

### ✅ Core Functionalities:
- **Add/View/Search Patient**
- **Schedule/View Appointments**
- **Add/View Diagnosis**
- **Generate/View Bills**

### 📄 Data Handling:
- All records are saved as CSV-format in text files.
- Easily extendable to export `.csv` for use in Excel.

### 🛡️ Admin Login:
- Basic username/password protection:
  - Username: `admin`
  - Password: `pass123`

---

## 🛠️ Technologies Used

- **C++**
- File handling with `fstream`
- Modular design with classes
- CLI-based interaction
- No external libraries required

---

## To Compile and Run

```bash
g++ main.cpp patient.cpp appointment.cpp diagnosis.cpp billing.cpp -o hospital.exe
./hospital.exe
```

## Sample
===Hospital Management System ===
1. Add Patient
2. View All Patients
3. Search Patient by ID
...
Enter choice: 1
Enter Patient ID: 101
Enter Name: Sam
Enter Age: 19
...
✅ Patient added successfully!

--------


