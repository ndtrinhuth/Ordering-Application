#include "Product.h"

// Constructor
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

// Getter
string Product::getID() const {
    return id;
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

// Setter
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

// Input
void Product::input() {
    cout << "Enter ID: ";
    getline(cin, id);

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter price: ";
    cin >> price;
    cin.ignore();
}

// Output
void Product::output() const {
    cout << "ID: " << id
        << " | Name: " << name
        << " | Price: " << price << endl;
}

// Operator >>
istream& operator>>(istream& in, Product& p) {
    cout << "Enter ID: ";
    getline(in, p.id);

    cout << "Enter name: ";
    getline(in, p.name);

    cout << "Enter price: ";
    in >> p.price;
    in.ignore();

    return in;
}

// Operator <<
ostream& operator<<(ostream& out, const Product& p) {
    out << "ID: " << p.id
        << " | Name: " << p.name
        << " | Price: " << p.price;
    return out;
}
