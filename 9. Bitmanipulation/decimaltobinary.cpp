#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
void decimaltobinary(int n)
{
    string s;
    while(n>0)
    {
        if(n&1)
        {
            s.push_back('1');
        }
        else
        {
            s.push_back('0');
        }
        n/=2;
    }
    reverse(s.begin(),s.end());
    cout<<s<<'\n';
}
void decimaltobinaryoptimized(int n)
{
    int mask = 1<<31;
    bool isonefound = false;

    while(mask)
    {
        if(((mask & n) == 0) && isonefound == false)
        {
            mask >>=1;
            continue;
        }
        else
        {
            isonefound = true;
            if((mask & n)>0)
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }
            mask = mask>>1;
        }
    }
}
int main()
{
    int n = 140001012;
    decimaltobinary(n);
    return 0;
}