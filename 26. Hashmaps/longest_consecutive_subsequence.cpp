#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//using unordered map
int longestconssubseq(int arr[],int n)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int no = arr[i];

        if(!m.count(no-1) && !m.count(no+1))
        {
            m[no] = 1;
        }
        else if(m.count(no-1) && !m.count(no+1))
        {
            int l = m[no-1];
            m[no-l] = l+1;
            m[no] = l+1;
        }
        else if(!m.count(no-1) && m.count(no+1))
        {
            int l = m[no+1];
            m[no] = l+1;
            m[no+l] = l+1;
        }
        else
        {
            int l1 = m[no-1];
            int l2 = m[no+1];
            m[no-l1] = l1+l2+1;
            m[no+l2] = l1+l2+1;
        }
    }

    int len = 0;
    for(auto p:m)
    {
        len = max(len,p.second);
    }
    return len;
}
int longestconssubsequsingset(int arr[],int n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    int len = 0;
    for(auto x:s)
    {
        if(s.find(x-1)!=s.end())
        {
            continue;
        }
        
        int temp = x;
        int st = 0;
        while(s.find(temp)!=s.end())
        {
            st++;
            temp++;
        }

        len = max(len,st);
    }
    return len;
}
int main()
{
    int arr[] = {14,5,1,2,6,3,7,8,9,13,15,11,12,13,17};
    int n = sizeof(arr)/sizeof(int);
    cout<<longestconssubseq(arr,n)<<'\n';
    cout<<longestconssubsequsingset(arr,n)<<'\n';
    return 0;
}