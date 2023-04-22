#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class ItemTracker {
public:

    void readDataFile();
    void displayMenu();

private:

    map<string, int> itemFrequency;    // store in a map
    void searchItem();
    void printFrequencyList();
    void printHistogram();
};

void ItemTracker::readDataFile() {
    ifstream dataFile("CS210_Project_Three_Input_File.txt");    // open the .txt file
    string item;
    while (dataFile >> item) {
        itemFrequency[item]++;
    }
    dataFile.close();    // close the data file
}

void ItemTracker::displayMenu() {    // display the menu options and get user input
    int choice;
    do {
        cout << "\nMenu\n";
        cout << "1. Search for an item\n";
        cout << "2. Print the frequency list\n";
        cout << "3. Print a histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            searchItem();
            break;
        case 2:
            printFrequencyList();
            break;
        case 3:
            printHistogram();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

void ItemTracker::searchItem() {  // Option 1 - search for an item
    string item;
    cout << "Enter the item to search for: ";
    cin >> item;
    if (itemFrequency.find(item) == itemFrequency.end()) {
        cout << item << " not found.\n";
    }
    else {
        cout << "Frequency of " << item << " = " << itemFrequency[item] << endl;
    }
}

void ItemTracker::printFrequencyList() {     // Option 2 - display the frequency list
    cout << "Frequency list:\n";
    for (auto const& item : itemFrequency) {
        cout << item.first << " " << item.second << endl;
    }
}

void ItemTracker::printHistogram() {      // Option 1 - display the histogram list
    cout << "Histogram:\n";
    for (auto const& item : itemFrequency) {
        cout << item.first << " ";
        for (int i = 0; i < item.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

ofstream printFrequencyList("frequency.dat");

int main() {
    ItemTracker itemTracker;
    itemTracker.readDataFile();
    itemTracker.displayMenu();
    return 0;
}
