#include<iostream>
using namespace std;
//Top down appro
int profit(int wines[],int i,int j,int y,int dp[][100])
{
    // base case
    if(i>j) return 0;

    // recursive case
    if(dp[i][j]!=0) return dp[i][j];
    int op1 = wines[i]*y + profit(wines,i+1,j,y+1,dp);
    int op2 = wines[j]*y + profit(wines,i,j-1,y+1,dp);
    return dp[i][j] = max(op1,op2);
}
int profitBU(int wines[],int i,int j,int n)
{
    int dp[100][100] = {0};
    for(int k=0;k<n;k++)
    {
        dp[k][k] = n*wines[k];
    }
    for(int l=1;l<n;l++)
    {
        for(int k = 0;k+l<n;k++)
        {
            int op1 = wines[k]*(n-l) + dp[k+1][k+l];
            int op2 = wines[k+l]*(n-l) + dp[k][k+l-1];
            dp[k][k+l] = max(op1,op2);
        }
    }
    return dp[0][n-1];
}
int main()
{
    int wines[] = {2,3,5,1,4};
    int n = sizeof(wines)/sizeof(int);
    int dp[100][100] = {0};
    cout<<profit(wines,0,n-1,1,dp)<<'\n';
    cout<<profitBU(wines,0,n-1,n)<<'\n';
    return 0;
}