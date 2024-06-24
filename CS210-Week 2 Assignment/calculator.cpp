#include <iostream>
using namespace std;

int main() { // Changed void to int for main function
    char statement[100];
    int op1, op2;
    char operation;
    char answer = 'Y'; // Corrected declaration of answer by using single quotes for character assignment
    while (answer == 'Y' || answer == 'y') { // Fixed syntax error in the while loop condition
        cout << "Enter expression" << endl;
        cin >> op1 >> operation >> op2;
        if (operation == '+') // Removed semicolon at the end of if statements
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl; // Fixed wrong shift operator '>>' to '<<'
        if (operation == '-') // Removed semicolon at the end of if statements
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; // Fixed wrong shift operator '>>' to '<<'
        if (operation == '*') // Fixed missing semicolon
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; // Fixed division symbol '/' to '*' for multiplication
        if (operation == '/') // Fixed missing semicolon
            cout << op1 << " / " << op2 << " = " << static_cast<double>(op1) / op2 << endl; // Casted op1 to double to ensure correct division for double inputs

        cout << "Do you wish to evaluate another expression? (Y/N)" << endl; // Added prompt for Y/N
        cin >> answer;
    }
    cout << "Program Finished." << endl; // Added a message to indicate program termination
    return 0; // Indicate successful program termination
}
