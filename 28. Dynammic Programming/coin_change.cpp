#include<iostream>
#include<climits>
using namespace std;
//Top down approach
int mincoins(int n,int coins[],int t,int dp[])
{
    //base case
    if(n==0) return 0;

    //recursive case
    if(dp[n]!=0) return dp[n];
    int ans = INT_MAX;
    for(int i=0;i<t;i++)
    {
        if(n>=coins[i]) ans = min(ans,mincoins(n-coins[i],coins,t,dp));
    }
    return dp[n] = 1 + ans;
}
//Bottom up approach
int mincoinsBU(int n,int coins[],int t)
{
    int dp[10000] = {0};
    
    for(int i=1;i<=n;i++)
    {
        dp[i] = INT_MAX;
        for(int j=0;j<t;j++)
        {
            if(i>=coins[j])
            { 
                dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    int coins[] = {1,7,10};
    int t = sizeof(coins)/sizeof(int);
    int dp[10000] = {0};
    cout<<mincoins(n,coins,t,dp)<<'\n';
    cout<<mincoinsBU(n,coins,t)<<'\n';
    return 0;
}