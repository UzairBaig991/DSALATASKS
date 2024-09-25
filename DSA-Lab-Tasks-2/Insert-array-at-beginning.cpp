#include<iostream>
using namespace std;
int main() {
    int arr[10],n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    cout<<"Enter the values in the array: "<<endl;
    for(int i=0; i<n; i++) {
        cin>>arr[i]; }  
    cout<<"Enter the array element at the beginning: "<<endl;
    int x;
    cin>>x;
    for(int i=n; i>0 ; i--) {
        arr[i] = arr[i-1]; }
    arr[0] = x;
    n++;
    cout<<"Array elements are :"<<endl;
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<endl; }
    return 0; }
