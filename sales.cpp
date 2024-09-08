#include<iostream>
using namespace std;
int main()
{
    int branches[12];
    cout<<"Enter the sales for the branches : "<<endl;
    for(int i=0 ; i<12 ; i++)
    {
        cout<<"Branch "<< i+1 << ":";
        cin>>branches[i];
    }
    double totalsales = 0;
    double highestsales = branches[0];
    double lowestsales = branches[0];
    double highestbranch;
    double lowestbranch;
    for(int i=0 ; i<12 ; i++)
    {
        totalsales = totalsales + branches[i];
        if(branches[i] > highestsales)
        {
            highestsales = branches[i];
            highestbranch = i;
        }
        if(branches[i]  < lowestsales)
        {
            lowestsales = branches[i];
            lowestbranch = i;
        }
    }
    cout<<"Total Sales = Rs: "<< totalsales << endl;
    cout<<"Branch with the lowest sales "<< lowestbranch+1 << " with sales of .Rs :"<< lowestsales <<endl;
    cout<<"Branch with the highest sales "<< highestbranch+1 << " with sales of .Rs :"<< highestsales <<endl;
    return 0;
}