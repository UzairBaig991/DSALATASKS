#include<iostream>
using namespace std;
int main()
{
    int grades[1000] , n;
    cout<<"Enter the number of students :";
    cin>>n;
    cout<<"Enter the grades of the students :"<<endl;
    for(int i=0 ; i<n ; i++)
    {
        cin>>grades[i];
    }
    int sum = 0;
    for(int i=0 ; i<n ; i++)
    {
        sum = sum + grades[i];
    }
    float average = sum/n;
    cout<<"Average Grade :"<< average<<endl;
    int aboveavg =0 , belowavg = 0;
    for(int i=0 ; i<n ; i++)
    {
        if(grades[i] > average)
        {
            aboveavg++;
        }
        else if(grades[i] < average)
        {
            belowavg++;
        }
    }
    cout<<"Students,who are above the average :"<< aboveavg <<endl;
    cout<<"Students,who are below the average :"<< belowavg <<endl;
    int highestgrades = grades[0];
    int lowestgrades = grades[0];
    for(int i=0 ; i<n ; i++)
    {
        if(grades[i] > highestgrades)
        {
            highestgrades = grades[i];
        }
        else if(grades[i] < lowestgrades)
        {
            lowestgrades = grades[i];
        }
    }
    cout<<"Students with highest grades :"<< highestgrades <<endl;
    cout<<"Students with lowest grades :"<< lowestgrades <<endl;
    return 0;
}