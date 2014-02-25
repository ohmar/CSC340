/*
* Name: Omar Sandoval
* ID: 911121957
* Email: omgar@mail.sfsu.edu
* Compiler: g++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	// Initialize variables
	string inputFile1;
	string inputFile2;

	// Initialize stream of file1 and file 2
	ifstream file1;
	ifstream file2;

	// Ask user to input the name of their first file.
	cout << "Please enter the name of your first file." << endl;
	cin >> inputFile1;

	// Ask user to input the name of their second file.
	cout << "Please enter the name of your second file." << endl;
	cin >> inputFile2;

	// Open all three files.
	file1.open(inputFile1.c_str());
	file2.open(inputFile2.c_str());
	ofstream fout("output.txt");

	// if files did not open, print error.
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

		// if the first integer is less than or equal to the second integer.
		if (data1 <= data2) {
			fout << data1 << endl; // send first integer to our output file.
			file1 >> data1;        // get new integer.
			// else print out the second integer to output.
		}
		else {
			fout << data2 << endl;
			file2 >> data2;
		}
	}

	// Print out the rest of file1 if not yet complete.
	while (!file1.fail()) {
		fout << data1 << endl;
		file1 >> data1;
	}

	// Print out the rest of file2 if not yet complete.
	while (!file2.fail()) {
		fout << data2 << endl;
		file2 >> data2;
	}
}