#include "../include/order_pickup_point.h"
#include <iostream>
#include <random>  // ��� ��������� ��������� �����
#include <set>     // ��� �������� ������������ ID
#include <fstream>

using namespace FunctionsOPPControl;


void FunctionsOPPControl::adminMenu() {
    std::cout << "\n--- ������������� ---\n";
    std::cout << "1. ���������� ��� ������\n";
    std::cout << "2. ����� ����� �� ID\n";
    std::cout << "3. �������� ����� �����\n";
    std::cout << "4. ������� ����� ���\n";
    std::cout << "5. �������� ��� ���\n";
    std::cout << "6. �������� ���� ��������\n";
    std::cout << "7. ��������� � ������� ����\n";
    std::cout << "�������� �����: ";
}
void FunctionsOPPControl::clientMenu() {
    std::cout << "\n--- ������ ---\n";
    std::cout << "1. ���������� ��� ������\n";
    std::cout << "2. �������� ����� �����\n";
    std::cout << "3. ����� ����� �� ID\n";
    std::cout << "4. ��������� � ������� ����\n";
}

int FunctionsOPPControl::generateUniquePVZId() {
    std::set<int> existingIds;
    std::ifstream file("pvz_data.txt");

    // ��������� ������������ ID �� ����� � ��������� �� � ���������
    if (file.is_open()) {
        int id;
        std::string name;
        double x, y;
        while (file >> id >> name >> x >> y) {
            existingIds.insert(id);
        }
        file.close();
    }

    // ��������� ������ ����������� ID
    int newId;
    do {
        newId = rand() % 10000 + 1;  // ��������� ���������� ����� �� 1 �� 10000
    } while (existingIds.find(newId) != existingIds.end());

    return newId;
}