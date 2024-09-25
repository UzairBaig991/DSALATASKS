#include<iostream>
using namespace std;
int linearsearch(int arr[] , int size , int target)
{
    for( int i=0 ; i<size ; i++)
    {
        if(arr[i] == target)
        {
            return i;     //return i, it returns the value of index
        }
    }
    return -1;       // return -1 , if target is not found
}
int main()
{
    cout<<"\t****LINEAR SEARCH****\t"<<endl;
    int arr[10] ;
    int size;
    cout<<"Enter the size of the array :";
    cin>>size;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the array element at index "<< i << ":";
        cin>>arr[i];
    }
    size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout<<"Enter the array element to search :";
    cin>>target;
    int result = linearsearch(arr,size,target);
    if(result != -1)
    {
        cout<<"Element "<< target << " found at index ." << result <<endl;
    }
    else 
        cout<<"Element "<< target << " not found in any array ."<<endl;
    return 0;
}