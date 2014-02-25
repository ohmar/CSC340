/*
 * Name: Omar Sandoval
 * ID: 911121957
 * Email: omgar@mail.sfsu.edu
 * Compiler: g++
 */

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file1("textFile1.txt"); // open all three files.
    ifstream file2("textFile2.txt");
    ofstream fout("output.txt");

    // if files fî not open, print error.
    if (!file1.good() || !file2.good() || !fout.good()) {
        cout << "Error opening file(s)" << endl;
        return 0;
    }

    // initialize variables.
    int data1;
    int data2;

    // get data from two text files.
    file1 >> data1;
    file2 >> data2;

    // while our two text files are still open
    while (!file1.fail() && !file2.fail()) {

        // if the first integer is less than or equal to the second integer
        if (data1 <= data2) {
            fout << data1 << endl; // send first integer to our output file.
            file1 >> data1;        // get new integer
        // else print out the second integer to output.
        } else {
            fout << data2 << endl;
            file2 >> data2;
        }
    }

    while (!file1.fail()) {
        fout << data1 << endl;
        file1 >> data1;
    }

    while (!file2.fail()) {
        fout << data2 << endl;
        file2 >> data2;
    }
}