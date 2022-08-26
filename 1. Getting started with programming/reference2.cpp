#include<iostream>
using namespace std;
int main()
{
    int a =10;
    int &b = a;
    int &c = b;
    b++;
    c++;
    cout<<a<<endl;
    cout<<b<<endl;
    c--;
    cout<<b<<endl;
    cout<<c<<endl;
    return 0;
}