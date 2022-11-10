R//==========================================================
//
// Title:      Assignment 3 Selection Sort
// Course:     CSC 3110
// Lab Number:
// Author:     Mizanul Haque
// Date:      10/13/22
// Description:
//  This program uses selection sort to take an array of numbers and reorganie them through using selection sort to put them in 
// corret order.
//
// 
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type

using namespace std; // So "std::cout" may be abbreviated to "cout"

// Print the array
void printArray(int arr[], const int n) {
    for (int k = 0; k < n - 1; k++)
        cout << arr[k] << " ";
    cout << arr[n - 1] << '\n';
}

// Selection sort function to swap elements and put them in order
void selectionSort(int arr[], const int n) {
    int i, j,   // loop variables
        index,  // index of the minimum element
        t,      // temporal
        count (0);  // count swaps

    for (i = 0; i < n - 1; i++) {
        index = i;
        // Find minimum
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[index])
                index = j;
        }
        if (i != index) {
            // Swap elements
            t = arr[index];
            arr[index] = arr[i];
            arr[i] = t;
            
            count++;
            
            cout << "Swap: ";
            printArray(arr, n);
        }
    }

    cout << count << " swaps" << endl;
}


int main() {
    srand(time(NULL));

    constexpr int n = 25;   // Length of the array
    int arr[n];     // Array
    
    // Filling array with random numbers
    for (int k = 0; k < n; k++) {
        arr[k] = rand() % 100;
    }

    cout << "Unsorted Arrays: ";
    printArray(arr, n);

    selectionSort(arr, n);  // Sort the array

    cout << "Sorted Arrays: ";
    printArray(arr, n);

}

