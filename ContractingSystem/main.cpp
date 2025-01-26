#include <iostream>
#include "contract.h"

int main() {
    // مثال داده‌های قرارداد
    Contract contract;
    contract.responsibleName = "Ali";
    contract.responsibleLastName = "Rezaei";
    contract.nationalCode = "1234567890";
    contract.phoneNumber = "09123456789";

    contract.tourDetails.service = "Tour Package";
    contract.tourDetails.destinationCity = "Paris";
    contract.tourDetails.vehicle = "Airplane";

    contract.tourDetails.passengers.push_back({"John", "Doe", "Father", 500, "Single", "5-star"});
    contract.tourDetails.passengers.push_back({"Jane", "Doe", "Mother", 500, "Single", "5-star"});

    // ایجاد PDF
    createPDF(contract);

    std::cout << "PDF created successfully!" << std::endl;
    return 0;
}