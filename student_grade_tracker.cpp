//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Student {
    string name;
    int id;
    vector<double> grades;
    double average;

    Student() : id(0), average(0.0) {}
};

vector<Student> students;

void addStudent() {
    Student student;
    cout << "Enter student name: ";
    cin >> student.name;
    cout << "Enter student ID: ";
    cin >> student.id;
    cout << "Enter number of assignments/exams: ";
    int numGrades;
    cin >> numGrades;
    for (int i = 0; i < numGrades; i++) {
        double grade;
        cout << "Enter grade " << (i + 1) << ": ";
        cin >> grade;
        student.grades.push_back(grade);
    }
    double sum = 0;
    for (auto grade : student.grades) {
        sum += grade;
    }
    student.average = sum / static_cast<double>(student.grades.size());
    students.push_back(student);
}

void calculateGrades() {
    for (auto &student : students) {
        cout << "Student " << student.name << " (" << student.id << "): ";
        cout << "Average grade: " << student.average << endl;
    }
}

void calculateClassAverage() {
    double sum = 0;
    for (auto &student : students) {
        sum += student.average;
    }
    double classAverage = sum / static_cast<double>(students.size());
    cout << "Class average: " << classAverage << endl;
}

void displayClassToppers() {
    vector<Student> toppers = students;
    sort(toppers.begin(), toppers.end(), [](const Student &a, const Student &b) {
        return a.average > b.average;
    });
    cout << "Class toppers:" << endl;
    for (int i = 0; i < 3 && i < toppers.size(); i++) {
        cout << (i + 1) << ". " << toppers[i].name << " - Average: " << toppers[i].average << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "Student Grade Tracker" << endl;
        cout << "---------------------" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Calculate grades" << endl;
        cout << "3. Calculate class average" << endl;
        cout << "4. Display class toppers" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                calculateGrades();
                break;
            case 3:
                calculateClassAverage();
                break;
            case 4:
                displayClassToppers();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cout << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}


// Created by Lenovo on 6/30/2024.
//
