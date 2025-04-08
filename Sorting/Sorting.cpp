#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;

//////////////////////////////////////////////////////////////////
// Simple Sorting Algorithms
//////////////////////////////////////////////////////////////////

void SelectionSort (vector<int>& arr) {

    for (int i = 0; i < arr.size(); i++) {

        int min = i; // store the index of the smallest number

        for (int j = i; j < arr.size(); j++) {

            if (arr[j] < arr[min]) min = j; // if we find a value smaller than our current smallest value, store that index in our min variable

        }

        // swap the min value with the first unsorted element
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

    }

}

void InsertionSort (vector<int>& arr) {

    for (int i = 1; i < arr.size(); i++) {

        int temp = arr[i];
        int j = i;

        while (j > 0 && arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = temp;

    }

}   

// helper method to print vectors
void printVector (vector<int> arr) {
    cout << "[";
    for (int i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[arr.size() - 1] << "]" << endl;
}

int main () {

    vector<int> arr = {10, 4, 1, 120, 15};

    InsertionSort(arr);

    printVector(arr);

    return 0;

}