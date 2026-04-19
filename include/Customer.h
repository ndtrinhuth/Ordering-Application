#pragma once
#include <iostream>
#include <string>
#include <regex>
using namespace std;

// Lớp cha (Person)
class Person {
protected:
    string name;
    string phone;
    string address;

public:
    Person(string name = "", string phone = "", string address = "") {
        this->name = name;
        this->phone = phone;
        this->address = address;
    }

    // Hàm kiểm tra rỗng
    bool isEmpty(string str) {
        return str.empty();
    }

    // Hàm kiểm tra số điện thoại (10 số)
    bool isValidPhone(string phone) {
        regex pattern("^[0-9]{10}$"); // đúng 10 chữ số
        return regex_match(phone, pattern);
    }
};

// Lớp con (Customer kế thừa Person)
class Customer : public Person {
public:
    void input() {
        do {
            cout << "Nhap ten: ";
            getline(cin, name);
            if (isEmpty(name)) {
                cout << "Ten khong duoc de trong!\n";
            }
        } while (isEmpty(name));

        do {
            cout << "Nhap so dien thoai (10 so): ";
            getline(cin, phone);
            if (!isValidPhone(phone)) {
                cout << "So dien thoai khong hop le!\n";
            }
        } while (!isValidPhone(phone));

        do {
            cout << "Nhap dia chi: ";
            getline(cin, address);
            if (isEmpty(address)) {
                cout << "Dia chi khong duoc de trong!\n";
            }
        } while (isEmpty(address));
    }

    void display() {
        cout << "\n--- Thong tin khach hang ---\n";
        cout << "Ten: " << name << endl;
        cout << "So dien thoai: " << phone << endl;
        cout << "Dia chi: " << address << endl;
    }
};

// Hàm main
int main() {
    Customer c;
    c.input();
    c.display();
    return 0;
}
