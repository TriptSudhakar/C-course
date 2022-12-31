#include<iostream>
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
    int dp[n] = {0};
    for(int i=0;i<n;i++)
    {
        dp[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int ans = 1;
    for(int i=0;i<n;i++)
    {
        ans = max(dp[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}