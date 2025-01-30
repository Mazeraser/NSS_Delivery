#pragma once
#include <string>
#include "product.h"
#include "point.h"

class Order {
private:
    int order_id;
    int courier_id;
    Product product;           // Продукт, связанный с заказом
    std::string client_name;
    std::string order_date;
    std::string status;
    int quantity;
    bool is_ready;
    Point delivery_point;
    double order_time;

public:
    // Конструктор заказа
    Order(int orderId, const Product& prod, const std::string& client, const std::string& date,
        const std::string& orderStatus, const Point DeliveryPoint, int qty);

    // Функции для работы с заказом
    void updateOrderStatus(const std::string& newStatus);
    bool isOrderReady() const;
    int getOrderQuantity() const;
    std::string getOrderInfo() const;
    void set_time(double Time);

    // Геттеры
    int getOrderId() const;
    std::string getProductName() const;
    std::string getClientName() const;
    std::string getStatus() const;
    Point getDeliveryPoint() const;

    void set_courier(int courierId);
    int get_courier() const;

};
