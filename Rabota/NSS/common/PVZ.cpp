#include "PVZ.h"
#include <string>
#include <vector>
#include "order.h"
#include <iostream>
#include <fstream>
#include <sstream>

#define CLIENTS_FILE "clients.txt" // ��� �����, ��� �������� �������

// ������� ��� �������� ������������� ������� � ���� ������
bool FunctionsPVZControl :: clientExists(const std::string& firstName, const std::string& lastName) {
    std::ifstream file(CLIENTS_FILE);
    if (!file.is_open()) {
        std::cerr << "�� ������� ������� ���� � ���������." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string fName, lName;
        if (iss >> fName >> lName) {
            if (fName == firstName && lName == lastName) {
                return true;
            }
        }
    }
    return false;
}

// ������� ��� ���������� ������ ������� � ���� ������
void FunctionsPVZControl :: addClient(const std::string& firstName, const std::string& lastName) {
    std::ofstream file(CLIENTS_FILE, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "�� ������� ������� ���� ��� ������ �������." << std::endl;
        return;
    }

    file << firstName << " " << lastName << "\n";
    file.close();
    std::cout << "������ " << firstName << " " << lastName << " ������� �������� � ���� ������." << std::endl;
}
void FunctionsPVZControl :: clientLoginOrRegister() {
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
