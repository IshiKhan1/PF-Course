#include <iostream> // Muhammad Imran 67451, Muhammed Annus 66539, hamza satthei
#include <string>
using namespace std;

const int MAX_STUDENTS = 100; // Maximum number of students

struct Student {
    int id;
    string name;
    string department;
    float gpa;
    bool isActive;
};

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Cannot add more students. Maximum limit reached.\n";
        return;
    }

    Student newStudent;
    cout << "Enter Student ID: ";
    cin >> newStudent.id;
    cin.ignore(); // Clear the input buffer
    cout << "Enter Student Name: ";
    getline(cin, newStudent.name);
    cout << "Enter Department: ";
    getline(cin, newStudent.department);
    cout << "Enter GPA: ";
    cin >> newStudent.gpa;
    newStudent.isActive = true;

    students[studentCount++] = newStudent;
    cout << "Student added successfully!\n";
}

void viewStudents() {
    if (studentCount == 0) {
        cout << "No students to display.\n";
        return;
    }

    cout << "\nStudent List:\n";
    cout << "-------------------------------------------------\n";
    cout << "ID\tName\t\t\tDepartment\tGPA\n";
    cout << "-------------------------------------------------\n";

    for (int i = 0; i < studentCount; i++) {
        if (students[i].isActive) {
            cout << students[i].id << "\t"
                 << students[i].name << "\t\t"
                 << students[i].department << "\t\t"
                 << students[i].gpa << "\n";
        }
    }

    cout << "-------------------------------------------------\n";
}


void searchStudent() {
    int searchId;
    cout << "Enter Student ID to search: ";
    cin >> searchId;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchId && students[i].isActive) {
            cout << "Student Found:\n";
            cout << "ID: " << students[i].id << "\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Department: " << students[i].department << "\n";
            cout << "GPA: " << students[i].gpa << "\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void updateStudent() {
    int updateId;
    cout << "Enter Student ID to update: ";
    cin >> updateId;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == updateId && students[i].isActive) {
            cout << "Enter new details for Student ID " << updateId << ":\n";
            cin.ignore(); // Clear the input buffer
            cout << "Enter Student Name: ";
            getline(cin, students[i].name);
            cout << "Enter Department: ";
            getline(cin, students[i].department);
            cout << "Enter GPA: ";
            cin >> students[i].gpa;
            cout << "Student details updated successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    int deleteId;
    cout << "Enter Student ID to delete: ";
    cin >> deleteId;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == deleteId && students[i].isActive) {
            students[i].isActive = false;
            cout << "Student record deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\nUniversity Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Exiting program. Goodbye!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
