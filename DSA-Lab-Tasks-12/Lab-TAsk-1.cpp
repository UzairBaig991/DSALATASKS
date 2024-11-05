#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];  // Set the first element as pivot
    int i = low + 1;       // Start from the element next to the pivot

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);  // Place the pivot element in its correct position
    return i - 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(const vector<int> &arr) {  // Function to print array elements
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {33, 12, 49, 52, 3, 75, 29, 41, 6, 19};
    int n = arr.size();
    cout << "Original Array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    printArray(arr);
    return 0;
}
