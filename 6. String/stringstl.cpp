#include<iostream>
using namespace std;
int main()
{
    char a[100] = "Hello world!";
    string s(a);
    cout<<s<<endl;;

    string x = "I am learning strings update!";
    string word = "learning";

    cout<<"Learning is present at : "<<x.find(word)<<'\n';
     
    int index = x.find(word);
    x.erase(index,word.length()+1);

    cout<<x;

    return 0;
}