#include<iostream>
using namespace std;
void SpiralPrint(int arr[][100],int n,int m)
{
    int sr = 0 , er = n-1, sc = 0, ec = m-1;

    while(sr<=er && sc<=ec)
    {
        for(int i = sc;i<=ec;i++)
        {
            cout<<arr[sr][i]<<" ";
        }
        sr++;

        for(int i=sr;i<=er;i++)
        {
            cout<<arr[i][ec]<<" ";
        }
        ec--;
        
        if(sr<er){
        for(int i=ec;i>=sc;i--)
        {
            cout<<arr[er][i]<<" ";
        }
        er--;}
        
        if(sc<ec){
        for(int i = er;i>=sr;i--)
        {
            cout<<arr[i][sc]<<" ";
        }
        sc++;}
    }
}
int main()
{
    int a[100][100];
    int r = 3,c = 4;
    int val = 1;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            a[i][j] = val;
            val++;
        }
    }
    SpiralPrint(a,r,c);
    return 0;
}