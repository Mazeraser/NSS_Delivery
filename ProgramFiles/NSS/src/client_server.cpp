#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h> // ��� ������� inet_pton
#pragma comment(lib, "Ws2_32.lib") // ����������� ���������� WinSock
#define PORT 8080 // ��������� ���� ��� �����������

int main() {
    WSADATA wsaData;

    // ������������� WinSock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "������ ������������� WinSock" << std::endl;
        return 1;
    }

    SOCKET clientSocket;
    struct sockaddr_in serverAddr;

    // �������� ����������� ������
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "������ �������� ������: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // ��������� ������ �������
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);

    // ������� IP-����� ������� (��������, 127.0.0.1 ��� ���������� �����������)
    const char* serverIP = "127.0.0.1";
    if (inet_pton(AF_INET, serverIP, &serverAddr.sin_addr) <= 0) {
        std::cerr << "�������� ����� ��� ����� �� ��������������" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // ����������� � �������
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "������ �����������: " << WSAGetLastError() << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "����������� � ������� �������!" << std::endl;

    // �������� ������ ����� ���������� ������
    closesocket(clientSocket);

    // ������� WinSock
    WSACleanup();
    return 0;
}