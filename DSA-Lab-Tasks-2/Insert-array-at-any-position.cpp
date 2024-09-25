#include<iostream>
using namespace std;
int main()
{
    int arr[10] , n , position ,x;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"Enter the elements in the array ."<<endl;
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the position you want to insert element at : ";
    cin>>position;
    cout<<"Enter the element in the index : ";
    cin>>x;
    for( int i=n-1 ; i>=position-1 ;i--)
    {
        arr[i+1] = arr[i];
    }
    arr[position-1] = x;
    n++;
    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}