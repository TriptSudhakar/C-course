#include<iostream>
#include<vector>
using namespace std;
class Heap
{
    vector<int> v;
    bool minHeap;

    bool compare(int a,int b)
    {
        if(minHeap) return a<b;
        else return a>b;
    }

    void heapify(int idx)
    {
        int left = 2*idx;
        int right = 2*idx+1;

        int min_idx = idx;
        int last = v.size()-1;

        if(left<=last && compare(v[left],v[min_idx])) min_idx = left;
        if(right<=last && compare(v[right],v[min_idx])) min_idx = right;

        // base case
        if(min_idx!=idx)
        {
            swap(v[idx],v[min_idx]);
            heapify(min_idx);
        }
    }
public:
    Heap(int default_size = 10,bool type = true)
    {
        v.reserve(default_size);
        v.push_back(-1);
        minHeap = type;
    }

    void push(int d)
    {
        v.push_back(d);
        int index = v.size()-1;
        int parent = index/2;

        // keep pushing till you reach a root node or stop midway 
        while(index>1 and compare(v[index],v[parent]))
        {
            swap(v[index],v[parent]);
            index = parent;
            parent = parent/2;
        }
    }

    int top()
    {
        return v[1];
    }

    void pop()
    {
        int last = v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }

    bool empty()
    {
        return v.size()==1;
    }
};
void buildHeap(vector<int> &v)
{
    for(int i=2;i<v.size();i++)
    {
        int idx = i;
        int parent = i/2;
        while(idx>1 and v[idx]>v[parent])
        {
            swap(v[idx],v[parent]);
            idx = parent;
            parent = parent/2;
        }
    }
}
bool minHeap = false;

bool compare(int a,int b)
{
    if(minHeap) return a<b;
    else return a>b;
}
void heapify(vector<int> &v,int idx,int size)
{
    int left = 2*idx;
    int right = 2*idx+1;

    int min_idx = idx;
    int last = size-1;
    if(left<=last && compare(v[left],v[min_idx])) min_idx = left;
    if(right<=last && compare(v[right],v[min_idx])) min_idx = right;

    // base case
    if(min_idx!=idx)
    {
        swap(v[idx],v[min_idx]);
        heapify(v,min_idx,size);
    }
}
void buildHeapOptimised(vector<int> &v)
{
    for(int i=(v.size()-1)/2;i>=1;i--)
    {
        heapify(v,i,v.size());
    }
}

void heapsort(vector<int> &arr)
{
    buildHeapOptimised(arr);
    int n = arr.size();

    // remove n-1 elements from the heap
    while(n>1)
    {
        swap(arr[1],arr[n-1]);
        n--;
        heapify(arr,1,n);
    }
}
int main()
{
    // Heap h;
    // int n;
    // cin>>n;

    // for(int i=0;i<n;i++)
    // {
    //     int no;
    //     cin>>no;
    //     h.push(no);
    // }

    // // remove all the elements one by one
    // while(!h.empty())
    // {
    //     cout<<h.top()<<" ";
    //     h.pop();
    // }
    // cout<<'\n';

    vector<int> v{-1,10,20,5,6,1,8,9,4};
    for(int i=1;i<v.size();i++) cout<<v[i]<<" ";
    cout<<'\n';
    // buildHeap(v);
    // buildHeapOptimised(v);
    heapsort(v);
    for(int i=1;i<v.size();i++) cout<<v[i]<<" ";
    cout<<'\n';
    return 0;
}