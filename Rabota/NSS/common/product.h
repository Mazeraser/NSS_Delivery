#include <string>

class Product {
private:
    int id;                 // ID ������
    std::string name;        // �������� ������
    double price;            // ���� ������
    bool isAvailable;        // ������ �������

public:
    // �����������
    Product(int productId, const std::string& productName, double productPrice, bool availability);

    // �������
    int getId() const;
    std::string getName() const;
    double getPrice() const;
    bool getAvailability() const;

    // �������
    void setId(int productId);
    void setName(const std::string& productName);
    void setPrice(double productPrice);
    void setAvailability(bool availability);

    // ������� ��� ������ ���������� � ������
    void printProductInfo() const; //��� ������ ����� ����� ����� �������� �� ���������� ��������� ������
};