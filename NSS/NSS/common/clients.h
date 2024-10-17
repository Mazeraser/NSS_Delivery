#include <string>
#include <vector>
#include "order.h"
#include <iostream>

class Client {
private:
    int id;                         // ID �������
    std::string firstName;           // ���
    std::string lastName;            // �������
    std::string middleName;          // ��������
    std::vector<Order> orders;       // ������ ������� �������
    std::vector<Order> receivedOrders; // ������ ��������� �������
public:
    // ����������� ������ Client
    Client(int clientId, const std::string& fName, const std::string& lName, const std::string& mName)
        : id(clientId), firstName(fName), lastName(lName), middleName(mName) {}

    // ������� ��� ������� � �����
    int getId() const { return id; }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getMiddleName() const { return middleName; }
    std::vector<Order> getOrders() const { return orders; }

    // ������� ��� ��������� �����
    void setFirstName(const std::string& fName) { firstName = fName; }
    void setLastName(const std::string& lName) { lastName = lName; }
    void setMiddleName(const std::string& mName) { middleName = mName; }
    void setId(int clientId) { id = clientId; }

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