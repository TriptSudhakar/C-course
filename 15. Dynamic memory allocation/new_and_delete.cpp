#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *a = new int[n]{0};
    // Variable a that is created inside the static memory -> Overwritten
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<sizeof(a)<<'\n';
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    delete []a;

    int b[100]={0};
    cout<<sizeof(b)<<'\n';
    cout<<b<<'\n'; //symbol table
    // here b cannot be overwritten, b is a part of read only memory
    return 0;
}