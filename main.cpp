#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../include/ProductManager.h"
#include "../include/Customer.h"
#include "../include/ShoppingCart.h"
#include "../include/Order.h"

using namespace std;

void hienThiMenu() {
    cout << "\n========== HE THONG DAT HANG SMART ORDER ==========" << endl;
    cout << "1. Nhap thong tin khach hang" << endl;
    cout << "2. Tai danh sach san pham tu kho (File)" << endl;
    cout << "3. Xem danh muc san pham" << endl;
    cout << "4. Chon mua san pham (Them vao gio)" << endl;
    cout << "5. Xem gio hang & Cap nhat so luong" << endl;
    cout << "6. Thanh toan & Xuat hoa don" << endl;
    cout << "0. Thoat" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Lua chon cua ban: ";
}

int main() {
    srand(time(0)); // Khoi tao so ngau nhien cho Ma don hang
    ProductManager khoHang;
    Customer khachHang;
    ShoppingCart gioHang;
    
    bool daCoKhachHang = false;
    bool daTaiSanPham = false;

    int luaChon;
    do {
        hienThiMenu();
        if (!(cin >> luaChon)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (luaChon) {
            case 1: {
                cin.ignore();
                khachHang.input();
                daCoKhachHang = true;
                cout << "=> Luu thong tin khach hang thanh cong!" << endl;
                break;
            }
            case 2: {
                // Dam bao ban co file products.txt dung cau truc trong thu muc du an
                khoHang.loadFromFile("products.txt");
                daTaiSanPham = true;
                cout << "=> Da tai du lieu tu kho hang." << endl;
                break;
            }
            case 3: {
                if (!daTaiSanPham) {
                    cout << "[!] Vui long tai du lieu (Muc 2) truoc." << endl;
                } else {
                    cout << "\n--- DANH MUC SAN PHAM ---" << endl;
                    khoHang.display();
                }
                break;
            }
            case 4: {
                if (!daTaiSanPham) {
                    cout << "[!] Kho hang dang trong." << endl;
                    break;
                }
                string id;
                int sl;
                cout << "Nhap Ma san pham muon mua: ";
                cin >> id;
                Product* p = khoHang.findByID(id);
                if (p != nullptr) {
                    cout << "Nhap so luong: ";
                    cin >> sl;
                    CartItem item(p->getID(), p->getName(), p->getPrice(), sl);
                    gioHang.addItem(item);
                    cout << "=> Da them " << p->getName() << " vao gio." << endl;
                } else {
                    cout << "[!] Khong tim thay ID: " << id << endl;
                }
                break;
            }
            case 5: {
                cout << "\n--- GIO HANG HIEN TAI ---" << endl;
                gioHang.displayCart();
                if (gioHang.getTotalPrice() > 0) {
                    cout << "Ban co muon sua so luong? (1: Co, 0: Khong): ";
                    int x; cin >> x;
                    if (x == 1) {
                        string id; int sl_moi;
                        cout << "Nhap ID san pham: "; cin >> id;
                        cout << "Nhap so luong moi: "; cin >> sl_moi;
                        gioHang.updateQuantity(id, sl_moi);
                        cout << "=> Da cap nhat." << endl;
                    }
                }
                break;
            }
            case 6: {
                if (!daCoKhachHang) {
                    cout << "[!] Vui long nhap thong tin khach hang (Muc 1) truoc." << endl;
                    break;
                }
                if (gioHang.getTotalPrice() == 0) {
                    cout << "[!] Gio hang dang trong!" << endl;
                    break;
                }

                // Tao don hang voi ID ngau nhien
                string maDH = "ORD" + to_string(rand() % 9000 + 1000);
                Order donHang(maDH, khachHang, gioHang);
                
                donHang.inputDeliveryAddress();
                donHang.calculateShippingFee();
                donHang.displayOrderSummary();
                
                cout << "\n=> Dat hang thanh cong! Gio hang se duoc lam moi." << endl;
                gioHang = ShoppingCart(); // Reset gio hang
                break;
            }
            case 0:
                cout << "Tam biet!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
    } while (luaChon != 0);

    return 0;
}
