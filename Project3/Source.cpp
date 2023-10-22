#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequency; // Map to store item frequencies

public:
    // Read in data from file and get frequencies 
    void readDataFromFile(const string& filename) {
        ifstream inputFile(filename);
        string item;

        if (inputFile.is_open()) {
            while (getline(inputFile, item)) {
                itemFrequency[item]++;
            }
        }

        inputFile.close();
    }

    // Get the frequency of an item
    int getItemFrequency(const string& item) {
        return itemFrequency[item];
    }

    // Print all frequencies
    void printItemFrequencies() {
        for (const auto& entry : itemFrequency) {
            cout << entry.first << ": " << entry.second << endl;
        }
    }

    // Print a histogram
    void printItemHistogram() {
        for (const auto& entry : itemFrequency) {
            cout << entry.first << " ";
            for (int i = 0; i < entry.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    // Read in data from .txt  file
    ItemTracker tracker;
    tracker.readDataFromFile("D:\\Visual Studio\\Programming Langs\\Project3\\CS210_Project_Three_Input_File.txt");

    string choice;
    while (true) {
        // Main menu
        cout << "Menu:" << endl;
        cout << "1. Look up item frequency" << endl;
        cout << "2. Print item frequencies" << endl;
        cout << "3. Print item histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Look up frequeny by getting user input
        if (choice == "1") {
            string item;
            cout << "Enter the item: ";
            cin >> item;
            cout << "Frequency: " << tracker.getItemFrequency(item) << endl;
        }
        // Call pringItemFrequencies
        else if (choice == "2") {
            tracker.printItemFrequencies();
        }
        // Call printItemHistogram
        else if (choice == "3") {
            tracker.printItemHistogram();
        }
        // End loop
        else if (choice == "4") {
            break;
        }
        // User input validation: if they type something other than 1 - 4
        else {
            cout << "Invalid choice. Please select again." << endl;
        }
    }

    return 0;
}