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
    void loadFromFile(string fileName) {
        ifstream file(fileName);
        if (!file.is_open()) return;

        productList.clear();
        int count;
        if (!(file >> count)) return;

        string id, name;
        double price;
        int qty;

        while (file >> id >> name >> price >> qty) {
            Product temp(id, name, price);
            productList.push_back(temp);
        }
        file.close();
    }

    void display() {
        if (productList.empty()) {
            cout << "Danh sach trong!" << endl;
            return;
        }
        for (const auto& p : productList) {
            cout << p << endl;
        }
    }

    Product* findByID(string id) {
        for (int i = 0; i < (int)productList.size(); i++) {
            if (productList[i].getID() == id) {
                return &productList[i];
            }
        }
        return nullptr;
    }

    bool checkData() {
        return !productList.empty();
    }
};

#endif#pragma once
