/*
 * Name: Omar Sandoval
 * ID: 911121957
 * Email: omgar@mail.sfsu.edu
 * Compiler: g++
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

//struct prose {
//  vector<string> proseVector;
//  vector<string> tempVector(100);
//  vector<int> countVector(100);
//};

int main()
{

    int i = 0, j = 0, k = 0, l = 0, count = 0;
    string temp;
 
    cout << "This program will return all words in your given statement and their count!\n\n";
 
    vector<string> proseVector;
    vector<string> tempVector(100);
    vector<int> countVector(100);
    char delimiters[] = {',', '.', '?', ';', ' '};

    // read users statement.
    cout << "Please enter your statement: " << endl;
    string prose;
    getline(cin,prose);

    // convert statement into a stream
    stringstream proseSS;
    proseSS << prose;
    cout << proseSS << endl;

    // Opens text file
    // prose.open("prose.txt") 

    //Check for and erases certain delimiters; inserts revised string back into vector
    while(proseSS >> temp) {
        for(i = 0; i < sizeof(delimiters); i++) {
            //Finds location of unwanted delimiters then removes them
            int location = temp.find(delimiters[i]);
            if(location != string::npos) {
                temp.erase(location);
                proseVector.push_back(temp);
            }
        }
        proseVector.push_back(temp);
    }
 
    //Changes uppercase letters into lowercase
    for(i = 0; i < proseVector.size(); i++) {
        transform(proseVector[i].begin(), proseVector[i].end(), proseVector[i].begin(),(int (*)(int))tolower);
    }
 
    //First word in proseVector is copied to tempVector to begin comparisons in the next for loop
    tempVector[0] = proseVector[0];
 
    //Words already in tempVector will have their count increased and new words are added
    for(i = 0, j = (i + 1), k = 0, l = 0; l < (proseVector.size() - 1); l++, j++) {
        if(tempVector[0] == proseVector[0]) {
            countVector[0] = 1;
            if(tempVector[i] == proseVector[j]) {
                ++count;
            } else {
                ++i;
                ++k;
                count = 1;
            }
            tempVector[i] = proseVector[j];
            countVector[k] = count;
        }
    }
 
    //Prints out words and their occurrence
    cout << "Words" << "\t\t" << "Occurrences\n\n";
    for(i = 0; i < tempVector.size(); i++) {
        if(countVector[i] != 0) {
            cout << tempVector[i] << "\t\t" << countVector[i] << endl;
        }
    }
}