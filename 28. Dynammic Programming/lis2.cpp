#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int dp[n+1] = {INT_MIN};
    // lengths from 0 to n
    for(int i=1;i<=n;i++)
    {
        dp[i] = INT_MAX;
    }
    
    for(int i=0;i<n;i++)
    {
        // for(int len = 0;len<n;len++)
        // {
        //     if(dp[len]<arr[i] && arr[i]<dp[len+1])
        //     {
        //         dp[len+1] = arr[i];
        //     }
        // }

        // Binary search
        int len = upper_bound(dp,dp+n+1,arr[i]) - dp;
        if(dp[len-1]<arr[i] && arr[i]<dp[len])
        {
            dp[len] = arr[i];
        }
    }
    int lis = 0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==INT_MAX) break;
        lis = i;
    }
    cout<<lis<<'\n';
    return 0;
}