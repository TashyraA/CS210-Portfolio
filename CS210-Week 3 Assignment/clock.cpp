/*******************************
 * Name: Tashyra Adams
 * Date: March 24,2024
 * Class: 3-3 Project One Submission
 *******************************/

#include <iostream>
#include <iomanip>
#include <ctime>

// Class definition for Clock
class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor to initialize the clock with the current system time
    Clock() {
        time_t now = time(0);        // Get current system time
        tm* localTime = localtime(&now);   // Convert to local time

        // Set hours, minutes, and seconds based on current time
        hours = localTime->tm_hour;
        minutes = localTime->tm_min;
        seconds = localTime->tm_sec;
    }

    // Function to display time in 12-hour format
    void display12HourFormat() {
        std::cout << "12-Hour Clock" << std::endl;
        // Format and print hours, minutes, and seconds
        std::cout << std::setw(2) << std::setfill('0') << (hours % 12 == 0 ? 12 : hours % 12) << ":" 
                  << std::setw(2) << std::setfill('0') << minutes << ":" 
                  << std::setw(2) << std::setfill('0') << seconds << (hours < 12 ? " AM" : " PM") << std::endl;
    }

    // Function to display time in 24-hour format
    void display24HourFormat() {
        std::cout << "24-Hour Clock" << std::endl;
        // Format and print hours, minutes, and seconds
        std::cout << std::setw(2) << std::setfill('0') << hours << ":" 
                  << std::setw(2) << std::setfill('0') << minutes << ":" 
                  << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }

    // Function to add one hour to the clock
    void addHour() {
        hours = (hours + 1) % 24;   // Increment hours, and wrap around at 24
    }

    // Function to add one minute to the clock
    void addMinute() {
        minutes = (minutes + 1) % 60;   // Increment minutes, and wrap around at 60
        if (minutes == 0) {
            addHour(); // If minutes overflow, increment hour
        }
    }

    // Function to add one second to the clock
    void addSecond() {
        seconds = (seconds + 1) % 60;   // Increment seconds, and wrap around at 60
        if (seconds == 0) {
            addMinute(); // If seconds overflow, increment minute
        }
    }
};

// Main function
int main() {
    Clock clock12, clock24;     // Create instances of Clock for 12-hour and 24-hour clocks
    int choice;                 // Variable to store user's choice

    // Main loop for user interaction
    do {
        // Display menu options
        std::cout << "\n1. Display Clocks\n"
                  << "2. Add One Hour\n"
                  << "3. Add One Minute\n"
                  << "4. Add One Second\n"
                  << "5. Exit Program\n";

        // Prompt user for choice
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Switch case to handle user's choice
        switch (choice) {
            case 1:
                clock12.display12HourFormat();      // Display 12-hour clock
                std::cout << std::endl;
                clock24.display24HourFormat();      // Display 24-hour clock
                break;
            case 2:
                clock12.addHour();                  // Add one hour to both clocks
                clock24.addHour();
                std::cout << "One hour added to both clocks.\n";
                break;
            case 3:
                clock12.addMinute();                // Add one minute to both clocks
                clock24.addMinute();
                std::cout << "One minute added to both clocks.\n";
                break;
            case 4:
                clock12.addSecond();                // Add one second to both clocks
                clock24.addSecond();
                std::cout << "One second added to both clocks.\n";
                break;
            case 5:
                std::cout << "Exiting program...\n";    // Exit program
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";   // Handle invalid input
        }
    } while (choice != 5);  // Continue loop until user chooses to exit

    return 0;   // Return 0 to indicate successful completion of program
}
