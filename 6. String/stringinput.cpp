#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    // string s;
    // getline(cin,s,'$');
    // cout<<s<<endl;

    string s1 = "World";
    string s2 = "Hello";

    cout<<s1.compare(s2)<<endl; // gives 0 if both strings are same
    // if s1>s2 output is positive otherwise negative
    return 0;
}