#include<iostream>
using namespace std;
int main()
{
    int i = 1;
    // First takes step then checks condition
    do
    {
        i = i+1;
        cout<<i<<endl;
    }
    while(i<5);
    // If the condition is false it will still run an iteration
    return 0;
}