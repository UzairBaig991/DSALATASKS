#include <iostream>
using namespace std;
class SquareRootProgression         // Class: SquareRootProgression
{
private:
    int curr_value; 
public:
    SquareRootProgression() 
    {
        curr_value = 65536; 
    }
    void nextValue() 
    {
        int temp = curr_value;
        int sqr_root = temp / 2; 
        for (int i = 0; i < 10; ++i) 
        {
            sqr_root = (sqr_root + temp / sqr_root) / 2; 
        }

        curr_value = sqr_root;
    }
    double getCurrent() 
    {
        return curr_value;
    }
};
int main() 
{
    SquareRootProgression prog;
    cout << "Progression: ";
    for (int i = 0; i < 10; ++i) 
    {
        cout << prog.getCurrent() << "  "; 
        prog.nextValue();
    }
    cout<<endl;
    return 0;
}
