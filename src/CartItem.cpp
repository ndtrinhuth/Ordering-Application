#include "../include/CartItem.h"

CartItem::CartItem() {}

CartItem::CartItem(string id, string name, double price, int quantity) {
    this->id = id;
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

double CartItem::getTotal() {
    return price * quantity;
}

void CartItem::display() {
    cout << id << " - " << name
         << " | Price: " << price
         << " | Qty: " << quantity
         << " | Total: " << getTotal() << endl;
}

string CartItem::getId() {
    return id;
}

void CartItem::setQuantity(int quantity) {
    this->quantity = quantity;
}
