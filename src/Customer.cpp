#include "Customer.h"

// Constructor
Customer::Customer()
{
    name = "";
    phone = "";
    address = "";
}

Customer::Customer(string name, string phone, string address)
{
    this->name = name;
    this->phone = phone;
    this->address = address;
}

// Hàm kiểm tra số điện thoại (chỉ gồm số, độ dài 10)
bool Customer::isValidPhone(string phone)
{
    if (phone.length() != 10) return false;

    for (char c : phone)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

// Nhập dữ liệu
void Customer::input()
{
    do {
        cout << "Enter name: ";
        getline(cin, name);
        if (name.empty())
            cout << "Name cannot be empty!\n";
    } while (name.empty());

    do {
        cout << "Enter phone (10 digits): ";
        getline(cin, phone);
        if (!isValidPhone(phone))
            cout << "Invalid phone number!\n";
    } while (!isValidPhone(phone));

    do {
        cout << "Enter address: ";
        getline(cin, address);
        if (address.empty())
            cout << "Address cannot be empty!\n";
    } while (address.empty());
}

// Hiển thị
void Customer::display()
{
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Address: " << address << endl;
}
