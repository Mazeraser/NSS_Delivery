#include "courier.h"
#include <iostream>

Courier::Courier(OPP& opp, double Speed, int ID) {
    pos = new Point(opp.getCoordX(), opp.getCoordY());
    speed_kmh = Speed;
    main_opp = &opp;
    id = ID;
    current_order_id = -1; // Изначально курьер свободен
}

Courier::~Courier() {
    delete pos;
}

void Courier::set_order(Order* order) {
    if (is_available()) {
        current_order_id = order->getOrderId();
        Point sec_pos = order->getDeliveryPoint();
        order->set_time(PointManager::get_distance(pos, &sec_pos) / speed_kmh);
    }
}

void Courier::set_point(Point point) {
    *pos = point;
}

int Courier::get_order() const {
    return current_order_id;
}

bool Courier::is_available() const {
    return current_order_id == -1;
}

void Courier::complete_order() {
    current_order_id = -1;
}

int Courier::get_id() const {
    return id;
}

OPP* Courier::get_opp() const {
    return main_opp;
}