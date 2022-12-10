#include<iostream>
#include"hashtable.h"
using namespace std;

int main()
{
    Hashtable<int> price_menu;
    price_menu.insert("Burger",120);
    price_menu.insert("Pepsi",30);
    price_menu.insert("BurgerPizza",150);
    price_menu.insert("Noodles",55);
    price_menu.insert("Coke",40);
    price_menu.print();

    int *price = price_menu.search("Noodles");
    if(price==NULL)
    {
        cout<<"Not found\n";
    }
    else
    {
        cout<<"Price is "<<*price<<'\n';
    }
    price_menu.erase("Coke");
    price_menu.print();

    price_menu["Dosa"] = 60;
    price_menu["Dosa"] += 10;
    cout<<"Price of Dosa is "<<price_menu["Dosa"]<<'\n';
    price_menu.erase("Burger");
    price_menu.print();
    return 0;
}