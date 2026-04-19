#include "../include/ProductManager.h"

void ProductManager::loadFromFile(string fileName) {
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

void ProductManager::display() {
    if (productList.empty()) {
        cout << "Danh sach trong!" << endl;
        return;
    }
    for (const auto& p : productList) {
        cout << p << endl;
    }
}

Product* ProductManager::findByID(string id) {
    for (int i = 0; i < (int)productList.size(); i++) {
        if (productList[i].getID() == id) {
            return &productList[i];
        }
    }
    return nullptr;
}

bool ProductManager::checkData() {
    return !productList.empty();
}
