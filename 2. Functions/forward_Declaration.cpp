#include<iostream>
using namespace std;

// Forward declaration
int Multiply(int ,int ); // we don't need to give arguement name 

int main()
{
    int a = 10,b = 20;
    cout<<Multiply(a,b)<<endl;

    int ans = Multiply(100,30);
    cout<<ans<<endl;

    return 0;
}

int Multiply(int a,int b)
{
    return a*b;
}