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

void populateArray(string fLocation, vector<double>& tVector, vector<string>& invArray, 
                    vector<int>& invLineArray){
    ifstream fileData;
    string text;

    fileData.open(fLocation);
    if (fileData.good()){
        static int i = 0;
        while(getline(fileData, text) && i < MAX_DAYS){}
    }
}