#include <iostream>
#include <string>
#include <vector>
#include "ProductManager.h"
#include "Customer.h"
#include "ShoppingCart.h"
#include "Order.h"

using namespace std;

// Hàm hiển thị menu chính
void showMenu() {
    cout << "\n--- HE THONG QUAN LY BAN HANG ---" << endl;
    cout << "1. Nhap thong tin khach hang" << endl;
    cout << "2. Tai danh sach san pham tu file" << endl;
    cout << "3. Xem danh sach san pham" << endl;
    cout << "4. Them san pham vao gio hang" << endl;
    cout << "5. Xem gio hang va cap nhat so luong" << endl;
    cout << "6. Tien hanh thanh toan (Tao don hang)" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "Chon chuc nang (0-6): ";
}

int main() {
    ProductManager pm;
    Customer currentCustomer;
    ShoppingCart currentCart;
    bool isCustomerSet = false;
    bool isProductLoaded = false;

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                currentCustomer.input();
                isCustomerSet = true;
                cout << "=> Cap nhat thong tin khach hang thanh cong!" << endl;
                break;
            }
            case 2: {
                // Gia su file du lieu la products.txt
                pm.loadFromFile("products.txt");
                isProductLoaded = true;
                break;
            }
            case 3: {
                if (!isProductLoaded) {
                    cout << "![Loi] Vui long tai danh sach san pham (Muc 2) truoc." << endl;
                } else {
                    pm.display();
                }
                break;
            }
            case 4: {
                if (!isProductLoaded) {
                    cout << "![Loi] Chua co du lieu san pham." << endl;
                    break;
                }
                string id;
                int qty;
                cout << "Nhap ma san pham (ID) muon mua: ";
                cin >> id;
                Product* p = pm.findByID(id);
                if (p != nullptr) {
                    cout << "Nhap so luong: ";
                    cin >> qty;
                    // Tao CartItem tu thong tin Product tim duoc
                    CartItem newItem(p->getID(), p->getName(), p->getPrice(), qty);
                    currentCart.addItem(newItem);
                    cout << "=> Da them vao gio hang." << endl;
                } else {
                    cout << "![Loi] Khong tim thay san pham voi ID: " << id << endl;
                }
                break;
            }
            case 5: {
                currentCart.displayCart();
                if (currentCart.getTotalPrice() > 0) {
                    cout << "Ban co muon cap nhat so luong? (1: Co, 0: Khong): ";
                    int subChoice; cin >> subChoice;
                    if (subChoice == 1) {
                        string id; int newQty;
                        cout << "Nhap ID san pham: "; cin >> id;
                        cout << "Nhap so luong moi: "; cin >> newQty;
                        currentCart.updateQuantity(id, newQty);
                    }
                }
                break;
            }
            case 6: {
                if (!isCustomerSet) {
                    cout << "![Loi] Vui long nhap thong tin khach hang (Muc 1) truoc khi thanh toan." << endl;
                    break;
                }
                if (currentCart.getTotalPrice() == 0) {
                    cout << "![Loi] Gio hang trong. Hay mua sam truoc khi thanh toan!" << endl;
                    break;
                }

                // Tao don hang voi ma don hang ngau nhien (Vi du: ORD123)
                Order myOrder("ORD" + to_string(rand() % 1000), currentCustomer, currentCart);
                
                // Quy trinh thiet lap don hang
                myOrder.inputDeliveryAddress();
                myOrder.calculateShippingFee();
                
                // Ket qua cuoi cung
                myOrder.displayOrderSummary();
                
                cout << "\nCam on ban da mua hang! Chuong trinh se lam moi gio hang." << endl;
                currentCart = ShoppingCart(); // Reset gio hang sau khi thanh toan
                break;
            }
            case 0:
                cout << "Dang thoat chuong trinh..." << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);

    return 0;
}
