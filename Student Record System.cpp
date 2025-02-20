#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    double gpa;

    Student(int id, string name, double gpa) : id(id), name(name), gpa(gpa) {}

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
    }
};

void addStudent(vector<Student>& students) {
    int id;
    string name;
    double gpa;

    cout << "Enter student ID: ";
    cin >> id;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter student GPA: ";
    cin >> gpa;

    students.push_back(Student(id, name, gpa));
}

void displayStudents(const vector<Student>& students) {
    cout << "\nStudent Records:" << endl;
    for(const auto& s : students) {
        s.display();
    }
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Record System Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                cout << "Exiting system." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while(choice != 3);

    return 0;
}
