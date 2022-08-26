#include<iostream>
using namespace std;

void staircase(int a[][100],int n,int m,int key)
{
    int i = 0,j = m-1;
    bool iskeypresent = false;
    while(i<n&&j>=0)
    {
        if(a[i][j]==key)
        {
            cout<<"Key found at index "<<i<<","<<j<<'\n';
            iskeypresent = true;
            break;
        }
        else if(a[i][j]<key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    if(!iskeypresent)
    {
        cout<<"Key not found"<<'\n';
    }
}
int main()
{
    //Consider the given array is sorted row & column wise
    int a[][100] = {
        {1,4,8,10},
        {2,5,9,15},
        {6,13,18,20},
        {11,14,21,25}
    };
    staircase(a,4,4,14);
    return 0;
}