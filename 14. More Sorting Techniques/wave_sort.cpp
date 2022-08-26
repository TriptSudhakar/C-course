#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,3,4,2,7,4};
    // sort the array in wave form
    int n = sizeof(arr)/sizeof(int);

    for(int i=0;i<n;i+=2)
    {
        if(i!=0 && arr[i]<arr[i-1])
        {
            swap(arr[i],arr[i-1]);
        }
        if(i!=(n-1) && arr[i]<arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}