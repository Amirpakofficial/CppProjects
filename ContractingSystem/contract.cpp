#include "contract.h"
#include <hpdf.h>
#include <iostream>

void createPDF(const Contract& contract) {
    // ایجاد یک سند PDF جدید
    HPDF_Doc pdf = HPDF_New(NULL, NULL);
    if (!pdf) {
        std::cerr << "Error: Cannot create PDF document." << std::endl;
        return;
    }

    // ایجاد یک صفحه جدید
    HPDF_Page page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

    // تنظیم فونت و اندازه
    HPDF_Font font = HPDF_GetFont(pdf, "Helvetica", NULL);
    HPDF_Page_SetFontAndSize(page, font, 12);

    // موقعیت شروع متن
    float y = HPDF_Page_GetHeight(page) - 50;

    // افزودن مشخصات مسئول
    HPDF_Page_BeginText(page);
    HPDF_Page_TextOut(page, 50, y, ("Responsible: " + contract.responsibleName + " " + contract.responsibleLastName).c_str());
    y -= 20;
    HPDF_Page_TextOut(page, 50, y, ("National Code: " + contract.nationalCode).c_str());
    y -= 20;
    HPDF_Page_TextOut(page, 50, y, ("Phone Number: " + contract.phoneNumber).c_str());
    y -= 40;
    HPDF_Page_EndText(page);

    // افزودن جزئیات تور
    HPDF_Page_BeginText(page);
    HPDF_Page_TextOut(page, 50, y, ("Service: " + contract.tourDetails.service).c_str());
    y -= 20;
    HPDF_Page_TextOut(page, 50, y, ("Destination: " + contract.tourDetails.destinationCity).c_str());
    y -= 20;
    HPDF_Page_TextOut(page, 50, y, ("Vehicle: " + contract.tourDetails.vehicle).c_str());
    y -= 40;
    HPDF_Page_EndText(page);

    // افزودن جدول مسافران
    HPDF_Page_BeginText(page);
    HPDF_Page_TextOut(page, 50, y, "Passengers:");
    y -= 20;
    for (const auto& passenger : contract.tourDetails.passengers) {
        HPDF_Page_TextOut(page, 50, y, (passenger.firstName + " " + passenger.lastName + " - " + passenger.relation + " - " + std::to_string(passenger.price)).c_str());
        y -= 20;
    }
    HPDF_Page_EndText(page);

    // افزودن بندهای قرارداد
    HPDF_Page_BeginText(page);
    HPDF_Page_TextOut(page, 50, y, "Contract Terms:");
    y -= 20;
    HPDF_Page_TextOut(page, 50, y, "1. This is the first term of the contract.");
    y -= 20;
    HPDF_Page_TextOut(page, 50, y, "2. This is the second term of the contract.");
    HPDF_Page_EndText(page);

    // ذخیره فایل PDF
    HPDF_SaveToFile(pdf, "contract.pdf");
    HPDF_Free(pdf);
}