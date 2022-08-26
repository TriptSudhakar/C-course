#include<iostream>
using namespace std;
class Car{
    int price;
    int model_no;
    char name[100];
};
int main()
{
    Car c;
    cout<<sizeof(c)<<'\n';
    cout<<sizeof(Car)<<'\n';
}