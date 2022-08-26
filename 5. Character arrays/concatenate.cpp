#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[2000];
    char b[1000];
    
    cin.getline(a,1000);
    cin.getline(b,1000);
    
    // strcat(a,b); // appends b to a
    // cout<<a<<'\n'<<b<<'\n';
    if(strcmp(a,b)==false) // strcmp returns 0 if strings match
    {
        cout<<"Match";
    }
    else
    {
        cout<<"Not a Match";
    }
    return 0;
}