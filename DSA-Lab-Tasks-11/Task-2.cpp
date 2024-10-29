#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    // Already sorted array
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "\nAlready Sorted Array 1 : ";
    printArray(arr1, n1);
    bubbleSort(arr1, n1);
    cout << "Sorted Array 1: ";
    printArray(arr1, n1);

    // Reverse sorted array
    int arr2[] = {5, 4, 3, 2, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "\nReverse Sorted Array 2 : ";
    printArray(arr2, n2);
    bubbleSort(arr2, n2);
    cout << "Sorted Array 2: ";
    printArray(arr2, n2);

    // Random unsorted array
    int arr3[] = {3, 1, 4, 1, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "\nRandom Unsorted Array 3: ";
    printArray(arr3, n3);
    bubbleSort(arr3, n3);
    cout << "Sorted Array 3: ";
    printArray(arr3, n3);

    return 0;
}
