#include<iostream>
#include<climits>
using namespace std;
//recursive solution
int max_profit(int prices[],int n)
{
    // base case
    if(n<=0) return 0;

    // recursive case
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int cut = i+1;
        int current_ans = prices[i] + max_profit(prices,n-cut);
        ans = max(ans,current_ans);
    }
    return ans;
}

//bottom up solution
int max_profit_dp(int prices[],int n)
{
    int dp[n+1] = {0};
    for(int len = 1;len<=n;len++)
    {
        int ans = INT_MIN;
        for(int i=0;i<len;i++)
        {
            int cut = i+1;
            int current_ans = prices[i]+dp[len-cut];
            ans = max(ans,current_ans);
        }
        dp[len] = ans;
    } 
    return dp[n];
}
int main()
{
    int prices[] = {3,5,8,9,10,17,17,20};
    int n = sizeof(prices)/sizeof(int);
    cout<<max_profit(prices,n)<<'\n';
    cout<<max_profit_dp(prices,n)<<'\n';
    return 0;
}