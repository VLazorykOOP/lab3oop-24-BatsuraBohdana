#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

class Date {
private:
    int day, month, year;
    static const string months[12];

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    bool isValid(int d, int m, int y) const {
        if (y < 0 || m < 1 || m > 12) return false;
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear(y)) daysInMonth[1] = 29;
        return d >= 1 && d <= daysInMonth[m - 1];
    }

public:
    // Конструктор за замовчуванням
    Date() : day(1), month(1), year(2000) {}

    // Конструктор з параметрами
    Date(int d, int m, int y) {
        setDate(d, m, y);
    }

    // Метод встановлення дати
    void setDate(int d, int m, int y) {
        if (isValid(d, m, y)) {
            day = d;
            month = m;
            year = y;
        } else {
            cout << "Некоректна дата! Встановлено 1.01.2000" << endl;
            day = 1;
            month = 1;
            year = 2000;
        }
    }

    // Геттери
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Вивід у форматі "5 січня 2019 року"
    void printLongFormat() const {
        cout << day << " " << months[month - 1] << " " << year << " року" << endl;
    }

    // Вивід у форматі "05.01.2019"
    void printShortFormat() const {
        cout << setfill('0') << setw(2) << day << "." << setw(2) << month << "." << year << endl;
    }
};

// Ініціалізація назв місяців
const string Date::months[12] = {
    "січня", "лютого", "березня", "квітня", "травня", "червня",
    "липня", "серпня", "вересня", "жовтня", "листопада", "грудня"
};

// Функція тестування можливостей класу
int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    cout << "Дата за замовчуванням:\n";
    Date defaultDate;
    defaultDate.printLongFormat();
    defaultDate.printShortFormat();

    cout << "\nСтворення дати з параметрами (5.1.2019):\n";
    Date customDate(5, 1, 2019);
    customDate.printLongFormat();
    customDate.printShortFormat();

    cout << "\nСпроба встановити некоректну дату (32.13.2023):\n";
    Date invalidDate(32, 13, 2023);
    invalidDate.printLongFormat();
    invalidDate.printShortFormat();

    return 0;
}
