// COMSC-210 | Lab 13 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // for sort(), find(), max_element(), min_element()
#include <numeric>  // for accumulate()
#include <cmath>    // for round()
using namespace std;

const int MAX_DAYS = 30;
const string FILE_LOCATION = "C:\\Users\\lordj\\COMSC-210\\projects\\210-lab-13\\text.txt";

void populateVector(string, vector<double>&, vector<string>&);
void displayVectorInfo(vector<double>&);
void displayInvalidVector(vector<string>&);

/**
 * @brief Reads a text file filled with temperature data, populates an array with it
 *        while keeping track of invalid entries and their line, then displays the array
 *        data and invalid entries.
*/
int main() {
    vector<double> tempVector;
    vector<string> iArgVector;

    populateVector(FILE_LOCATION, tempVector, iArgVector);
    displayVectorInfo(tempVector);
    displayInvalidVector(iArgVector);

    // Clear Vectors for next data set
    tempVector.clear();
    iArgVector.clear();

    return 0;
}

/**
 * @brief Reads a text file, populates an array with it while keeping track of invalid
 *        entries and their line.
 * @param fileLoaction The location of the text file to read from
 * @param tVector The vector to hold the temperature data
 * @param iDatArray The vector to hold the invalid entries and lines
*/
void populateVector(string fLocation, vector<double>&tVector, vector<string>&iDatArray){
    ifstream fileData;
    string text;
    // Variable to hold the converted temperature value
    static double temperatureVal = 0;

    fileData.open(fLocation);
    // Check if file was opened successfully
    if (fileData.good()){
        // Variable to keep track of the current line number in the file
        static int currentLine = 1;

        while(getline(fileData, text)){
            // If line is empty, skip to next line
            if (text.empty()){
                currentLine++;
                continue;
            }

            try{
                // See if data can be converted to double
                temperatureVal = stod(text);
                tVector.push_back(temperatureVal);
                currentLine++;

            } catch(const std::exception& e){
                // Add Invalid entry and line number to iDatArray
                iDatArray.push_back(text + " - at line: " + to_string(currentLine));

                currentLine++;
                continue;
            }
        }
    } else{
        cout << "\n!File was not found!" << endl << endl;
        return;
    }
}

/**
 * @brief Displays the data in the array, as well as the hottest day, coldest day, and 
 *        average temperature.
 * @param tVector The array to hold the temperature data
*/
void displayVectorInfo(vector<double>& tVector){
    static int week = 0;

    // End function if array is empty
    if (tVector.empty()){
        cout << "!Vector is empty!" << endl;
        return;
    }

    cout << "\n--- Temperature Data ---" << endl;
    // loop through array and display data per week
    for (double j : tVector) {
        // Display week number at the start of each week
        if (week % 7 == 0) {
            cout << " Week " << week / 7 + 1 << ": ";
        }
        cout << j << ", ";
        week++;
        // If week is over, start new line
        if (week % 7 == 0) {
            cout << "\n";
        }
    };

    cout << "\n  Hottest day: " 
        << *max_element(tVector.begin(), tVector.end()) << "°F" << endl;
    cout << "  Coldest day: " 
        << *min_element(tVector.begin(), tVector.end()) << "°F" << endl;

    // Calculate how many months of data there are
    static int months =  ceil(tVector.size() / 30.0);
    // Calculate and display average temperature (If multiple months)
    if (tVector.size() > 30)
        for (int i = 0; i < months; i++){
            cout << "  Average temperature in month " << i + 1 << ": " 
                << accumulate(tVector.begin() + (i * 30), tVector.begin() + 
                                ((i + 1) * 30), 0.0)/30 << "°F" << endl;
        }
    // calculate and display average temperature (If only one month)
    else 
        cout << "  Average temperature in the month: " 
                << accumulate(tVector.begin(), tVector.end(), 0.0)/tVector.size() 
                    << "°F" << endl;
}

/**
 * @brief Displays the invalid entries in the array, as well as their line number.
 * @param iDatArray The array to hold the invalid entries and their numbers
*/
void displayInvalidVector(vector<string>& iDatArray){
    cout << "\n--- Invalid Data ---" << endl;
    // loop throguh invalid data array and display data and line number of each entry
    for (string j : iDatArray) {
        cout << "  " << j << endl;
    }
}