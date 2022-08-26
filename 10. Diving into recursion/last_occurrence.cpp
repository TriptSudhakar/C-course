#include<iostream>
using namespace std;
int lastoccurrence(int *a,int n,int i,int key)
{
    // base case
    if(i==n)
    {
        return -1;
    }

    //recursive case
    if(a[i]==key)
    {
        // i could be ans answer
        int bi = lastoccurrence(a,n,i+1,key);
        if(bi !=-1)
        {
            return bi;
        }
        else return i;
    }

    int j = lastoccurrence(a,n,i+1,key);
    return j;
}
int main()
{
    int a[] = {1,3,2,4,1,6,1};
    int n = sizeof(a)/sizeof(int);
    cout<<lastoccurrence(a,n,0,1)<<'\n';
    return 0;
}