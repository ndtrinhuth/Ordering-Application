#include "../include/ShoppingCart.h"

int main() {
    ShoppingCart cart;

    cart.loadFromFile("cart.txt");

    cart.addItem(CartItem("SP04", "Headphone", 800, 1));

    cart.updateQuantity("SP02", 5);

    cart.displayCart();

    return 0;
}
