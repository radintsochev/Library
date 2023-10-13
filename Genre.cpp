#include "Genre.h"
#include <iostream>
#include <bitset>

Genre::Genre() = default;

Genre::Genre(size_t number) {
    data = number;
}

void Genre::setCharacteristic(Characteristic characteristic) {
    data ^= ((long long)1 << size_t(characteristic));
    toggleControl();
}

void Genre::setType(Type type) {
    data ^= ((long long)1 << (7 + size_t(type)));
    toggleControl();
}

void Genre::setTargetAudience(TargetAudience audience) {
    data ^= ((long long)1 << (11 + size_t(audience)));
    toggleControl();
}

void Genre::toggleControl() {
    data ^= ((long long)1 << 15);
}

bool Genre::validate() {
    bool evenOnes = true;
    size_t number = data;
    while (number != 0) {
        evenOnes = !evenOnes;
        number = number & (number - 1);
    }
    return evenOnes;
}

void Genre::display() const {
    std::cout << "Genre ID: " << std::bitset<16>(data) << std::endl;
}

bool operator==(const Genre& lhs, const Genre& rhs) {
    return lhs.data == rhs.data;
}

bool operator!=(const Genre& lhs, const Genre& rhs) {
    return !(lhs == rhs);
}