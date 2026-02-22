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


/**
 * @brief - Description of main
 * @return 
*/
int main() {
    vector<double> tempVector;
    vector<string> iArgVector;

    populateVector(FILE_LOCATION, tempVector, iArgVector);
    displayVectorInfo(tempVector);

    return 0;
}

void populateVector(string fLocation, vector<double>&tVector, vector<string>&invArgArray){
    ifstream fileData;
    string text;
    static double temperatureVal = 0;

    fileData.open(fLocation);
    if (fileData.good()){
        static int currentLine = 1;

        while(getline(fileData, text)){
            if (text.empty()){
                currentLine++;
                continue;
            }

            try{
                temperatureVal = stod(text);
                tVector.push_back(temperatureVal);
                currentLine++;

            } catch(const std::exception& e){
                invArgArray.push_back(text + " at line " + to_string(currentLine));

                currentLine++;
                continue;
            }
        }
    } else{
        cout << "\n!File was not found!" << endl << endl;
        return;
    }
    cout << endl;
}

void displayVectorInfo(vector<double>& tVector){
    static int week = 0;
    if (tVector.empty()){
        cout << "!Vector is empty!" << endl;
        return;
    }

    cout << "--- Temperature Data ---" << endl;
    for (double j : tVector) {
        // Display week number at the start of each week
        if (week % 7 == 0) {
            cout << "Week " << week / 7 + 1 << ": ";
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
    // Calculate and display average temperature for each month, or for the month if there is only one month of data
    if (tVector.size() > 30)
        for (int i = 0; i < months; i++){
            cout << "  Average temperature in month " << i + 1 << ": " 
                << accumulate(tVector.begin() + (i * 30), tVector.begin() + 
                                ((i + 1) * 30), 0.0)/30 << "°F" << endl;
        }
    else 
        cout << "  Average temperature in the month: " 
                << accumulate(tVector.begin(), tVector.end(), 0.0)/tVector.size() 
                    << "°F" << endl;
}