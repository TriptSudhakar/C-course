#include<iostream>
#include<unordered_map>
#define mp(a,b) make_pair(a,b)
#define ppi pair<pair<int,int>,int>
using namespace std;
class node
{
public:
    node*left=NULL; // for 0
    node*right=NULL; // for 1

};
class trie
{
    node*root;
public:
    trie()
    {
        root = new node();
    }

    void insert(int n)
    {
        node*temp = root;
        //loop
        for(int i=31;i>=0;i--)
        {
            int bit = (n>>i)&1;
            if(bit==0)
            {
                if(temp->left==NULL) temp->left = new node();
                temp = temp->left;
            }
            else
            {
                if(temp->right==NULL) temp->right = new node();
                temp = temp->right;
            }
        }
    }

    int max_xor_helper(int value)
    {
        node*temp = root;
        int current_ans = 0;
        for(int j=31;j>=0;j--)
        {
            int bit = (value>>j)&1;
            if(bit==0)
            {
                //find a complementary value
                if(temp->right!=NULL)
                {
                    temp = temp->right;
                    current_ans+=(1<<j);
                }
                else temp = temp->left;
            }
            else
            {
                //current bit is 1
                if(temp->left!=NULL)
                {
                    temp = temp->left;
                    current_ans+=(1<<j);
                }
                else temp = temp->right;
            }
        }
        return current_ans;
    }

    ppi max_xor_pair(int*input,int n)
    {
        int max_xor = 0;
        auto p = mp(0,0);
        for(int i=0;i<n;i++)
        {
            int val = input[i];
            insert(val);
            int current_xor = max_xor_helper(val);
            if(current_xor>=max_xor)
            {
                p = mp(current_xor^val,val);
                max_xor = current_xor;
            }
        }
        return mp(p,max_xor);
    }

    int max_xor_subarray(int*input,int n)
    {
        int cxor[10000];
        cxor[0] = input[0];
        for(int i=1;i<n;i++)
        {
            cxor[i] = input[i]^cxor[i-1];
        }

        auto p = max_xor_pair(cxor,n);
        auto i = p.first.first;
        auto j = p.first.second;
        auto ans = p.second;
        int idi,idj;

        for(int k=0;k<n;k++)
        {
            if(cxor[k]==j) idj = k;
        }
        for(int k=n-1;k>=0;k--)
        {
            if(cxor[k]==i) idi = k;
        }

        cout<<"Subarray is : \n";
        for(int k=idi+1;k<=idj;k++)
        {
            cout<<input[k]<<" ";
        }
        cout<<'\n';
        return ans;
    }
};
int main()
{
    int input[] = {3,10,5,25,9,2,8,0,17,22};
    int n = sizeof(input)/sizeof(int);
    trie t;
    cout<<t.max_xor_subarray(input,n)<<'\n';
    return 0;
}