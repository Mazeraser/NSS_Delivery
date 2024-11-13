/*#include <iostream>
#include <winsock2.h> // �������� ��������� ��� WinSock
#include <ws2tcpip.h> // ��� �������������� ������� ������� (��������, getaddrinfo)

#pragma comment(lib, "Ws2_32.lib") // ����������� ���������� WinSock

#define PORT 8080 // ��������� ����

int main() {
    WSADATA wsaData;

    // ������������� WinSock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "������ ������������� WinSock" << std::endl;
        return 1;
    }

    int server_fd;
    SOCKET new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // �������� ������
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        std::cerr << "������ �������� ������: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // ��������� ������ (SO_REUSEADDR ��� ���������� ������������� ������)
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt)) == SOCKET_ERROR) {
        std::cerr << "������ ��������� ���������� ������: " << WSAGetLastError() << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    // ��������� ������ �������
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;  // �������� �� ���� �����������
    address.sin_port = htons(PORT);        // �������������� ����� � ������� ������� ����

    // �������� ������ � ������
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        std::cerr << "������ �������� ������: " << WSAGetLastError() << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    // ������������� �������� ����������
    if (listen(server_fd, 3) == SOCKET_ERROR) {
        std::cerr << "������ �������������: " << WSAGetLastError() << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    std::cout << "�������� �����������..." << std::endl;

    // �������� ������ �����������
    new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);
    if (new_socket == INVALID_SOCKET) {
        std::cerr << "������ �������� �����������: " << WSAGetLastError() << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    std::cout << "������ ���������!" << std::endl;

    // �������� ������� ����� ���������� ������
    closesocket(new_socket);
    closesocket(server_fd);

    // ������� WinSock
    WSACleanup();

    return 0;
}
*/