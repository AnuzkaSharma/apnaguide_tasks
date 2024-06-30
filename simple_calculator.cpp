//
// Created by Lenovo on 6/30/2024.
//

#include <iostream>

using namespace std;

// Function to add two numbers
double add(double num1, double num2) {
    return num1 + num2;
}

// Function to subtract two numbers
double subtract(double num1, double num2) {
    return num1 - num2;
}

// Function to multiply two numbers
double multiply(double num1, double num2) {
    return num1 * num2;
}

// Function to divide two numbers
double divide(double num1, double num2) {
    if (num2 == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return num1 / num2;
}



int main() {
    int choice;
    double num1, num2, result;

    cout << "Simple Calculator" << endl;
    cout << "-----------------" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice!= 5) {
        switch (choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = add(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 2:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = subtract(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 3:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = multiply(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 4:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = divide(num1, num2);
                cout << "Result: " << result << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Enter your choice: ";
        cin >> choice;
    }

    return 0;
}
