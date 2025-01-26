#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>
#include <vector>

// ساختارهای داده
struct Passenger {
    std::string firstName;
    std::string lastName;
    std::string relation;
    double price;
    std::string roomType;
    std::string hotelGrade;
};

struct Tour {
    std::string service;
    std::string destinationCity;
    std::string vehicle;
    std::vector<Passenger> passengers;
};

struct Contract {
    std::string responsibleName;
    std::string responsibleLastName;
    std::string nationalCode;
    std::string phoneNumber;
    Tour tourDetails;
};

// تعریف تابع
void createPDF(const Contract& contract);

#endif // CONTRACT_H