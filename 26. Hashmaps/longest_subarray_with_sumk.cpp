#include<iostream>
#include<unordered_map>
using namespace std;
int longestsubarraywithsumk(int arr[],int n,int k)
{
    unordered_map<int,int> m;
    int len = 0;
    int pre = 0;
    for(int i=0;i<n;i++)
    {
        pre += arr[i];
        if(pre==k)
        {
            len = max(len,i+1);
        }
        if(m.find(pre-k)!=m.end())
        {
            len = max(len,i-m[pre-k]);
        }
        if(m.count(pre)==0) //records the first occurrence
        {
            m[pre] = i;
        }
    }
    return len;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[10000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<longestsubarraywithsumk(arr,n,k)<<'\n';
    return 0;
}