#pragma once
#include <iostream>
#include <string>
#include <ctime> // Thư viện xử lý ngày giờ hệ thống
#include "Customer.h"
#include "ShoppingCart.h"

using namespace std;

class Order 
{
private:
    string orderId;
    Customer customer;
    ShoppingCart cart;
    string deliveryAddress;
    
    // Sử dụng kiểu time_t để lưu mốc thời gian chuẩn
    time_t orderDate;             
    time_t expectedDeliveryDate;  
    
    double shippingFee;

    // Hàm hỗ trợ (private) để định dạng ngày tháng in ra màn hình
    string formatDate(time_t dateObj);

public:
    // Constructors
    Order();
    Order(string id, Customer cust, ShoppingCart currentCart);

    // 1. Nhập địa chỉ giao hàng (có thể khác địa chỉ mặc định của Customer)
    void inputDeliveryAddress();

    // 2. Lấy ngày giờ hệ thống làm ngày đặt hàng
    void setSystemOrderDate();

    // 3. Tính ngày giao hàng dự kiến (Mặc định cộng thêm số ngày nhất định)
    void calculateExpectedDeliveryDate(int estimatedDays = 3);

    // 4. Tính phí ship dựa trên địa chỉ
    void calculateShippingFee();

    // Lấy tổng tiền cuối cùng (Tiền hàng + Phí ship)
    double getFinalTotal();

    // Hiển thị thông tin đơn hàng
    void displayOrderSummary();
};
