#include<iostream>
using namespace std;
int binarysearch(int arr[] , int size , int target)
{
int low = 0;
int high = size-1;
while (low <= high)
  {
    int mid = low + (high-low)/2;
    if(arr[arr[mid] == target])
    {
        return mid;
    }
    if(arr[mid] > target)
    {
        high  = mid - 1;  
    }
    else
    {
        low = mid + 1;
    }
    return -1;
  }
}
int main()
{
    cout<<"\t****BINARY SEARCH****\t"<<endl;
    int arr[10] ;
    int size;
    cout<<"Enter the size of the array :";
    cin>>size;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the value of array at index "<< i << ":";
        cin>>arr[i];
    }
    size = sizeof(arr)/sizeof(arr[0]);
    int target;
    cout<<"Enter the value to search :";
    cin>>target;
    int result = binarysearch(arr,size,target);
    if(result != -1)
    {
        cout<<"Element "<< target << " found at index " << result <<endl;
    }
    else 
        cout<<"Element "<< target << " not found in any array ."<<endl;
    return 0;
}