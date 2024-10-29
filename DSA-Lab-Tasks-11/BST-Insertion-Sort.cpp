#include<iostream>
using namespace std;

void insertionsort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        // Move elements of array[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) 
        { 
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printarray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    printarray(arr, n);
    insertionsort(arr, n);
    cout << "Sorted Array: ";
    printarray(arr, n);
    return 0;
}
