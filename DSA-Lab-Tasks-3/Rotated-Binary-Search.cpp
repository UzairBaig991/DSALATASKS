#include <iostream>
using namespace std;
int rotatedBinarySearch(int arr[], int left, int right, int target) 
{
    if (left > right) 
    {
        return -1; 
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) 
    {
        return mid;
    }
    if (arr[left] <= arr[mid]) 
    {
        if (target >= arr[left] && target < arr[mid]) 
        {
            return rotatedBinarySearch(arr, left, mid - 1, target);
        } 
        else 
        {
            return rotatedBinarySearch(arr, mid + 1, right, target);
        }
    } 
    else 
    {
        if (target > arr[mid] && target <= arr[right]) 
        {
            return rotatedBinarySearch(arr, mid + 1, right, target);
        } 
        else 
        {
            return rotatedBinarySearch(arr, left, mid - 1, target);
        }
    }
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: "<<endl;
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the rotated sorted array:"<<endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    cout << "Enter the target element: ";
    cin >> target;
    int result = rotatedBinarySearch(arr, 0, n - 1, target);
    if (result != -1) 
    {
        cout << "Target element found at index: " << result << endl;
    } 
    else 
    {
        cout << "Target element not found." << endl;
    }
return 0;
}
