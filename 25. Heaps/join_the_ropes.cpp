#include<iostream>
#include<queue>
using namespace std;

// Problem Statement - Gives N ropes of different sizes, we have join the ropes together.
// ---------------
// The cost of joining 2 ropes of different sizes A and B is (A+B). Find the minimum cost
int join_ropes(int ropes[],int n)
{
    int cost = 0;
    priority_queue<int,vector<int>,greater<int>> pq(ropes,ropes+n);
    while(pq.size()>1)
    {
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();
        cost += A+B;
        pq.push(A+B);
    }
    return cost;
}
int main()
{
    int ropes[] = {4,3,2,6};
    int n = sizeof(ropes)/sizeof(int);

    cout<<join_ropes(ropes,n)<<'\n';
    return 0;
}