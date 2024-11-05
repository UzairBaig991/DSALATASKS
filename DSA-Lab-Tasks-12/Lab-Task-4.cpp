#include <iostream>
#include <ctime>
using namespace std;

void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
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

void hybridQuickSort(int arr[], int low, int high) {
    if (low < high) {
        // Automatically use insertion sort if subarray size is small
        if (high - low < 10) {
            insertionSort(arr, low, high);
        } else {
            int pivotIndex = partition(arr, low, high);
            hybridQuickSort(arr, low, pivotIndex - 1);
            hybridQuickSort(arr, pivotIndex + 1, high);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 19, 21, 8, 15, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    clock_t start = clock();
    hybridQuickSort(arr, 0, n - 1);
    clock_t end = clock();

    cout << "Sorted Array: ";
    printArray(arr, n);

    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Execution Time: " << duration << " seconds" << endl;

    return 0;
}
