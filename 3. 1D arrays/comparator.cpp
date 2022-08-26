#include<iostream>
using namespace std;
void PrintArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool compare(int a,int b)
{
    return a>b;
}

void Bubblesort(int a[],int n,bool (&mycompare)(int a,int b))
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(mycompare(a[j],a[j+1]))
            {
                swap(a[j],a[j+1]);
            }
        }
    }
}
int main()
{
    int a[] = {5,4,3,2,1};
    int n = sizeof(a)/sizeof(int);

    cout<<"Before Bubble Sort : ";
    PrintArray(a,n);

    Bubblesort(a,n,compare);

    cout<<"After Bubble Sort : ";
    PrintArray(a,n);
}