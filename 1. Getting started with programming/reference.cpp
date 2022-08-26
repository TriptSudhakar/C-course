#include<iostream>
using namespace std;
int main()
{
    // We can create another name for a bucket
    int a = 10;
    
    int &b = a; // b is a refernce variable to a
    cout<<b; // -> 10
    
    int &c = b;
    cout<<c; // -> 10

    c++;
    cout<<a; // ->11
    return 0;
}