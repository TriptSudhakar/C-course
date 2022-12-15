#include<iostream>
#include<climits>
using namespace std;
//Top down approach
int minsteps(int n,int dp[])
{
    //base case
    if(n==1) return 0;

    //recursive case
    if(dp[n]!=0) return dp[n];
    int temp = minsteps(n-1,dp);
    if(n%2==0) temp = min(temp,minsteps(n/2,dp));
    if(n%3==0) temp = min(temp,minsteps(n/3,dp));
    return dp[n] = 1 + temp;
}
//Bottom up approach
int minstepsBU(int n)
{
    int dp[1000] = {0};
    for(int i=2;i<=n;i++)
    {
        int temp = INT_MAX;
        temp = dp[i-1];
        if(i%2==0) temp = min(temp,dp[i/2]);
        if(i%3==0) temp = min(temp,dp[i/3]);
        dp[i] = 1+temp;
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    int dp[1000] = {0};
    cout<<minsteps(n,dp)<<'\n';
    cout<<minstepsBU(n)<<'\n';
    return 0;
}