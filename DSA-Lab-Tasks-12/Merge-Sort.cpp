#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    vector<int> leftarr(n1);
    vector<int> rightarr(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftarr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightarr[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftarr[i] <= rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        } else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftarr, if any
    while (i < n1) {
        arr[k] = leftarr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightarr, if any
    while (j < n2) {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int arrsize = arr.size();

    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    mergesort(arr, 0, arrsize - 1);

    cout << "Sorted Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
