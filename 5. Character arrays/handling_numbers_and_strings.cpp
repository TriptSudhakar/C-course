#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char a[1000];
    cin.get();
    // cin.ignore(); both will do the same function
    for(int i=0;i<n;i++)
    {
        cin.getline(a,1000);
        cout<<a<<'\n';
    }
    // The above loop gives first string as empty string as 
    // immediately after the no is assigned to n, 
    // the loop starts executing and it takes input with '\n' as delimiter
    return 0;
}