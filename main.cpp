// COMSC-210 | Lab 13 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // for sort(), find(), max_element(), min_element()
#include <numeric>  // for accumulate()
using namespace std;

const int MAX_DAYS = 30;
const string FILE_LOCATION = " ";

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

    fileData.open(fLocation);
    if (fileData.good()){
        static int i = 0;
        static int offset = 2;
        static int line = 1;
        static double temperatureVal = 0;

        while(getline(fileData, text) && i/offset < MAX_DAYS){
            if (text.empty()){
                line++;
                continue;
            }

            try{
                temperatureVal = stod(text);
            } catch(const std::exception& e){

                line++;
                continue;
            }
            
            
            
        }
    }
}