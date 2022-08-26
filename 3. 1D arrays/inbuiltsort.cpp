#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a,int b)
{
    return a>b;
}
int main()
{
    int a[] = {1,2,4,6,7,0,3,0,8,2,5};
    int n = sizeof(a)/sizeof(int);
    
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    sort(a,a+n,compare);
    
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}