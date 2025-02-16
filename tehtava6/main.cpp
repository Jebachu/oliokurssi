#include "Student.h"
#include <vector>
#include <algorithm>

int main() {
    int selection = 0;
    vector<Student> studentList;

    do {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cout << "Exit = 5" << endl;
        cin >> selection;

        switch (selection) {
        case 0: {
            string name;
            int age;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter student age: ";
            cin >> age;
            studentList.push_back(Student(name, age));
            break;
        }
        case 1:
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        case 2:
            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                return a.getName() < b.getName();
            });
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        case 3:
            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                return a.getAge() < b.getAge();
            });
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        case 4: {
            string searchName;
            cout << "Enter student name to find: ";
            cin >> searchName;
            auto it = find_if(studentList.begin(), studentList.end(), [&searchName](const Student& s) {
                return s.getName() == searchName;
            });
            if (it != studentList.end()) {
                it->printStudentInfo();
            } else {
                cout << "Student not found." << endl;
            }
            break;
        }
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Wrong selection, try again." << endl;
            break;
        }
    } while (selection != 5);

    return 0;
}
