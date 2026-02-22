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
        // static int i = 0;
        // static int offset = 2;
        static int currentLine = 1;

        while(getline(fileData, text) && currentLine <= MAX_DAYS){
            if (text.empty()){
                currentLine++;
                continue;
            }

            try{
                temperatureVal = stod(text);
                tVector.push_back(temperatureVal);
                currentLine++;
                // i += offset;

            } catch(const std::exception& e){
                invArgArray.push_back(text + " at line " + to_string(currentLine));

                currentLine++;
                // cout << "CL: " << currentLine << "i: " << i << endl;
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
    for (double val : tVector) cout << val << " "; cout << endl;
}