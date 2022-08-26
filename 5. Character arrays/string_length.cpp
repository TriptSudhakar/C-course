#include<iostream>
#include<cstring> // Header file for using string/character array functions
using namespace std;
int main()
{
    char a[1000];
    cin.getline(a,1000);
    cout<<strlen(a)<<endl;
    return 0;
}