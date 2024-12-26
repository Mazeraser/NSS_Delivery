#pragma once
#include <string>
#include "sqlite3.h"
#include <winsock2.h>
#include <vector>
#include <iomanip>
#include <ctime>

namespace SQL_Database {

    //��� �������������
    void addUser(sqlite3* db, const std::string& name, const std::string& password);
    bool loginUser(sqlite3* db, const std::string& name, const std::string& password);
    void deleteUser(sqlite3* db, const std::string& name);
    void displayUsers(sqlite3* db);

    void handleGetUserOrders(sqlite3* db, int clientSocket, const std::string& body);

    //��������������� ������� ��� ��������� �������������
    void handleAddUser(sqlite3* db, int clientSocket, const std::string& body);
    void handleLoginUser(sqlite3* db, int clientSocket, const std::string& body);
    void handleDeleteUser(sqlite3* db, int clientSocket, const std::string& body);
    void handleDisplayUsers(sqlite3* db, int clientSocket);

    // ���������� SQL �������
    void executeSQLScript(sqlite3* db, const std::string& scriptPath);
    // ��������� HTTP ������� (��� ��������� ��������)
    void handleHttpRequest(sqlite3* db, int clientSocket, const std::string& httpRequest);
    // ��������������� ������� ��� �������� HTTP ������
    void sendHttpResponse(int clientSocket, const std::string& status, const std::string& body);
    // ��������������� ������� ��� ���������� ������ �� ���� �������
    std::string extractData(const std::string& body, const std::string& key);
    bool isNumeric(const std::string& str);


    //��� ������� ������
    void addPickupPoint(sqlite3* db, const std::string& name, const std::string& address, double coordX, double coordY);
    void editPickupPoint(sqlite3* db, int pickupPointID, const std::string& name, const std::string& address, double coordX, double coordY);
    void deletePickupPoint(sqlite3* db, int pickupPointID);
    void displayPickupPoints(sqlite3* db);

    //��������������� ��� ������� ������
    void handleAddPickupPoint(sqlite3* db, int clientSocket, const std::string& body);
    void handleEditPickupPoint(sqlite3* db, int clientSocket, const std::string& body);
    void handleDeletePickupPoint(sqlite3* db, int clientSocket, const std::string& body);
    void handleDisplayPickupPoints(sqlite3* db, int clientSocket);

    //������
    void addOrder(sqlite3* db, const std::string& customerName, int pickupPointID, const std::vector<int>& productIds);
    void fastForwardOrdersBy24Hours(sqlite3* db);
    void markOrdersAsDelivered(sqlite3* db);

    void handleGetAllOrders(sqlite3* db, int clientSocket);
    void handlePlaceOrder(sqlite3* db, int clientSocket, const std::string& body);
    void handleCancelOrder(sqlite3* db, int clientSocket, const std::string& body);
    void handleSearchOrder(sqlite3* db, int clientSocket, const std::string& body);

    //��� �������� ��������� � ��
    void initializeProductsTable(sqlite3* db);

    void handleGetProducts(sqlite3* db, int clientSocket);


    std::time_t parseDateTime(const std::string& dateTimeStr);
    void handleOrderStatus(sqlite3* db, int clientSocket, const std::string& body);
}

