/*
 * Name: Omar Sandoval
 * ID: 911121957
 * Email: omgar@mail.sfsu.edu
 * Compiler: g++
 */

#include <iostream>
using namespace std;

int main()
{
    int row, col, sum = 0;      // initialize values 

    // prompt user to enter size of their matrix.
    cout << "Please enter the size of your SQUARE matrix. (e.g. 5 5 would be 5 rows and 5 columns, etc.)" << endl;

    // save users input
    cin >> row;
    cin >> col;

    // initialize the users matrix and arrays we will use for the sums.
    int matrix[row][col];

    // check if the user entered a square matrix size.
    while (row != col) {
        cout << "You did not enter a square matrix." << endl;
        cout << "Please enter the size of a SQUARE matrix." << endl;
        cin >> row;
        cin >> col;
    }

    // initialize variables
    int rowTotal[row];
    int colTotal[col]; 
    int diagTotal[1];
    int x, y;
    bool rowsEqual = 0, colsEqual = 0;
    bool diagonalsEqual = 0, rowAndColEqual = 0;

    // prompt user to enter their desired matrix.
    cout << "Please enter the elements of your matrix." << endl; 

    // save values the user inputs as their matrix.
    for (x = 0; x < row; x++) {
        for (y = 0; y < col; y++) {
            cin >> matrix[x][y];
        }
    }

    // sum for each row.
    for (x = 0; x < row; x++) {
        for (y = 0; y < col; y++) {
            sum += matrix[x][y];    // keep a running sum of each value
        }
        rowTotal[x] = sum;          // store each sum into an array
        sum = 0;
    }

    // sum for each column.
    for (y = 0; y < col; y++) {
        for (x = 0; x < row; x++) {
            sum += matrix[x][y];    // keep a running sum of each value
        }
        colTotal[y] = sum;          // store each sum into an array.
        sum = 0;                    // reset sum to 0.
    }

    // sum for each diagonal.
    if (row == col) {
        sum = 0;
        for (x = 0; x < row; x++) {
            sum += matrix[x][x];
        }
        diagTotal[0] = sum;
        sum = 0;
        for (x = 0; x < col; x++) {
            sum += matrix[x][x];
        }
        diagTotal[1] = sum;
        sum = 0;
    }

    // show user the sum of the rows.
    cout << "Sum for each row" << endl;
    for (x = 0; x < row; x++) { 
        cout << rowTotal[x] << "\n";
    }

    // show user the sum of the columns.
    cout << "Sum for each column" << endl;
    for (x = 0; x < col; x++) {
        cout << colTotal[x] << "\n";
    }

    // show user the sum of the diagonal.
    cout << "Sum for each diagonal" << endl;
    for (x = 0; x <= 1; x++) {
        cout << diagTotal[x] << "\n";
    }

    // check if sum for all rows are equal to each other.
    // start from 1 because checking if the first column is equal
    //      to itself would be redundant
    for (x = 1; x < row; x++) {

        // check if sum of one row is equal to all other rows.
        if (rowTotal[0] == rowTotal[x]) {
            cout << "Row " << x << " is equal!" << endl;
            rowsEqual = true;
        } else {
            cout << "Row " << x << " is not equal!" << endl;
            rowsEqual = false;
        }
    }

    // check if sum for all columns are equal to each other.
    // start from 1 because checking if the first column is equal
    //      to itself would be redundant
    for (x = 1; x < col; x++) {

        // check if sum of one column is equal to all other columns.
        if (colTotal[0] == colTotal[x]) {
            cout << "Column " << x << " is equal!" << endl;
            colsEqual = true;
        } else {
            cout << "Column " << x << " is not equal!" << endl;
            colsEqual = false;
        }
    }

    // check if row sum and column sum are equal.
    for (x = 0; x < row; x++) {
            if (rowTotal[x] == colTotal[x]) {
                cout << "Row and column sum are equal!" << "\n";
                rowAndColEqual = true;;
            } else {
                cout << "Row and column sum are NOT equal!" << "\n";
                rowAndColEqual = false;
            }
    }

    // check if diagonal sum is equal to row sum and column sum.
    for (x = 0; x <= 1; x++) {
        if (rowTotal[x] == diagTotal[0] && colTotal[x] == diagTotal[0]) {
            if (rowTotal[x] == diagTotal[0] && colTotal[x] == diagTotal[1]) {
                cout << "Diagonal sum is equal to column sum and row sum!" << "\n";
                diagonalsEqual = true;
            } else {
                cout << "Diagonal sum is NOT equal to column sum or row sum." << "\n";
                diagonalsEqual = false;
            }
        }
    }

    // if row, column and diagonal sum is equal, MAGIC SQUARE!
    if (rowsEqual == true && colsEqual == true && rowAndColEqual == true && diagonalsEqual == true) {
        cout << "Your matrix is a magic square!" << "\n";
    } else {
        cout << "Your matrix is NOT a magic square!" << "\n";
    }
    return 0;
}