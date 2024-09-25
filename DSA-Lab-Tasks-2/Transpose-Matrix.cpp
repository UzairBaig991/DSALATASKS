#include<iostream>
using namespace std;
int main()
{
    int arr[3][3];
    int x;
    bool found = false;
    cout<<"Enter the elements of 3*3 matrix :"<<endl;
    for(int i=0 ; i<3 ; i++)
    {
        for (int j=0 ; j<3 ; j++)
        {
            cout<<"Enter elements at position "<<"("<<i<<","<<j<<"):"<<endl;
            cin>>arr[i][j];
            }
    }
    for(int i=0 ; i<3 ; ++i)
    {
        for (int j=i+1 ; j<3 ; ++j)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    cout<<"Transposed Matrix."<<endl;
    for(int i=0 ; i<3 ; ++i)
    {
        for (int j=0 ; j<3 ; ++j)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
