#include<iostream>
using namespace std;
// access specifiers - public and private
class Car{
private:
    float price;
public:
    int model_no;
    char name[100];

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
    Car arr[20];

    Car c;
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';
    c.set_price(120);
    // cout<<c.name<<" Model no "<<c.model_no<<" Price "<<c.price<<'\n';

    // cout<<"Enter the discount you want to give\n";
    // float discount;
    // cin>>discount;

    // cout<<c.apply_discount(discount)<<'\n';

    c.print();
    cout<<sizeof(c)<<'\n';
    cout<<sizeof(Car)<<'\n';
}