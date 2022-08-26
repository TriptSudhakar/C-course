#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node*left;
    node*right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
node* buildTree()
{
    int d;
    cin>>d;

    if(d==-1) return NULL;
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void printPre(node*root)
{
    if(root==NULL)
    {
        return;
    }

    // Otherwise print root followed by subtrees (children)
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}
void printIn(node*root)
{
    if(root==NULL)
    {
        return;
    }

    // Otherwise print root followed by subtrees (children)
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}
void printPost(node*root)
{
    if(root==NULL)
    {
        return;
    }

    // Otherwise print root followed by subtrees (children)
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}
int height(node*root)
{
    if(root==NULL)
    {return 0;}

    int ls = height(root->left);
    int rs = height(root->right);

    return 1+max(ls,rs);
}
void printKthLevel(node*root,int k)
{
    if(root==NULL) return;

    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
}
void printAllLevels(node*root)
{
    int H = height(root);
    for(int i=1;i<=H;i++)
    {
        printKthLevel(root,i);
        cout<<'\n';
    }
    return;
}
void bfs(node*root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        node*f = q.front();
        if(f==NULL)
        {
            cout<<'\n';
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<f->data<<',';
            q.pop();

            if(f->left)
            {
                q.push(f->left);
            }
            if(f->right)
            {
                q.push(f->right);
            }
        }
    }
}
int count(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}
int diameter(node*root)
{
    if(root==NULL) return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1+h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1,max(op2,op3));
}

class Pair
{
public:
    int height;
    int diameter;
};

Pair fastDiameter(node*root)
{
    Pair p;
    if(root==NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }

    // Otherwise?
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height,right.height)+1;
    p.diameter = max(left.height+right.height,max(left.diameter,right.diameter));
    return p;
}

int replaceSum(node*root)
{
    if(root==NULL) return 0;

    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }

    // Recursive Part
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum+rightSum;
    return temp+leftSum+rightSum;
}

class HBpair
{
public:
    int height;
    bool balance;
};
HBpair isHeightBalance(node*root)
{
    HBpair p;
    if(root==NULL)
    {
        p.height = 0;
        p.balance = true;
        return p;
    }

    // Recursive case
    auto left = isHeightBalance(root->left);
    auto right = isHeightBalance(root->right);

    p.height = max(left.height,right.height)+1;
    if(abs(left.height-right.height)<=1 && left.balance && right.balance)
    {
        p.balance = true;
    }

    else p.balance = false;
    return p;
}

node* buildBalancedTreefromArray(int*a,int s,int e)
{
    // base case
    if(s>e) return NULL;

    // recursive case;
    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = buildBalancedTreefromArray(a,s,mid-1);
    root->right = buildBalancedTreefromArray(a,mid+1,e);

    return root;
}

node* createTreefromTraversal(int*in,int *pre,int s,int e)
{
    static int i = 0;
    // base case
    if(s>e)
    {
        return NULL;
    }

    // recursive case
    node*root = new node(pre[i]);

    int index = -1;
    for(int j=s;j<=e;j++)
    {
        if(in[j]==pre[i])
        {
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreefromTraversal(in,pre,s,index-1);
    root->right = createTreefromTraversal(in,pre,index+1,e);

    return root;
}

void printRightView(node*root,int level,int& maxlevel)
{
    if(root==NULL) return;

    if(maxlevel<level)
    {
        cout<<root->data<<' ';
        maxlevel = level;
    }

    printRightView(root->right,level+1,maxlevel);
    printRightView(root->left,level+1,maxlevel);
}

int printAtDistanceK(node*root,node*target,int k)
{
    // base case
    if(root==NULL)
    {
        return -1;
    }

    // reach the target node
    if(root==target)
    {
        printKthLevel(target,k+1);
        return 0;
    }

    // next step - ancestor
    int DL = printAtDistanceK(root->left,target,k);

    if(DL!=-1)
    {
        // Again there are 2 cases
        // Ancestor itself or need to go to the right subtree of root
        if(DL+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printKthLevel(root->right,k-2-DL+1);
        }
        return 1+DL;
    }

    int DR = printAtDistanceK(root->right,target,k);
    if(DR!=-1)
    {
        if(DR+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printKthLevel(root->left,k-2-DR+1);
        }
        return 1+DR;
    }

    // node was not present in right and left subtree of the given node
    return -1;
}

//assumption both a and b are present in the tree, all the keys qre unique
node* lca(node*root,int a,int b)
{
    if(root==NULL) return NULL;

    if(root->data==a || root->data==b)
    {
        return root;
    }

    //search in left and right subtree
    node*leftans = lca(root->left,a,b);
    node*rightans = lca(root->right,a,b);

    if(leftans!=NULL && rightans!=NULL)
    {
        return root;
    }

    if(leftans!=NULL) return leftans;
    return rightans;
}
class branch
{
public:
    int branchsum;
    int maxsum;

    branch()
    {
        branchsum = 0;
        maxsum = 0;
    }
};
branch maxsum_path(node*root)
{
    branch p;
    if(root == NULL)
    {
        return p;
    }

    branch left = maxsum_path(root->left);
    branch right = maxsum_path(root->right);
    
    // construct two values
    int op1 = root->data;
    int op2 = left.branchsum + root->data;
    int op3 = right.branchsum + root->data;
    int op4 = left.branchsum + right.branchsum + root->data;

    int current_ans_through_root = max(max(op1,op2),max(op3,op4));

    // branch sum of the current root
    p.branchsum = max(left.branchsum,max(right.branchsum,0)) + root->data;
    p.maxsum = max(current_ans_through_root,max(left.maxsum,right.maxsum));
    return p;
}

//finding the level of a given node from the root node/any given node
int search(node*root,int key,int level=0)
{
    if(root == NULL)
    {
        return -1;
    }

    if(root->data == key)
    {
        return level;
    }

    int left = search(root->left,key,level+1);
    if(left!=-1) return left;
    return search(root->right,key,level+1);
}

//function to find distance between 2 nodes
int findDistance(node*root,int a,int b)
{
    node* lca_node = lca(root,a,b);
    int l1 = search(lca_node,a);
    int l2 = search(lca_node,b);

    return l1+l2;
}
int main()
{
    // node*root = buildTree();
    // printPre(root);
    // cout<<'\n';
    // printIn(root);
    // cout<<'\n';
    // printPost(root);
    // cout<<'\n';

    // cout<<height(root)<<'\n';

    // printKthLevel(root,3);
    // printAllLevels(root);

    // bfs(root);

    // cout<<count(root)<<'\n';

    // cout<<diameter(root)<<'\n';
    // Pair p = fastDiameter(root);
    // cout<<p.height<<" "<<p.diameter<<'\n';

    // bfs(root);
    // cout<<'\n';
    // replaceSum(root);
    // bfs(root);

    // if(isHeightBalance(root).balance)
    // {
    //     cout<<"Balanced\n";
    // }
    // else cout<<"Not a Balanced Tree\n";

    // int a[] = {1,2,3,4,5,6,7};
    // int n = 7;
    // node*root = buildBalancedTreefromArray(a,0,n-1);
    // bfs(root);

    // int in[] = {3,2,8,4,1,6,7,5};
    // int pre[] = {1,2,3,4,8,5,6,7};
    // int n = sizeof(in)/sizeof(int);
    // node*root = createTreefromTraversal(in,pre,0,n-1);
    // bfs(root);

    node*root = buildTree(); 
    // 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1 
    // int maxlevel = -1;
    // printRightView(root,0,maxlevel);
    // cout<<'\n';

    // node* target = root->left->left;
    // cout<<target->data<<'\n';
    // printAtDistanceK(root,target,2);
    // cout<<'\n';

    // 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
    // cout<<"LCA of 4 and 7 is "<<lca(root,4,7)->data<<'\n';
    // cout<<"LCA of 6 and 9 is "<<lca(root,6,9)->data<<'\n';

    // 10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1
    // cout<<"Max Sum Path is "<<maxsum_path(root).maxsum<<endl;

    // 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
    cout<<"Dist of 4 and 7 is "<<findDistance(root,4,7)<<'\n';
    cout<<"Dist of 6 and 9 is "<<findDistance(root,6,9)<<'\n';
    return 0;
}