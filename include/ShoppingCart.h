#pragma once
#include "CartItem.h"
#include <vector>
#include <fstream>

class ShoppingCart 
{
private:
    vector<CartItem> items;
public:
    void addItem(CartItem item);
    void updateQuantity(string id, int newQty);
    double getTotalPrice();
    void displayCart();
    void loadFromFile(string filename);
};
