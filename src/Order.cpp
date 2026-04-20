#define _CRT_SECURE_NO_WARNINGS
#include "../include/Order.h"
#include <iomanip> // Để format tiền tệ

// Helper format ngày giờ thành chuỗi dd/mm/yyyy
string Order::formatDate(time_t dateObj) {
    char buffer[80];
    // Chuyển time_t sang cấu trúc tm (time structure)
    struct tm* timeinfo = localtime(&dateObj);
    // Định dạng ngày/tháng/năm
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", timeinfo);
    return string(buffer);
}

// Constructor mặc định
Order::Order() {
    orderId = "UNKNOWN";
    shippingFee = 0.0;
    orderDate = time(0);
    expectedDeliveryDate = time(0);
}

// Constructor có tham số để "Tạo đơn hàng"
Order::Order(string id, Customer cust, ShoppingCart currentCart) {
    orderId = id;
    customer = cust;
    cart = currentCart;
    shippingFee = 0.0;
    
    // Tự động gọi các hàm thiết lập ngày giờ khi tạo đơn
    setSystemOrderDate();
    calculateExpectedDeliveryDate(3); // Mặc định giao trong 3 ngày
}

// Nhập địa chỉ giao hàng
void Order::inputDeliveryAddress() {
    cout << "--- Nhap Thong Tin Giao Hang ---" << endl;
    cout << "Nhap dia chi giao hang: ";
    cin.ignore(); // Xóa bộ nhớ đệm trước khi dùng getline
    getline(cin, deliveryAddress);
}

// Lấy ngày hệ thống hiện tại
void Order::setSystemOrderDate() {
    // time(0) trả về timestamp của hiện tại
    orderDate = time(0); 
}

// Tính ngày giao dự kiến bằng cách cộng thêm 'estimatedDays' vào orderDate
void Order::calculateExpectedDeliveryDate(int estimatedDays) {
    // 1 ngày = 24 giờ * 60 phút * 60 giây = 86400 giây
    expectedDeliveryDate = orderDate + (estimatedDays * 86400);
}

// Tính phí ship (Logic ví dụ)
void Order::calculateShippingFee() {
    // Nếu địa chỉ trống, chưa thể tính
    if (deliveryAddress.empty()) {
        shippingFee = 0;
        return;
    }

    // Chuyển địa chỉ về chữ thường để dễ so sánh (giả lập)
    string lowerAddress = "";
    for(char c : deliveryAddress) {
        lowerAddress += tolower(c);
    }

    // Logic mô phỏng: Nếu ở HCM/Hồ Chí Minh thì phí 15k, còn lại 35k
    if (lowerAddress.find("hcm") != string::npos || lowerAddress.find("ho chi minh") != string::npos) {
        shippingFee = 15000.0;
    } else {
        shippingFee = 35000.0;
    }
}

// Tính tổng thanh toán
double Order::getFinalTotal() {
    return cart.getTotalPrice() + shippingFee;
}

// Hiển thị hóa đơn
void Order::displayOrderSummary() {
    cout << "\n========================================" << endl;
    cout << "          HOA DON MUA HANG              " << endl;
    cout << "========================================" << endl;
    cout << "Ma don hang: " << orderId << endl;
    
    // Gọi hàm display của customer (giả định Customer có hàm này)
    customer.display(); 
    
    cout << "Dia chi nhan hang: " << deliveryAddress << endl;
    cout << "Ngay dat hang: " << formatDate(orderDate) << endl;
    cout << "Ngay giao du kien: " << formatDate(expectedDeliveryDate) << endl;
    cout << "----------------------------------------" << endl;
    
    // Gọi hàm display của giỏ hàng (giả định ShoppingCart có hàm này)
    cart.displayCart();
    
    cout << "----------------------------------------" << endl;
    cout << "Tong tien hang: " << fixed << setprecision(0) << cart.getTotalPrice() << " VNĐ" << endl;
    cout << "Phi van chuyen: " << shippingFee << " VNĐ" << endl;
    cout << "----------------------------------------" << endl;
    cout << "TONG THANH TOAN: " << getFinalTotal() << " VNĐ" << endl;
    cout << "========================================" << endl;
}
