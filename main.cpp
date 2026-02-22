// COMSC-210 | Lab 13 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // for sort(), find(), max_element(), min_element()
#include <numeric>  // for accumulate()
using namespace std;

const int MAX_DAYS = 30;
const string FILE_LOCATION = "C:\\Users\\lordj\\COMSC-210\\projects\\210-lab-12\\text.txt";

void populateArray(string, vector<double>&, vector<string>&, vector<int>&);

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    return 0;
}

void populateArray(string fLocation, vector<double>&tVector, vector<string>&invArgArray){
    ifstream fileData;
    string text;
    static double temperatureVal = 0;

    fileData.open(fLocation);
    if (fileData.good()){
        static int i = 0;
        static int offset = 2;
        static int currentLine = 1;

        while(getline(fileData, text) && i/offset < MAX_DAYS){
            if (text.empty()){
                currentLine++;
                continue;
            }

            try{
                temperatureVal = stod(text);
                tVector.push_back(temperatureVal);
                currentLine++;
                i += offset;

            } catch(const std::exception& e){
                invArgArray.at(i) = text;
                invArgArray.at(i + 1) = currentLine;

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