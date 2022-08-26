#include<iostream>
#include<cstring>
using namespace std;
// access specifiers - public and private
class Car{
private:
    float price;
public:
    int model_no;
    char *name;
    const int msp;

    // Constructor
    Car():msp(99)
    {
        name = NULL;
    }

    // Paramterized constructor
    Car(float p, int m,char *n,int minprice = 99):price(p),msp(minprice)
    {
        price = p;
        model_no = m;
        name = new char[strlen(n)+1];
        strcpy(name,n);
    }

    Car(const Car &x):msp(x.msp){
        cout<<"Inside copy constructor\n";
        price = x.price;
        model_no = x.model_no;
        name = new char[strlen(x.name)+1];
        strcpy(name,x.name);
    }

    void operator=(Car &x)
    {
        cout<<"Inside copy assignment constructor\n";
        price = x.price;
        model_no = x.model_no;
        name = new char[strlen(x.name)+1];
        strcpy(name,x.name);
    }

    float get_discounted_price(const float x) const{
        return price*(1.0-x);
    }
    
    float apply_discount(const float x)
    {
        price = price * (1.0-x);
        return price;
    }

    void setprice(float p)
    {
        price = p;
    }

    void print()
    {
        cout<<"Name "<<name<<'\n';
        cout<<"Model no "<<model_no<<'\n';
        cout<<"Price "<<price<<'\n';
    }

    float get_price() const{
        return price;
        // members of class cannot be modified in constant functions
    }

    ~Car()
    {
        cout<<"Destroying car "<<name<<'\n';
        if(name!=NULL)
        {
            delete[] name;
        }
    }
};
int main()
{
    char arr[100] = "BMW";
    Car c(100,200,arr); // paramterized constructor
    // Car d(c); // copy constructor
    cout<<c.msp<<'\n';

    Car d; 
    d = c; // copy assignment constructor

    d.name[0] = 'A';
    d.setprice(400);

    c.print();
    d.print();
    
    // Dynamically created car
    char ename[100] = "Ferrari";
    Car *e = new Car(10,20,ename);
    e->print();
    delete e;
    return 0;
}