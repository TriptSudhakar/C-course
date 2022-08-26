#include<iostream>
#include<cstring>
using namespace std;
string extract_string_at_key(string str,int key)
{
    char* s = strtok((char*)str.c_str()," ");
    while(key>1)
    {
        s = strtok(NULL," "); // ?
        key--;
    }
    return (string)s;
}
int main()
{
    int n;
    cin>>n;
    cin.get();

    string a[100];
    for(int i=0;i<n;i++)
    {
        getline(cin,a[i]);
    }
    int key;
    string reversal,ordering;
    return 0;
}