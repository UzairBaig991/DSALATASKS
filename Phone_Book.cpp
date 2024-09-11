#include <iostream>
#include <string>
using namespace std;
int linearSearch(string arr[], int size, string target) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == target)
        return i; 
    }
    return -1; 
}
int binarySearch(string arr[], int size, string target) 
{
    int low = 0;
    int high = size - 1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        } 
        if (arr[mid] < target)
        {
            low = mid + 1; 
        }
        else
            high = mid - 1; 
    }
    return -1; 
}

int main() 
{
    string arr[10] ;
    int size;
    cout<<"Enter the size of the Phone Book  :";
    cin>>size;
    cout<<"\tIt is UN-SORTED Phone Book\t"<<endl;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the name at index "<< i << ":";
        cin>>arr[i];
    }
    cout<<"\tIt is SORTED Phone Book\t"<<endl;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the name at index "<< i << ":";
        cin>>arr[i];
    }
    size = sizeof(arr) / sizeof(arr[0]);
    string target;
    cout << "Enter name to search: ";
    cin >> target;
    int result = linearSearch(arr, size, target);
    if (result != -1)
    {
        cout << "Name : " << target << " found at position " << result << endl;
    }
    else
    {
        cout << "Name : " << target << " not found in phone." << endl;
    }
    result = binarySearch(arr, size, target);
    if (result != -1)
    {
        cout << "Name : " << target << " found at position " << result << endl;
    }
    else
        cout << "Name : " << target << " not found in phone book" << endl;
    return 0;
}