#include<iostream>
#include<deque>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    int arr[100000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;

    // We have to process first k elements seperately
    deque<int> Q(k);
    for(int i=0;i<k;i++)
    {
        while(!Q.empty() && arr[i]>arr[Q.back()])
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    for(int i=k;i<n;i++)
    {
        cout<<arr[Q.front()]<<" ";

        // 1. Remove the elements which are not part of the window (Contraction)
        while(!Q.empty() && (Q.front()<=i-k))
        {
            Q.pop_front();
        }

        // 2. Remove the elements which are not useful and are in window
        while(!Q.empty() && (arr[i]>=arr[Q.back()]))
        {
            Q.pop_back();
        }
        
        // 3. Add the new elements (Expansion)
        Q.push_back(i);
    }
    cout<<arr[Q.front()]<<endl;
    return 0;
}