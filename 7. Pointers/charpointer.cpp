#include<iostream>
using namespace std;
int main()
{
    char ch;
    ch = 'B';
    char* chptr = &ch;
    cout<<(int*)chptr; // can also use float* or void* instead of int*
    return 0;
}