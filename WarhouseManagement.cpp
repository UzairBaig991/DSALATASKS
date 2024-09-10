#include<iostream>
using namespace std;
int linearsearch(string inventory[] , int size , string target)
{
    for( int i=0 ; i<size ; i++)
    {
        if(inventory[i] == target)
        {
            return i;     //return i, it returns the value of index
        }
    }
    return -1;       // return -1 , if target is not found
}
int main()
{
    cout<<"\t****WARHOUSE INVENTORY SYSYTEM****\t"<<endl;
    string inventory[10] ;
    int size;
    cout<<"Enter the size of the invenory :";
    cin>>size;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the name of the product at index "<< i << ":";
        cin>>inventory[i];
    }
    size = sizeof(inventory) / sizeof(inventory[0]);
    string target;
    cout<<"Enter the name of the product to search :";
    cin>>target;
    int result = linearsearch(inventory,size,target);
    if(result != -1)
    {
        cout<<"Element "<< target << " found at index ." << result <<endl;
    }
    else 
        cout<<"Element "<< target << " not found in any array ."<<endl;
    return 0;
}