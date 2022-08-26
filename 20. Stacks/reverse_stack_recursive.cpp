#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &s,int x)
{
    // base case
    if(s.empty())
    {
        s.push(x);
        return;
    }

    // recursive case
    int t = s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(t);
}
void reverse_stack(stack<int> &s)
{
    //base case
    if(s.empty())
    {
        return;
    }

    //otherwise
    //pop out the top element and insert it at the
    //bottom of the reversed smaller stack
    int x = s.top();
    s.pop();
    reverse_stack(s);
    insertAtBottom(s,x);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverse_stack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<'\n';
}