#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count = 0;
    while(n)
    {
        int p = n & (-n); // extracts the first setbit from the right
        n = n-p;
        count++;
        cout<<"Iteration no "<<count<<endl;
    }
    // another method to count setbits
    // int setbits = __builtin_popcount(n);
    cout<<"Setbits : "<<count<<endl;
    return 0;
}