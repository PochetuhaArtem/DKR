#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

class Customer {
private:
    int id;
    std::string surname;
    std::string name;
    int cardNumber;
    int bankAccountNumber;

public:
    Customer(int id, std::string surname, std::string name, int cardNumber, int bankAccountNumber)
        : id(id), surname(surname), name(name), cardNumber(cardNumber), bankAccountNumber(bankAccountNumber) {}

    // getters
    int getId() const { return id; }
    std::string getSurname() const { return surname; }
    std::string getName() const { return name; }
    int getCardNumber() const { return cardNumber; }
    int getBankAccountNumber() const { return bankAccountNumber; }

    // setters
    void setId(int id) { this->id = id; }
    void setSurname(std::string surname) { this->surname = surname; }
    void setName(std::string name) { this->name = name; }
    void setCardNumber(int cardNumber) { this->cardNumber = cardNumber; }
    void setBankAccountNumber(int bankAccountNumber) { this->bankAccountNumber = bankAccountNumber; }

    // toString method
    std::string toString() const {
        return "Customer: " + std::to_string(id) + ", " + surname + ", " + name + ", " + std::to_string(cardNumber) + ", " + std::to_string(bankAccountNumber);
    }

    // overload << operator
    friend std::ostream& operator<<(std::ostream& os, const Customer& customer) {
        os << customer.toString();
        return os;
    }
};