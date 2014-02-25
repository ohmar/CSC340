/*
* Name: Omar Sandoval
* ID: 911121957
* Email: omgar@mail.sfsu.edu
* Compiler: g++, Linux
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

void selection_sort(vector<double> & data) {
    int length = data.size();

    for ( double i = 0; i < length; ++i ) {
        double min = i;
        for ( double j = i+1; j < length; ++j ) {
            if ( data[j] < data[min] ) {
                min = j;
            }
        }

        if ( min != i ) {
            double tmp = data[i];
            data[i] = data[min];
            data[min] = tmp;
        }
    }
}

void insertion_sort( vector<double> & data )
{
    int length = data.size();

    for ( double i = 1; i < length; ++i ) {
        bool inplace = true;
        double j = 0.0;
        for ( ; j < i; ++j ) {
            if ( data[i] < data[j] ) {
                inplace = false;
                break;
            }
        }

        if ( !inplace ) {
            double save = data[i];
            for ( double k = i; k > j; --k ) {
                data[k] = data[k-1];
            }
            data[j] = save;
        }
    }
}

int main() {

	double input;
	cout << "Please enter your vector; enter E when finished." << endl;

	vector<double> data;

	while(cin >> input) {
    	data.push_back(input);
	}
	cin.clear();
	cin.ignore(1, 'E');

	cout << "Please choose which sorting algorithm to use:" << endl;
	cout << "(1) for Selection Sort" << endl;
	cout << "(2) for Insertion Sort" << endl;
	int chosen;
    cin >> chosen;

	if (chosen == 1) {
		cout << "You chose selection sort!" << endl;
		selection_sort(data);
	} else if (chosen == 2) {
		cout << "You chose insertion sort!" << endl;
		insertion_sort(data);
	} else {
		cout << "Invalid input!" << endl;
	}

	for (vector<double>::iterator it = data.begin(); it != data.end(); ++it)
		cout << *it << ' ';
	cout << endl;
	return 0;

}
