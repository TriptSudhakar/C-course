#include<iostream>
#include<algorithm>
using namespace std;
void printarray(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}
int main()
{
    int a[] = {1,2,3,4,5,6,0};
    int n = sizeof(a)/sizeof(int);
    printarray(a,n);
    // rotate(a,a+3,a+n);
    reverse(a,a+n);
    printarray(a,n);
    return 0;
}