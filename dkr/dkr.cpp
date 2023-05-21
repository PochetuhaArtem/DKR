// dkr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "Customer.cpp"
#include "Logger.cpp"

int main() {
    std::vector<Customer> customers = {
        Customer(1, "Ivanov", "Ivan", 1234, 12345),
        Customer(2, "Petrov", "Petr", 2345, 23456),
        // add more customers
    };

    // sort customers by surname
    std::sort(customers.begin(), customers.end(), [](const Customer& a, const Customer& b) {
        return a.getSurname() < b.getSurname();
        });

    // print customers
    for (const Customer& customer : customers) {
        std::cout << customer << std::endl;
        Logger::log("Printed customer: " + customer.toString());
    }

    // print customers with card number in range
    int lower = 1000;
    int upper = 2000;
    for (const Customer& customer : customers) {
        if (customer.getCardNumber() >= lower && customer.getCardNumber() <= upper) {
            std::cout << customer << std::endl;
            Logger::log("Printed customer with card number in range: " + customer.toString());
        }
    }

    std::ofstream file("customers.txt");
    if (file.is_open()) {
        for (const Customer& customer : customers) {
            std::string line = customer.toString();
            // Просте XOR шифрування
            for (char& c : line) {
                c ^= 123;
            }
            file << line << std::endl;
        }
        file.close();
    }

    return 0;
}
