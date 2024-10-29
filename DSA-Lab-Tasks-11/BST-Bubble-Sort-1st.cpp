#include<iostream>
using namespace std;
void bubblesort(int arr[], int n)
{
    for(int i=0 ; i<n-1 ; i++)
    {
        //Last i elements are already sorted
        for(int j=0 ; j<n-i-1 ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//Function to print the array
void printarray(int arr[], int n)
{
    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[] = {11,12,7,17,20,28};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    printarray(arr, n);
    bubblesort(arr, n);
    cout << "Sorted Array: ";
    printarray(arr, n);
    return 0;
}