#include<iostream>
using namespace std;
int main()
{
    int arrangement[10][15] = {0};
    while(true)
    {
    cout<<" \t\tSeating Arrangement\t\t"<<endl;
    for(int i=0 ; i < 10 ; i++)
    {
        for(int j=0 ; j < 15 ; j++)
        {
            cout<<arrangement[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter the row (0-9) and the seat number (0-14) for booking :"<<endl;
    int row , seat;
    cout<<"Row:";
    cin>>row;
    cout<<"Seat:";
    cin>>seat;
    if(row == 0 && seat == 0)
    {
        break;
    }
    row--;
    seat--;
    if(row < 0 || row >=10 || seat < 0 || seat >=15)
    {
        cout<<"You entered an invalid row or seat number!!!"<<endl;
        return 1;
    }
    if(arrangement[row][seat] == 0)
    {
        arrangement[row][seat] = 1;
        cout<<"You booked a seat."<<endl;
    }
    else
    {
        cout<<"This seat is already booked.";
    }
    }
    return 0;
}