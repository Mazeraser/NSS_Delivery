#include "../include/order_pickup_point.h"
#include <string>
#include <vector>
#include "../include/order.h"
#include <iostream>
#include <fstream>
#include <sstream>

#define CLIENTS_FILE "clients.txt" //  ??? ?????, ??? ???????? ???????


// ������� ��� ���������� ������ ������� � ���� ������
void FunctionsOPPControl::clientLoginOrRegister() {
    std::string firstName, lastName;
    std::cout << "������� ���: ";
    std::cin >> firstName;
    std::cout << "������� �������: ";
    std::cin >> lastName;

    // ��������, ���������� �� ������ � ���� ������
    if (clientExists(firstName, lastName)) {
        std::cout << "����� ���������� �������, " << firstName << " " << lastName << "!" << std::endl;
    }
    else {
        std::cout << "������ �� ������. ������� ����� �������." << std::endl;
        addClient(firstName, lastName);
    }
}

int FunctionsOPPControl::generateUniqueClientId() {
    static int lastId = 0;

    // ������ ���������� ID �� �����
    std::ifstream file(CLIENTS_FILE);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int id;
            iss >> id;
            if (id > lastId) {
                lastId = id;
            }
        }
    }
    return ++lastId;
}
void FunctionsOPPControl::addClient(const std::string& firstName, const std::string& lastName) {
    int clientId = generateUniqueClientId();
    std::ofstream file(CLIENTS_FILE, std::ios::app);

    if (!file.is_open()) {
        std::cerr << "�� ������� ������� ���� ��� ������ �������." << std::endl;
        return;
    }

    // ���������� ������� � ������ ������� �������
    file << clientId << " " << lastName << " " << firstName << " 0 []" << std::endl;
    file.close();

    std::cout << "������ " << firstName << " " << lastName << " ������� �������� � ID " << clientId << "." << std::endl;
}

bool FunctionsOPPControl::clientExists(const std::string& firstName, const std::string& lastName) {
    std::ifstream file(CLIENTS_FILE);
    if (!file.is_open()) {
        std::cerr << "�� ������� ������� ���� � ���������." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int id, numOrders;
        std::string fName, lName;
        iss >> id >> lName >> fName >> numOrders;
        if (fName == firstName && lName == lastName) {
            return true;
        }
    }
    return false;
}
void FunctionsOPPControl::showAllClients() {
    std::ifstream file(CLIENTS_FILE);
    if (!file.is_open()) {
        std::cerr << "�� ������� ������� ���� � ���������." << std::endl;
        return;
    }

    std::string line;
    std::cout << "\n--- ������ �������� ---\n";
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int id, numOrders;
        std::string firstName, lastName;
        std::string orders;

        // ������ ������ �� ������
        if (iss >> id >> lastName >> firstName >> numOrders) {
            // ������ ���������� ����� ������ ��� ������ �������
            std::getline(iss, orders);
            std::cout << "ID: " << id << "\n"
                << "�������: " << lastName << "\n"
                << "���: " << firstName << "\n"
                << "���������� �������: " << numOrders << "\n"
                << "������: " << orders << "\n\n";
        }
    }
    file.close();
}


// �����������
PVZ::PVZ(int id, const std::string& name, double x, double y)
    : id(id), name(name), coordX(x), coordY(y) {}

// �������
int PVZ::getId() const {
    return id;
}
std::string PVZ::getName() const {
    return name;
}
double PVZ::getCoordX() const {
    return coordX;
}
double PVZ::getCoordY() const {
    return coordY;
}

// ����� ���������� � ���
void PVZ::printPVZInfo() const {
    std::cout << "��� ID: " << id
        << ", ��������: " << name
        << ", ����������: (" << coordX << ", " << coordY << ")\n";
}

void FunctionsOPPControl::addPVZToFile(const PVZ& pvz) {
    std::ofstream file("pvz_data.txt", std::ios::app);
    if (file.is_open()) {
        file << pvz.getId() << " " << pvz.getName() << " "
            << pvz.getCoordX() << " " << pvz.getCoordY() << "\n";
        file.close();
    }
    else {
        std::cerr << "������: �� ������� ������� ���� ��� ������.\n";
    }
}

// �������� ������ ��� ���������������
void FunctionsOPPControl::adminCreatePVZ() {
    int id = generateUniquePVZId();  // �������������� ���������� ID
    double x, y;
    std::string name;

    std::cout << "�������� ������ ���\n";
    std::cout << "ID ���: " << id << " (������������� ��������)\n";
    std::cout << "������� �������� ���: ";
    std::cin >> name;
    std::cout << "������� ���������� X: ";
    std::cin >> x;
    std::cout << "������� ���������� Y: ";
    std::cin >> y;

    PVZ newPVZ(id, name, x, y);
    addPVZToFile(newPVZ);
    std::cout << "��� ������� ������ � �������� � ����.\n";
}


// ������ ���� ��� �� ����� � ����� �� �����
void FunctionsOPPControl::showAllPVZ() {
    std::ifstream file("pvz_data.txt");
    if (!file.is_open()) {
        std::cerr << "������: �� ������� ������� ����.\n";
        return;
    }

    std::cout << "\n������ ���� ���:\n";
    int id, x, y;
    std::string name;
    while (file >> id >> name >> x >> y) {
        std::cout << "ID: " << id << ", ��������: " << name
            << ", ����������: (" << x << ", " << y << ")\n";
    }
    file.close();
}

