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

//////////////////////////////////////////////////////////////////
// More Complex Sorting Algorithms
//////////////////////////////////////////////////////////////////

void Merge (vector<int>& arr, int left, int mid, int right) {

    int first1 = left;
    int first2 = mid + 1;
    int last1 = mid;
    int last2 = right;

    vector<int> temp;
    int tempIndex = 0;

    while (first1 <= last1 && first2 <= last2) {

        if (arr[first1] <= arr[first2]) temp.push_back(arr[first1++]);
        else temp.push_back(arr[first2++]);

    }

    while (first1 <= last1) temp.push_back(arr[first1++]);
    while (first2 <= last2) temp.push_back(arr[first2++]);

    for (int i = left; i <= right; i++) {
        arr[i] = temp[tempIndex++];
    }

}

void MS (vector<int>& arr, int left, int right) {

    if (left < right) {

        int mid = (left + right) / 2;

        MS(arr, 0, mid);
        MS(arr, mid + 1, right);

        Merge(arr, left, mid, right);

    }

}

void MergeSort (vector<int>& arr) {

    MS(arr, 0, arr.size() - 1);

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

    MergeSort(arr);

    printVector(arr);

    return 0;

}