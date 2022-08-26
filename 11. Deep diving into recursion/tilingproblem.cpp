#include<iostream>
using namespace std;
int ways(int n)
{
    if(n<=3) return 1;
    return ways(n-1)+ways(n-4);
}
int main()
{
    int n=5;
    cout<<ways(n)<<'\n';
    return 0;
}