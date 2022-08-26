#include<iostream>
using namespace std;
class Fun
{
public:
    void operator()()
    {
        cout<<"Having Fun inside Operator Fn! \n";
    }
};
int main()
{
    Fun f;
    f();
    return 0;
}