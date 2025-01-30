#include "../include/order.h"
#include <sstream>

// Конструктор
Order::Order(int orderId, const Product& prod, const std::string& client, const std::string& date,
    const std::string& orderStatus, const Point DeliveryPoint, int qty)
    : order_id(orderId), product(prod), client_name(client), order_date(date),
    status(orderStatus), quantity(qty), is_ready(false), delivery_point(DeliveryPoint){}

// Геттеры
int Order::getOrderId() const { return order_id; }
std::string Order::getProductName() const { return product.getName(); }
std::string Order::getClientName() const { return client_name; }
std::string Order::getStatus() const { return status; }

// Обновление статуса заказа
void Order::updateOrderStatus(const std::string& newStatus) {
    status = newStatus;
    is_ready = (status == "Готов");
}

// Проверка готовности заказа
bool Order::isOrderReady() const {
    return is_ready;
}

// Получение количества товаров
int Order::getOrderQuantity() const {
    return quantity;
}

Point Order::getDeliveryPoint() const {
    return delivery_point;
}

void Order::set_time(double Time) {
    order_time = Time;
}

// Формирование информации о заказе
std::string Order::getOrderInfo() const {
    std::ostringstream oss;
    oss << "ID Заказа: " << order_id << "\n"
        << "Продукт: " << product.getName() << "\n"
        << "Клиент: " << client_name << "\n"
        << "Дата заказа: " << order_date << "\n"
        << "Статус: " << status << "\n"
        << "Количество: " << quantity << "\n"
        << "Готовность: " << (is_ready ? "Да" : "Нет") << "\n"
        << "Время доставки: " << order_time << "\n";
    return oss.str();
}

void Order::set_courier(int courierId) {
    courier_id = courierId;
}

int Order::get_courier() const {
    return courier_id;
}