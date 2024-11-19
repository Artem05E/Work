#include <iostream>

class DateTime {
private:
    int year, month, day, hour, minute, second;

    bool isValidDate(int y, int m, int d) {
        if (m < 1 || m > 12 || d < 1 || d > 31) return false;
        return true;
    }

    bool isValidTime(int h, int min, int sec) {
        return (h >= 0 && h < 24) && (min >= 0 && min < 60) && (sec >= 0 && sec < 60);
    }

public:

    DateTime() : year(2000), month(1), day(1), hour(0), minute(0), second(0) {}

    DateTime(int y, int m, int d, int h, int min, int sec) {
        if (isValidDate(y, m, d) && isValidTime(h, min, sec)) {
            year = y;
            month = m;
            day = d;
            hour = h;
            minute = min;
            second = sec;
        } else {
            throw std::invalid_argument("неверно");
        }
    }

    void setDateTime(int y, int m, int d, int h, int min, int sec) {
        if (isValidDate(y, m, d) && isValidTime(h, min, sec)) {
            year = y;
            month = m;
            day = d;
            hour = h;
            minute = min;
            second = sec;
        } else {
            throw std::invalid_argument("неверно");
        }
    }

    void printDateTime() {
        std::cout << "Дата: " << day << "." << month << "." << year
                  << " время: " << hour << ":" << minute << ":" << second << std::endl;
    }

    bool isNewYear() {
        return day == 1 && month == 1;
    }
};

int main() {
    try {
        DateTime dt; 
        dt.printDateTime();

        DateTime dt2(2025, 1, 1, 0, 0, 0); 
        dt2.printDateTime();

        std::cout << "Новый Год? " << (dt2.isNewYear() ? "да" : "нет") << std::endl;

        dt.setDateTime(2024, 12, 31, 23, 59, 59); 
        dt.printDateTime();

        std::cout << "Новый Год? " << (dt.isNewYear() ? "да" : "нет") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

