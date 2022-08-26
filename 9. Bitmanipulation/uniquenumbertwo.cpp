#include<iostream>
using namespace std;
int main()
{
    int a[] = {6,5,1,6,1,3};
    int n = sizeof(a)/sizeof(int);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans ^= a[i];
    }
    int pos = 0;
    while(ans>0)
    {
        if(ans&1)
        {
            break;
        }
        pos++;
        ans>>=1;
    }
    int x = 1<<pos;
    int no1 = 0,no2 = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]&x)
        {
            no1^=a[i];
        }
        else
        {
            no2^=a[i];
        }
    }
    cout<<no1<<" "<<no2<<'\n';
    return 0;
}