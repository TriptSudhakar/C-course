#include<iostream>
using namespace std;
template<typename T>
class node
{
public:
    string key;
    T value;
    Node<T>* next;

    Node(string key,T val)
    {
        this->key = key;
        value = val;
        next = NULL;
    }

    ~Node()
    {
        if(next!=NULL)
        {
            delete next;
        }
    }
};

template<typename Y>
class Hashtable
{
    node<Y>** table; //pointer to an array of pointer
    int current_size;
    int table_size;

public:
    Hashtable(int ts = 7)
    {
        table_size = ts;
        table = new node<T>*[table_size];
        current_size = 0;
        for(int i=0;i<table_size;i++)
        {
            table[i] = NULL;
        }
        void insert(string key,Y value)
        {
            //..
        }

        T search(string key)
        {

        }
        void erase(string key)
        {
            
        }
    }
};
int main()
{
    return 0;
}