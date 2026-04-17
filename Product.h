#pragma once
#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string id;
    string name;
    double price;

public:
    // Constructor
    Product();
    Product(string id, string name, double price);

    // Getter
    string getID() const;
    string getName() const;
    double getPrice() const;

    // Setter
    void setID(string id);
    void setName(string name);
    void setPrice(double price);

    // Input / Output
    void input();
    void output() const;

    // Operator overloading
    friend istream& operator>>(istream& in, Product& p);
    friend ostream& operator<<(ostream& out, const Product& p);
};
