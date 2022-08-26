#include<iostream>
#include<queue>
#include<climits>
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
        left = NULL;
        right = NULL;
    }
};

//Acccepts the old root node and data and returns the new root
node* insertinBST(node*root,int data)
{
    //base case
    if (root==NULL)
    {
        return new node(data);
    }

    //recursive case
    if(data<=root->data)
    {
        root->left = insertinBST(root->left,data);
    }
    else
    {
        root->right = insertinBST(root->right,data);
    }
    return root;
}
node* build()
{
    //Read a list of numbers till -1, these numbers will be inserted into BST
    int d;
    cin>>d;
    node*root = NULL;
    while(d!=-1)
    {
        root = insertinBST(root,d);
        cin>>d;
    }
    return root;
}
void inorder(node*root)
{
    if(root==NULL)
    {
        return;
    }

    // Otherwise print root followed by subtrees (children)
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
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
bool search(node*root,int data)
{
    if(root==NULL) return false;
    if(root->data==data) return true;

    // recursively search in left and right subtree
    if(data<=root->data) search(root->left,data);
    return search(root->right,data);
}
node* deleteinBST(node*root,int data)
{
    if(root==NULL) return NULL;

    else if(data<root->data)
    {
        root->left = deleteinBST(root->left,data);
        return root;
    }

    else if(data>root->data)
    {
        root->right = deleteinBST(root->right,data);
        return root;
    } 

    else
    {
        //Found the node to delete 
        //3 cases

        //1.Node with 0 children - leaf node
        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            return NULL;
        }

        //2.Node with 1 children 
        if(root->left!=NULL && root->right==NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL)
        {
            node*temp = root->right;
            delete root;
            return temp;
        }

        //3.Node with 2 children
        node* replace = root->right;
        //Find the inorder successor from right subtree
        while(replace->left!=NULL)
        {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteinBST(root->right,replace->data);

        return root;
    }
}
bool isBST(node*root,int minv = INT_MIN,int maxv = INT_MAX)
{
    if(root==NULL) return true;
    bool isleft = isBST(root->left,minv,root->data);
    bool isright = isBST(root->right,root->data,maxv);
    if(root->data>=minv && root->data<=maxv && isleft && isright)
    {
        return true;
    }
    return false;
}
class LinkedList
{
public:
    node*head;
    node*tail;
};
LinkedList flatten(node*root)
{
    LinkedList l;
    if(root==NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }

    //Leaf Node
    if(root->left==NULL && root->right==NULL)
    {
        l.head =l.tail = root;
        return l;
    }

    // Left is not NULL
    if(root->left!=NULL && root->right==NULL)
    {
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;
        
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }

    // Right is not NULL
    if(root->left==NULL && root->right!=NULL)
    {
        LinkedList rightLL = flatten(root->right);
        root->right = rightLL.head;
        
        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }

    // Both sides are not NULL
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;
    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}
int main()
{
    node*root = build(); // 5 3 7 1 6 8 -1
    inorder(root);
    cout<<'\n';
    bfs(root);

    // int s;
    // cin>>s;

    // if(search(root,s))
    // {
    //     cout<<"Present\n";
    // }
    // else cout<<"Not present";

    // root = deleteinBST(root,s);
    // inorder(root);

    // if(isBST(root)) cout<<"Yes\n";
    // else cout<<"No\n";

    LinkedList l = flatten(root);
    node*temp = l.head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->right;
    }
    cout<<'\n';
    return 0;
}