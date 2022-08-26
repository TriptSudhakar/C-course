#include<iostream>
using namespace std;
class Vector
{
    int *arr;
    int cs;
    int maxsize;

public:
    Vector(int defaultsize = 4)
    {
        maxsize = defaultsize;
        cs = 0;
        arr = new int[maxsize];
    }

    void push_back(int data)
    {
        if(cs==maxsize)
        {
            // Doubling operations
            int *oldarr = arr;
            arr = new int[2*maxsize];
            maxsize *= 2;

            for(int i=0;i<cs;i++)
            {
                arr[i] = oldarr[i];
            }

            // Delete the old array;
            delete[] oldarr;
        }
        arr[cs] = data;
        cs++;
    }

    bool empty(){return cs==0;}
    void pop_back()
    {
        if(!empty()){ cs--;}
    }

    int getSize()
    {return cs;}


    int getMaxSize()
    {return maxsize;}
    void print()
    {
        for(int i=0;i<cs;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
    }

    int at(int i)
    {
        return arr[i];
    }

    int& operator[](int i)
    {
        return arr[i];  
    }

};
ostream& operator<<(ostream &os,Vector &v)
{
    cout<<"In << operator"<<'\n';
    v.print();
    return os;
}
int main()
{
    Vector v;
    for(int i=0;i<4;i++)
    {
        v.push_back(i*i);
    }
    cout<<v.getMaxSize()<<'\n';
    v.push_back(7);
    cout<<v.getMaxSize()<<'\n';
    // v.print();
    Vector fun(v);
    cout<<v<<fun;

    v[2] = 8;
    v[2] += 6;
    cout<<v[2]<<'\n';
    return 0;
}