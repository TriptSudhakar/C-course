#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;    

    node(int d)
    {
        data=d;
        next=NULL;
    }
};

// Linked list class (object oriented)
// class LinkedList
// {
//     node* head;
//     node* tail;

//     public:
//     LinkedList()
//     {
//         head=NULL;
//         tail=NULL;
//     }
//     void insert(int d)
//     {}
// };

// Functions (procedural programming)
// passing a pointer by reference
void insertAtHead(node* &head,int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    node* n = new node(d);
    n->next = head; // same as (*n).next = head;
    head = n;
}

int length(node* head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}

void insertAtTail(node*&head,int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    node* tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}

void insertInMiddle(node*&head,int d,int p)
{
    //corner case
    if(head==NULL||p==0)
    {
        insertAtHead(head,d);
        return;
    }
    else if(p>length(head))
    {
        insertAtTail(head,d);
        return;
    }
    else
    {
        int jump = 1;
        node* temp = head;
        while(jump<p)
        {
            temp=temp->next;
            jump++;
        }
        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

void deleteHead(node*&head)
{
    if(head==NULL)
    {
        return;
    }
    node* temp = head->next;
    delete head;
    head = temp;
}

// Search operation
bool search(node*head,int key)
{
    node* temp = head;
    while(temp!= NULL)
    {
        if(head->data==key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<'\n';
}

node* take_input()
{
    int d;
    cin>>d;

    node* head = NULL;

    while(d!=-1)
    {
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}

node* input()
{
    int d;
    node*head = NULL;
    while(cin>>d)
    {
        insertAtHead(head,d);
    }
    return head;
}

// Cascading of operators;
ostream& operator<<(ostream &os,node*head)
{
    print(head);
    return os; // returning by reference
}

istream& operator>>(istream &is,node*&head)
{
    head = take_input();
    return is;
}

void reverse(node*&head)
{
    node* c = head,*p = NULL,*n;
    while(c!=NULL)
    {
        // save the next node
        n = c->next;
        // make the current node point to prev
        c->next = p;

        // update p and c
        p = c;
        c = n;
    }
    head = p;
    return;
}

node* recursive_reverse(node *&head)
{
    // base case
    if(head->next==NULL || head==NULL)
    {
        return head;
    }

    // recursive case
    node* shead = recursive_reverse(head->next);
    // node* temp = head->next;
    // temp->next = head;
    head->next->next = head;
    head->next = NULL;
    return shead;
}

node* midpoint(node*head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node*slow = head;
    node*fast = head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* merge(node*a,node*b)
{
    // base case
    if(a== NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }

    // take a head pointer
    node*c;
    if(a->data<b->data)
    {
        c = a;
        c->next = merge(a->next,b);
    }
    else
    {
        c = b;
        c->next = merge(a,b->next);
    }
    return c;
}

node* merge_sort(node*head)
{
    // base case
    if(head==NULL||head->next==NULL){return head;}

    // recursive case;
    // 1. Break
    node*mid = midpoint(head);
    node*a = head;
    node*b = mid->next;
    mid->next = NULL;

    // 2. Recursive call on two parts
    a = merge_sort(a);
    b = merge_sort(b);

    // 3. Merge them
    node*c = merge(a,b);
    return c;
}
int main()
{
    // node* head = NULL;
    // insertAtHead(head,3);
    // insertAtHead(head,2);
    // insertAtHead(head,1);
    // insertAtHead(head,0);
    // print(head);
    // insertInMiddle(head,4,3);
    // insertAtTail(head,7);
    // print(head);

    // if(search(head,1))
    // {
    //     cout<<"Element found\n";
    // }

    // node* head = input();

    // Overloading << and >> operators
    // node* head = take_input();
    // node* head2 = take_input();

    // node*head,*head2;
    // cin>>head>>head2;
    // cout<<head<<head2;

    // node*head;
    // cin>>head;
    // cout<<head;
    // head = recursive_reverse(head);
    // cout<<head;

    // node*mid = midpoint(head);
    // cout<<mid->data<<'\n';

    // node* head1,*head2;
    // cin>>head1>>head2;
    // node* newhead = merge(head1,head2);
    // cout<<newhead;

    node*head;
    cin>>head;
    head = merge_sort(head);
    cout<<head;
    return 0;
}