#include<iostream>
using namespace std;
int fib(int n,int dp[])
{
    // base case
    if(n==0 || n==1) return n;
    
    // recursive case
    if(dp[n]!=0) return dp[n];

    int ans;
    ans = fib(n-1,dp)+fib(n-2,dp);
    return dp[n] = ans;
}
int fibBU(int n)
{
    int arr[1000] = {0};
    arr[1] = 1;

    for(int i=2;i<=n;i++)
    {
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n];
}
int fibSpaceOpt(int n)
{
    if(n==0||n==1) return n;
    int a=0;
    int b=1;
    int c=a+b;
    for(int i=0;i<n-2;i++)
    {
        a = b;
        b = c;
        c = a+b;
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    int dp[1000] = {0};
    cout<<fib(n,dp)<<'\n';
    cout<<fibBU(n)<<'\n';
    cout<<fibSpaceOpt(n)<<'\n';
    return 0;
}