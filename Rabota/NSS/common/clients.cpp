#include "clients.h"

// �������
int Client::getId() const { return id; }
std::string Client::getFirstName() const { return firstName; }
std::string Client::getLastName() const { return lastName; }
std::string Client::getMiddleName() const { return middleName; }
std::vector<Order> Client::getOrders() const { return orders; }

// �������
void Client::setFirstName(const std::string& fName) { firstName = fName; }
void Client::setLastName(const std::string& lName) { lastName = lName; }
void Client::setMiddleName(const std::string& mName) { middleName = mName; }
void Client::setId(int clientId) { id = clientId; }

#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

    WSADATA wsaData;
    SOCKET sock = INVALID_SOCKET;
    struct sockaddr_in server_address;
    const char* request = "������� �����";
    char buffer[BUFFER_SIZE] = { 0 };

    // ������������� WinSock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "������ ������������� WinSock: " << WSAGetLastError() << std::endl;
        return 1;
    }

    // �������� ������
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cerr << "������ �������� ������: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // ��������� ������ �������
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // ����������� � �������
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        std::cerr << "������ ����������� � �������: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    // �������� ������� �������
    send(sock, request, strlen(request), 0);
    std::cout << "������ ���������: " << request << std::endl;

    // ��������� ������ �� �������
    int bytes_read = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_read > 0) {
        std::cout << "����� �� �������: " << buffer << std::endl;
    }

    // �������� ������
    closesocket(sock);

    // ������� WinSock
    WSACleanup();

    return 0;
}
