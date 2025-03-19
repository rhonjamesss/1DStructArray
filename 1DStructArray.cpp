#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct Student {
    int studentId = 0;
    string fname = "";
    string lname = "";
    string course = "";
    float gpa = 0.0;
};

Student students[1000];
int counter = 0;

void clearScreen(){
    system("cls");
}

bool ifDuplicateStudent(int studentId, int counter){
    for(int i = 0; i < counter; i++){
        if(students[i].studentId == studentId){
            return true;
        }
    }
    return false;
}

void addStudentData(){
    clearScreen();

    int studentId;
    cout << "Enter Student ID: ";
    cin >> studentId;

    if(ifDuplicateStudent(studentId, counter)){
        while(true){
            cout << "Student ID already exists!\n";
            cout << "Enter new Student ID: ";
            cin >> studentId;
            students[counter].studentId = studentId;

            if(!ifDuplicateStudent(studentId, counter)){
                break;
            }
        }
    }

    students[counter].studentId = studentId;

    cout << "Enter First Name: ";
    cin >> students[counter].fname;
    cout << "Enter Last Name: ";
    cin >> students[counter].lname;
    cout << "Enter Course: ";
    cin >> students[counter].course;
    cout << "Enter Previous GPA: ";
    cin >> students[counter].gpa;
    
    counter++;

    cout << "Student data added successfully!.\n";
}

void editStudentData(){
    clearScreen();
    if(counter == 0){
        cout << "No student records available.\n";
        return;
    }

    int studentId;
    cout << "Enter Student ID to search: ";
    cin >> studentId;

    for(int i = 0; i < counter; i++){
        if(students[i].studentId == studentId){
            cout << "\nCurrent Details: \n";
            cout << "First Name: " << students[i].fname << "\n";
            cout << "Last Name: " << students[i].lname << "\n";
            cout << "Course: " << students[i].course << "\n";
            cout << "GPA: " << students[i].gpa << "\n";

            cout << "\nEnter new details: \n";
            cout << "Enter New First Name: ";
            cin >> students[i].fname;
            cout << "Enter New Last Name: ";
            cin >> students[i].lname;
            cout << "Enter New Course: ";
            cin >> students[i].course;
            cout << "Enter New Previous GPA: ";
            cin >> students[i].gpa;
            cout << "Student data updated successfully!.\n";
            return;
        }
    }
    cout << "Student ID not found!.\n";
}

void deleteStudentData(){
    clearScreen();
    if(counter == 0){
        cout << "No student records available.\n";
        return;
    }

    int studentId;
    cout << "Enter Studend ID to delete: ";
    cin >> studentId;

    for(int i = 0; i < counter; i++){
        if(students[i].studentId == studentId){
            for(int j = i; j < counter - 1; j++){
                students[j] = students[j + 1];
            }
            counter--;
            cout << "Student record deleted successfully!.\n";
            return;
        }
    }
}

void displayStudentData(){
    clearScreen();
     if(counter == 0){
        cout << "No student records available.\n";
        return;
    }

    cout << "Select viewing option: \n";
    cout << "1. Alphabetically (last name)\n";
    cout << "2. GPA (ascending order)\n";
    cout << "Enter option: ";
    int choice;
    cin >> choice;

    if(choice == 1){
        for(int i = 0; i < counter; i++){
            for(int j = i + 1; j < counter; j++){
                if(students[i].lname > students[j].lname){
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    } else if(choice == 2){
        for(int i = 0; i < counter; i++){
            for(int j = i + 1; j < counter; j++){
                if(students[i].gpa > students[j].gpa){
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    } else {
        cout << "Invalid option. Please try again.\n";
        return;
    }

    cout << "Student Records:\n";
    cout << "ID | First Name \t| Last Name \t| Course \t| GPA\n";
    for(int i = 0; i < counter; i++){
        cout << students[i].studentId << " | "
             << students[i].fname << " \t\t| "
             << students[i].lname << " \t| "
             << students[i].course << " \t| "
             << students[i].gpa << "\n";
    }
}

int main(){
    int choice;
    while(true){
        clearScreen();
        cout << "Student Management System\n";
        cout << "[1] Add Student\n";
        cout << "[2] Edit Student\n";
        cout << "[3] Delete Student\n";
        cout << "[4] View Student\n";
        cout << "[5] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                addStudentData();
                break;
            case 2:
                editStudentData();
                break;
            case 3:
                deleteStudentData();
                break;
            case 4:
                displayStudentData();
                break;
            case 5:
                cout << "Exiting the program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        getch();
    }
}
