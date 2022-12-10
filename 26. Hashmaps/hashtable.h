#include<iostream>
#include<cstring>
using namespace std;
template<typename T>
class node
{
public:
    string key;
    T value;
    node<T>* next;

    node(string key,T val)
    {
        this->key = key;
        value = val;
        next = NULL;
    }

    ~node()
    {
        if(next!=NULL)
        {
            delete next;
            // recurive destructor call
        }
    }
};

template<typename Y>
class Hashtable
{
    node<Y>** table; //pointer to an array of pointers
    int current_size;
    int table_size;

    int hashfn(string key)
    {
        int idx = 0;
        int p = 1;
        for(int i=0;i<key.length();i++)
        {
            idx = idx+((key[i])*p)%table_size;
            idx = idx%table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }
    void rehash()
    {
        node<Y>**oldtable = table;
        int oldtablesize = table_size;
        table_size = 2*table_size; //approximation, can also find the next prime number
        table = new node<Y>*[table_size]; 

        for(int i=0;i<table_size;i++)
        {
            table[i] = NULL;
        }
        current_size = 0;

        //shift the elements from the old table to new table
        for(int i=0;i<oldtablesize;i++)
        {
            node<Y>*temp = oldtable[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->value);
                temp = temp->next;
            }
            if(oldtable[i]!=NULL)
            {
                delete oldtable[i]; // deletes the linked list
            }
        }
        delete [] oldtable; // deletes the older smaller array
    }
public:
    Hashtable(int ts = 7)
    {
        table_size = ts;
        table = new node<Y>*[table_size];
        current_size = 0;
        for(int i=0;i<table_size;i++)
        {
            table[i] = NULL;
        }
    }
    void insert(string key,Y value)
    {
        int idx = hashfn(key);

        node<Y>*n = new node<Y>(key,value);
        //Insert at the head of the linked list with id=idx
        n->next = table[idx];
        table[idx] = n;
        current_size++;

        //rehash
        float load_factor = current_size/(1.0*table_size);
        if(load_factor>0.7)
        {
            rehash();
        }
    }
    void print()
    {
        for(int i=0;i<table_size;i++)
        {
            cout<<"Bucket "<<i<<" : ";
            node<Y>*temp = table[i];
            while(temp!=NULL)
            {
                cout<<temp->key<<"->";
                temp = temp->next;
            } 
            cout<<'\n';
        }
        cout<<'\n';
    }
    Y* search(string key)
    {
        int idx = hashfn(key);
        node<Y>*temp = table[idx];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return &(temp->value);
            }
            temp = temp->next;
        }
        return NULL;
    }
    Y& operator[](string key)
    {
        Y* f = search(key);
        if(f==NULL)
        {
            Y garbage;
            insert(key,garbage);
            f = search(key);
        }
        return *f;
    }
    void erase(string key)
    {
        int idx = hashfn(key);
        node<Y>*temp = table[idx];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                break;
            }
            temp = temp->next;
        }
        node<Y>*prev = table[idx];
        while(prev!=NULL && prev->next!=temp)
        {
            prev = prev->next;
        }

        if(prev==NULL && temp==NULL)
        {
            return;
        }
        else if(prev==NULL && temp!=NULL)
        {
            
            table[idx] = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }
};