#include<iostream>
#include<cstring>
using namespace std;
// access specifiers - public and private
class Car{
private:
    float price;
public:
    int model_no;
    char name[100];

    // Constructor
    Car()
    {
        cout<<"Inside Car constructor"<<'\n';
    }

    // Paramterized constructor
    Car(float p, int m,string n)
    {
        price = p;
        model_no = m;
        int i=0,l = n.length();
        while(i<l)
        {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
    }

    // Copy Constructor
    Car(Car &x)
    {
        cout<<"Copy constructor\n";
        price = x.price;
        model_no = x.model_no;
        strcpy(name,x.name);
    }
    void print()
    {
        cout<<"Name "<<name<<'\n';
        cout<<"Model no "<<model_no<<'\n';
        cout<<"Price "<<price<<'\n';
    }

    float get_discounted_price(float x)
    {
        return price*(1.0-x);
    }
    
    float apply_discount(float x)
    {
        price = price * (1.0-x);
        return price;
    }

    void set_price(float p) // Setter
    {
        int msp = 111;
        if(p>0) price = p;
        else price = msp;
    }

    float get_price() // Getter
    {
        return price;
    }
};
int main()
{
    Car c;
    Car d(222,333,"Audi");
    Car e(d); // or Car e = d;
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';
    c.set_price(120);
    c.print();
    cout<<"Car D\n";
    d.print();
    cout<<"Car E\n";
    e.print();
}