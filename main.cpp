// COMSC-210 | Lab 13 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // for sort(), find(), max_element(), min_element()
#include <numeric>  // for accumulate()
using namespace std;

const int MAX_DAYS = 30;
const string FILE_LOCATION = "C:\\Users\\lordj\\COMSC-210\\projects\\210-lab-12\\text.txt";

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
        static int i = 0;
        static int currentLine = 1;

        while(getline(fileData, text)){
            i++;
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
    //  && i <= MAX_DAYS
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
}