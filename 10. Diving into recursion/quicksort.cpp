#include<iostream>
using namespace std;
int Partition(int *a,int s,int e)
{
    int i = s-1;
    for(int j=s;j<e;j++)
    {
        if(a[j]<=a[e])
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}
void Quicksort(int *a , int s,int e)
{
    // base case
    if(s>=e) return;

    // recursive case
    int index = Partition(a,s,e);
    Quicksort(a,s,index-1);
    Quicksort(a,index+1,e);

}
int main()
{
    int a[] = {2,3,1,4,11,7,8,10,6};
    int n = sizeof(a)/sizeof(int);
    Quicksort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}