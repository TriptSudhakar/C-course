#include<iostream>
using namespace std;
void update(int &a)
{
    a = a+1;
}
int main()
{
    int x = 1;
    cout<<"Before update : "<<x<<endl;
    update(x);
    cout<<"After update : "<<x<<endl;
    return 0;
}