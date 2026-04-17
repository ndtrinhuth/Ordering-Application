#pragma once
#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string id;
    string name;
    double price;

public:
    Product();
    Product(string id, string name, double price);

    virtual ~Product();

    string getID() const;
    string getName() const;
    double getPrice() const;

    void setID(string id);
    void setName(string name);
    void setPrice(double price);

    virtual void output() const;

    friend ostream& operator<<(ostream& out, const Product& p);
};

class FoodProduct : public Product {
public:
    FoodProduct();
    FoodProduct(string id, string name, double price);

    void output() const override;
};

class ElectronicProduct : public Product {
public:
    ElectronicProduct();
    ElectronicProduct(string id, string name, double price);

    void output() const override;
};
