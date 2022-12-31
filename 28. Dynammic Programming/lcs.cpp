#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int lcs(string s1,string s2,vector<vector<int>>&dp,int i = 0,int j = 0)
{
    // base case
    if(i==s1.length()||j==s2.length()) return 0;

    // recursive case
    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j]) return dp[i][j] = 1 + lcs(s1,s2,dp,i+1,j+1);

    return dp[i][j] = max(lcs(s1,s2,dp,i,j+1),lcs(s1,s2,dp,i+1,j));
}
int main()
{
    string s1 = "ABCDGH";
    string s2 = "ABEDGFH";
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1,vector<int>(n2,-1));
    cout<<lcs(s1,s2,dp)<<'\n';
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}