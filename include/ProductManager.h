#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Product.h"

using namespace std;

class ProductManager {
private:
    vector<Product> productList;

public:
    void loadFromFile(string fileName);
    void display();
    Product* findByID(string id);
    bool checkData();
};

#endif
