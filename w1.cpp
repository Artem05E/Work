#include <iostream>

union ByteOrderChecker {
    uint32_t value; 
    uint8_t bytes[4]; 
};

int main() {
    ByteOrderChecker checker;
    checker.value = 0x01020304;

    if (checker.bytes[0] == 0x04) {
        std::cout << "младший байт впереди" << std::endl;
    } else if (checker.bytes[0] == 0x01) {
        std::cout << "старший байт впереди" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }

    return 0;
}