پروژه ساخت قراردادهای خودکار برای شرکت خدماتی

این پروژه برای اتوماتیک‌سازی فرآیند ایجاد قراردادهای فروش در یک شرکت خدماتی مرتبط با سفرهای داخلی و خارجی طراحی شده است. برنامه اطلاعات مربوط به مسئول اصلی، مشخصات مسافران و جزئیات تور را از کاربر دریافت می‌کند و یک فایل PDF از قرارداد ایجاد می‌کند.

---

ویژگی‌های پروژه

- دریافت اطلاعات مسئول اصلی (نام، نام خانوادگی، کد ملی، شماره تلفن).
- دریافت جزئیات تور (خدمات، شهر مقصد، وسیله نقلیه).
- دریافت مشخصات مسافران (نام، نام خانوادگی، نسبت، قیمت، نوع اتاق، درجه هتل و ...).
- ایجاد یک جدول برای نمایش اطلاعات مسافران.
- افزودن بندهای قرارداد به صورت خودکار.
- تولید فایل PDF با فرمت استاندارد.

---

فناوری‌های استفاده شده

- زبان برنامه‌نویسی: C++
- کتابخانه تولید PDF: libharu

---

پیش‌نیازها

برای اجرای این پروژه، نیاز به نصب ابزارهای زیر دارید:

1. کامپایلر C++ (مانند g++ یا clang).
2. کتابخانه libharu (برای تولید فایل‌های PDF).

---

نصب کتابخانه libharu

در سیستم‌های مبتنی بر Debian/Ubuntu:

sudo apt update
sudo apt install libhpdf-dev

نصب از سورس:

1. وابستگی‌های لازم را نصب کنید:

sudo apt install build-essential cmake libpng-dev

2. کتابخانه libharu را از GitHub کلون کنید:

git clone https://github.com/libharu/libharu
cd libharu

3. کتابخانه را کامپایل و نصب کنید:

mkdir build
cd build
cmake ..
make
sudo make install

---

نحوه کامپایل و اجرای پروژه

1. پروژه را کلون کنید (اگر از Git استفاده می‌کنید):

git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name

2. پروژه را کامپایل کنید:

- اگر از g++ استفاده می‌کنید:

g++ main.cpp contract.cpp -o contract_app -I/usr/local/include -L/usr/local/lib -lhpdf

- اگر از CMake استفاده می‌کنید:

mkdir build
cd build
cmake ..
make

3. برنامه را اجرا کنید:

./contract_app

خروجی یک فایل PDF با نام contract.pdf خواهد بود.

---

ساختار پروژه

/project-folder/
│
├── main.cpp          // فایل اصلی برنامه
├── contract.h        // فایل هدر برای تعریف ساختارها و توابع
├── contract.cpp      // فایل سورس برای پیاده‌سازی توابع
├── CMakeLists.txt    // فایل تنظیمات CMake (اختیاری)
└── README.txt        // توضیحات پروژه

---

مثال خروجی

پس از اجرای برنامه، یک فایل PDF با محتوای زیر ایجاد می‌شود:

Responsible: Ali Rezaei
National Code: 1234567890
Phone Number: 09123456789

Service: Tour Package
Destination: Paris
Vehicle: Airplane

Passengers:
- John Doe (Father) - 500
- Jane Doe (Mother) - 500

Contract Terms:
1. This is the first term of the contract.
2. This is the second term of the contract.

---

مشارکت

اگر می‌خواهید در توسعه این پروژه مشارکت کنید، لطفاً مراحل زیر را دنبال کنید:

1. پروژه را فورک (Fork) کنید.
2. یک برنچ (Branch) جدید ایجاد کنید (git checkout -b feature/YourFeatureName).
3. تغییرات خود را کامیت کنید (git commit -m 'Add some feature').
4. تغییرات را به برنچ اصلی پوش (Push) کنید (git push origin feature/YourFeatureName).
5. یک پول ریکوئست (Pull Request) ایجاد کنید.

---

لایسنس

این پروژه تحت لایسنس MIT منتشر شده است.
