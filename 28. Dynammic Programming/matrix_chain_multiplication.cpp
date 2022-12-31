#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
int solve(vector<int> &v,int n)
{
    int dp[100][100];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<n;i++)
    {
        int r = 0,c = i;
        while(c<n)
        {
            int val = INT_MAX;
            for(int pivot = r;pivot<c;pivot++)
            {
                val = min(val,dp[r][pivot] + dp[pivot+1][c] + v[r]*v[pivot+1]*v[c+1]);
            }
            dp[r][c] = val;
            r++;c++;
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[0][n-1];
}
int main()
{
    vector<int> v{4,2,3,1,3};
    cout<<solve(v,v.size()-1)<<'\n';
    return 0;
}