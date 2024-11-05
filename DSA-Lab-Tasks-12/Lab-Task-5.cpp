#include <iostream>
#include <vector>
using namespace std;

// Merge function for Merge Sort
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> leftArr(n1), rightArr(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort function
void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Utility function to print the array
void printArray(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Testing different arrays
void testMergeSort() {
    vector<vector<int>> testArrays = {
        {12, 11, 13, 5, 6, 7},
        {38, 27, 43, 3, 9, 82, 10},
        {4, 2, 6, 5, 7, 9, 1, 3},
        {8, 3, 7, 4, 2, 6, 5, 1},
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
    };

    for (int i = 0; i < testArrays.size(); i++) {
        cout << "Original Array " << i + 1 << ": ";
        printArray(testArrays[i]);

        mergeSort(testArrays[i], 0, testArrays[i].size() - 1);

        cout << "Sorted Array " << i + 1 << ": ";
        printArray(testArrays[i]);
        cout << "-----------------------------\n";
    }
}

int main() {
    testMergeSort();
    return 0;
}
