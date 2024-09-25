#include <iostream>
using namespace std;
class Progression         // Base class: Progression
{
protected:
    int prev_value;            
    int curr_value;           

public:
    Progression()     
    {
        prev_value = 0;
        curr_value = 0;
    }
    void print()      // Function to print the current value
    {
        cout << curr_value << " ";
    }
};
class DifferenceProgression : public Progression  // Derived class:DifferenceProgression
{
public:
    DifferenceProgression()
    {
        prev_value = 2;   // First value
        curr_value = 200; // Second value
    }
    void nextValue() 
    {
        int next_value = curr_value - prev_value;
        if( next_value < 0 )
        {
            next_value = -next_value;
        }
        prev_value = curr_value;  
        curr_value = next_value;  
    }
};

int main() 
{
    DifferenceProgression prog;
    cout << "Progression: ";
    for (int i = 0; i < 10; ++i) 
    {
        prog.print();    
        prog.nextValue();  
    }
    cout << endl;
    return 0;
}
