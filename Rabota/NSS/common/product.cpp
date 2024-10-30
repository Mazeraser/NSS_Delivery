// product.cpp
#include "product.h"
#include <iostream>

// �����������
Product::Product(int productId, const std::string& productName, double productPrice, bool availability)
    : id(productId), name(productName), price(productPrice), isAvailable(availability) {}

// �������
int Product::getId() const { return id; }
std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
bool Product::getAvailability() const { return isAvailable; }

// �������
void Product::setId(int productId) { id = productId; }
void Product::setName(const std::string& productName) { name = productName; }
void Product::setPrice(double productPrice) { price = productPrice; }
void Product::setAvailability(bool availability) { isAvailable = availability; }

// ������� ��� ������ ���������� � ������
void Product::printProductInfo() const {
    std::cout << "ID ������: " << id << std::endl;
    std::cout << "��������: " << name << std::endl;
    std::cout << "����: " << price << std::endl;
    std::cout << "�������: " << (isAvailable ? "��" : "���") << std::endl;
} //��� ��� ���� ��������� ��� � ��� ����� �������� � ��������(����� ������ ����� ���������� "��������" ��������