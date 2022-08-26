#include<iostream>
using namespace std;
int main()
{
    char ch;
    // cin>>ch; // If we take 'Hello World$' as the input then the answer comes out to be 10
    // // whereas the expected answer is 11

    // To read whitespaces use cin.get()
    ch = cin.get();
    int count =0;
    while(ch!='$')
    {
        count++;
        // cin>>ch;
        ch = cin.get();
    }
    cout<<count;
    return 0;
}