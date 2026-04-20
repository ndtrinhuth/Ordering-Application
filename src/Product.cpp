#include "../include/Product.h"

Product::Product() {
    id = "";
    name = "";
    price = 0;
}

Product::Product(string id, string name, double price) {
    this->id = id;
    this->name = name;
    this->price = price;
}

Product::~Product() {}

string Product::getID() const {
    return id;
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void Product::setID(string id) {
    this->id = id;
}

void Product::setName(string name) {
    this->name = name;
}

void Product::setPrice(double price) {
    if (price >= 0)
        this->price = price;
    else
        this->price = 0;
}

void Product::output() const {
    cout << "ID: " << id
        << " | Name: " << name
        << " | Price: " << price;
}

ostream& operator<<(ostream& out, const Product& p) {
    p.output();
    return out;
}


FoodProduct::FoodProduct() : Product() {}

FoodProduct::FoodProduct(string id, string name, double price)
    : Product(id, name, price) {
}

void FoodProduct::output() const {
    cout << "[Food] ";
    Product::output();
}


ElectronicProduct::ElectronicProduct() : Product() {}

ElectronicProduct::ElectronicProduct(string id, string name, double price)
    : Product(id, name, price) {
}

void ElectronicProduct::output() const {
    cout << "[Electronic] ";
    Product::output();
}
