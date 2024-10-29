#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int arr1[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Original Array 1: ";
    printArray(arr1, n1);
    insertionSort(arr1, n1);
    cout << "Sorted Array 1: ";
    printArray(arr1, n1);

    int arr2[] = {1, 2, 3, 5, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "\nOriginal Array 2: ";
    printArray(arr2, n2);
    insertionSort(arr2, n2);
    cout << "Sorted Array 2: ";
    printArray(arr2, n2);

    int arr3[] = {29, 10, 14, 37, 13};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "\nOriginal Array 3: ";
    printArray(arr3, n3);
    insertionSort(arr3, n3);
    cout << "Sorted Array 3: ";
    printArray(arr3, n3);

    return 0;
}
