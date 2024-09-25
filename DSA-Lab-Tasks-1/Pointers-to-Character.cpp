#include<iostream>
#include<string>
using namespace std;
int main()
{
    int choice=0;
    char *pStudent[] = {"Uzair Baig", "Adeel Abbas", "Mehboob Rasheed", "Muhammad Arsalan", "Unaib Baig"};
    char *pStr = "Your favourite Student is";
    cout<<endl<<" Enter a number between 1 and 5 "<<endl;
    cin>>choice;
    if ( choice >=1 && choice<=5)
    {
        cout<<pStr<<" "<<pStudent[choice-1]<<endl;
    }
    return 0;
}
