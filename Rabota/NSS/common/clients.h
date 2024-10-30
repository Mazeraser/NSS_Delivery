#include <string>
#include <vector>
#include "order.h"
#include <iostream>

class Client {
private:
    int id;
    std::string firstName;
    std::string lastName;
    std::string middleName;
    std::vector<Order> orders;
    std::vector<Order> receivedOrders;
public:
    // ������� ��� ������� � �����
    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getMiddleName() const;
    std::vector<Order> getOrders() const;

    // ������� ��� ��������� �����
    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setMiddleName(const std::string& mName);
    void setId(int clientId);

    // ��������� ������� ��� ���������� ������ �� �������� ������
    void placeOrder(const std::string& productName);

    // ��������� ������� ��� ������ ������ �� ���������� (ID, ���, ������ ������)
    void searchOrderByID(int id);
    void searchOrderByFullName(const std::string& fullName); //����� ��������� ����� � ���� �������
    void searchOrderByStatus(const std::string& status);

    // ��������� ������� ��� ������ ������ (����� ������ �� ����������)
    void pickOrderByParameters(const std::string& productName, const std::string& clientName);

    void removeOrder(int orderId);
    // ������� ��� ������ ���������� � �������
    
    Order returnOrder(std::string reason);

    void printClientInfo();
};