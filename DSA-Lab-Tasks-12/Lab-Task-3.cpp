#include <iostream>
#include <vector>
#include <ctime>    
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
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

// Function to initialize an array with random values
void fillArrayWithRandomValues(vector<int> &arr, int size) {
    srand(time(0));  
    for (int i = 0; i < size; i++) {
        arr.push_back(rand() % 100000);  
    }
}

void measurePerformance(int arraySize) {
    vector<int> arr;
    fillArrayWithRandomValues(arr, arraySize);

    // Measuring execution time for QuickSort
    clock_t start = clock();
    quickSortLastElement(arr, 0, arr.size() - 1);
    clock_t end = clock();

    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Array Size: " << arraySize << " | Execution Time: " << duration << " seconds" << endl;
}

int main() {
    cout << "QuickSort Performance Measurement\n";

    // Measure and print performance for different array sizes
    measurePerformance(100);     // Test with 100 elements
    measurePerformance(1000);    // Test with 1,000 elements
    measurePerformance(10000);   // Test with 10,000 elements

    return 0;
}
