#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(int fahrenheit) {
    return static_cast<double>((fahrenheit - 32) * 5) / 9;
}

int main() {
    ifstream inFile("FahrenheitTemperature.txt"); // Open input file
    ofstream outFile("CelsiusTemperature.txt");   // Open output file

    if (!inFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1; // Exit program with error code 1
    }

    if (!outFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1; // Exit program with error code 1
    }

    string city;
    int fahrenheit;

    // Read data from input file and write converted data to output file
    while (inFile >> city >> fahrenheit) {
        double celsius = fahrenheitToCelsius(fahrenheit);
        outFile << city << " " << celsius << endl;
    }

    // Close input and output files
    inFile.close();
    outFile.close();

    cout << "Conversion completed successfully." << endl;

    return 0;
}
