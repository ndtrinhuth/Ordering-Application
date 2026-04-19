#pragma once
#include <iostream>
using namespace std;

class Customer
{
private:
    string name;
    string phone;
    string address;

public:
    Customer();
    Customer(string name, string phone, string address);

    void input();      // nhập dữ liệu
    void display();    // hiển thị

    bool isValidPhone(string phone); // kiểm tra SĐT
};
