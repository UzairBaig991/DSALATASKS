#include <iostream>
#include <vector>
#include <ctime>  // For measuring execution time
using namespace std;

// Merge Sort functions
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1), rightArr(n2);

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

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort functions
int partition(vector<int> &arr, int low, int high) {
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

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Utility function to fill arrays with random values
void fillArray(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand() % 10000;  
    }
}

// Function to test and compare both sorting algorithms
void compareSorts(int size) {
    vector<int> arr1(size);
    fillArray(arr1);  

    vector<int> arr2 = arr1; 
    clock_t start, end;

    // Test Merge Sort
    start = clock();
    mergeSort(arr1, 0, arr1.size() - 1);
    end = clock();
    double mergeSortTime = double(end - start) / CLOCKS_PER_SEC;

    // Test Quick Sort
    start = clock();
    quickSort(arr2, 0, arr2.size() - 1);
    end = clock();
    double quickSortTime = double(end - start) / CLOCKS_PER_SEC;

    // Output the results
    cout << "Array size: " << size << endl;
    cout << "Merge Sort time: " << mergeSortTime << " seconds" << endl;
    cout << "Quick Sort time: " << quickSortTime << " seconds" << endl;
    cout << "-----------------------------\n";
}

int main() {
    srand(time(0)); 

    // Testing with arrays of different sizes
    compareSorts(100);
    compareSorts(1000);
    compareSorts(10000);
    compareSorts(50000);

    return 0;
}
