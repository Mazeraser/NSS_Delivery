#pragma once
#include "point.h"
#include "order.h"
#include "point_manager.h"
#include "order_pickup_point.h"
#include <fstream>

class Courier {
private:
	int id;
	double speed_kmh;
	int current_order_id;
	Point* pos;
	OPP* main_opp;
	
public:
    Courier(OPP& opp, double Speed, int ID);
    ~Courier();

    void set_order(Order* order);
    void set_point(Point point);
    int get_order() const;
    bool is_available() const;
    void complete_order();
    int get_id() const;
    OPP* get_opp() const;
};