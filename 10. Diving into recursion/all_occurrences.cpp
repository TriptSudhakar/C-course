#include<iostream>
using namespace std;
void printalloccurrences(int *a,int n,int i,int key)
{
    // base case
    if (i==n)
    {
        return; 
    }

    // recursive case
    if(a[i]==key)
    {
        cout<<i<<" ";
    }
    printalloccurrences(a,n,i+1,key);
}
int main()
{
    int a[] = {1,2,3,2,4,2};
    int n = sizeof(a)/sizeof(int);
    printalloccurrences(a,n,0,2);
    return 0;
}