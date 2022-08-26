#include<iostream>
using namespace std;

void readline (char a[ ],char delimiter = '\n')
{
    int i=0;
    char ch = cin.get();
    while(ch!= delimiter)
    {
        a[i] = ch;
        i++;
        ch = cin.get();
    }
    a[i] = '\0';
}
int main()
{
    char a[100];
    // cin>>a; // in this way we cannot give input seperated by spaces
    // readline(a,'$');
    // cin.getline(a,100);
    cin.getline(a,100,'$'); 
    cout<<a;
    return 0;
}