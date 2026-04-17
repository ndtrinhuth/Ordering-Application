#pragma once
#include <iostream>
using namespace std;

class CartItem 
{
private:
    string id;
    string name;
    double price;
    int quantity;
public:
    CartItem();
    CartItem(string id, string name, double price, int quantity);

    double getTotal();
    void display();

    string getId();
    void setQuantity(int quantity);
};
