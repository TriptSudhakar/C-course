#include<iostream>
using namespace std;
void towerofhanoi(int n,char src,char dest,char helper)
{
    // base case 
    if (n==0) return;

    // recursive case
    towerofhanoi(n-1,src,helper,dest);
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<"\n";
    towerofhanoi(n-1,helper,dest,src);
}
int main()
{
    int n;
    cin>>n;
    towerofhanoi(n,'A','C','B');
}