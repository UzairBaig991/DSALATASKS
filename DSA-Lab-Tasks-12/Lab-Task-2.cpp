#include <iostream>
#include <vector>
#include <ctime>    

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function with simple time-based "random" pivot selection
int partitionRandom(vector<int> &arr, int low, int high) {
    int RandomIndex = low + (time(0) % (high - low + 1));
    swap(arr[RandomIndex], arr[high]);  
    
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortRandom(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionRandom(arr, low, high);
        quickSortRandom(arr, low, pivotIndex - 1);
        quickSortRandom(arr, pivotIndex + 1, high);
    }
}

// Original partition function using the last element as pivot
int partitionLastElement(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortLastElement(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionLastElement(arr, low, high);
        quickSortLastElement(arr, low, pivotIndex - 1);
        quickSortLastElement(arr, pivotIndex + 1, high);
    }
}

// Function to print array elements
void printArray(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {33, 12, 49, 52, 3, 75, 29, 41, 6, 19};
    vector<int> arr2 = arr1; 

    clock_t startRandom = clock();
    quickSortRandom(arr1, 0, arr1.size() - 1);
    clock_t endRandom = clock();

    cout << "Sorted Array with Time-Based Random Pivot: ";
    printArray(arr1);
    double durationRandom = double(endRandom - startRandom) / CLOCKS_PER_SEC;
    cout << "Execution Time with Time-Based Random Pivot: " << durationRandom << " seconds" << endl;

    clock_t startLast = clock();
    quickSortLastElement(arr2, 0, arr2.size() - 1);
    clock_t endLast = clock();

    cout << "Sorted Array with Last Element Pivot: ";
    printArray(arr2);
    double durationLast = double(endLast - startLast) / CLOCKS_PER_SEC;
    cout << "Execution Time with Last Element Pivot: " << durationLast << " seconds" << endl;

    return 0;
}
