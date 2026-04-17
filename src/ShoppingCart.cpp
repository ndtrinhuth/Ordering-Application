#include "../include/ShoppingCart.h"

void ShoppingCart::addItem(CartItem item) {
    items.push_back(item);
}
void ShoppingCart::updateQuantity(string id, int newQty) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].getId() == id) {
            items[i].setQuantity(newQty);
            return;
        }
    }
}

double ShoppingCart::getTotalPrice() {
    double sum = 0;
    for (int i = 0; i < items.size(); i++) {
        sum += items[i].getTotal();
    }
    return sum;
}

void ShoppingCart::displayCart() {
    for (int i = 0; i < items.size(); i++) {
        items[i].display();
    }
    cout << "Total Cart: " << getTotalPrice() << endl;
}

void ShoppingCart::loadFromFile(string filename) {
    ifstream in(filename);
    int n;
    in >> n;

    for (int i = 0; i < n; i++) {
        string id, name;
        double price;
        int quantity;
        in >> id >> name >> price >> quantity;
        items.push_back(CartItem(id, name, price, quantity));
    }
    in.close();
}
