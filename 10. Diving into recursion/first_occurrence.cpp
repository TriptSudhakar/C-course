#include<iostream>
using namespace std;
int firstoccurrence(int *a, int n,int key)
{
    // base case
    if(n == 0) return -1;

    // recursive case
    if(a[0]==key) return 0;

    int i = firstoccurrence(a+1,n-1,key);
    if(i == -1) return -1; // Key not found
    return i+1;
}
int firstoccurrencei(int *a,int n,int i,int key)
{
    if(i==n) return -1;

    if(a[i]==key) return i;
    return firstoccurrencei(a,n,i+1,key);
}
int main()
{
    int a[] = {1,1,6,3,4,3,3,7};
    int n = sizeof(a)/sizeof(int);

    cout<<firstoccurrence(a,n,3)<<'\n';
    cout<<firstoccurrencei(a,n,0,3)<<'\n';
    return 0;
}