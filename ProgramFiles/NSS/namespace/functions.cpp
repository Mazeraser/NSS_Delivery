#include "../include/order_pickup_point.h"
#include <iostream>

using namespace FunctionsOPPControl;


void FunctionsOPPControl::adminMenu() {
    std::cout << "\n--- ������������� (��������� ���) ---\n";
    std::cout << "1. ���������� ��� ������\n";
    std::cout << "2. ����� ����� �� ID\n";
    std::cout << "3. �������� ����� �����\n";
    std::cout << "4. ��������� � ������� ����\n";
}
void FunctionsOPPControl::clientMenu() {
    std::cout << "\n--- ������ ---\n";
    std::cout << "1. ���������� ��� ������\n";
    std::cout << "2. �������� ����� �����\n";
    std::cout << "3. ����� ����� �� ID\n";
    std::cout << "4. ��������� � ������� ����\n";
}