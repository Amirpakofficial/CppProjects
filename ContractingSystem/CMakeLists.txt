cmake_minimum_required(VERSION 3.10)
project(ContractApp)

# پیدا کردن کتابخانه libharu
find_package(HPDF REQUIRED)

# اضافه کردن فایل‌های سورس
add_executable(contract_app main.cpp contract.cpp)

# لینک کردن کتابخانه libharu
target_link_libraries(contract_app HPDF::HPDF)