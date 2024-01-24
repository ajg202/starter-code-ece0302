#include "bitset.hpp"

Bitset::Bitset() : bitsize(8), bit(new int[bitsize]) {
    for (size_t i = 0; i < bitsize; i++) {
        bit[i] = 0;
    }
}

Bitset::Bitset(intmax_t size) : bitsize(size), bit(new int[bitsize]) {
    for (size_t i = 0; i < bitsize; i++) {
        bit[i] = 0;
    }
}

Bitset::Bitset(const std::string &value) : bitsize(value.size()), bit(new int[bitsize]) {
	for (size_t i = 0; i < bitsize; i++) {
			bit[i] = value[i] - '0';
	}
}

Bitset::~Bitset() {
    delete[] bit;
}

bool Bitset::test(intmax_t index) {
    return (bit[index]==1);
}

intmax_t Bitset::size() const {
    return bitsize;
}

bool Bitset::good() const {
    if (bitsize>0){
		for (size_t i = 0; i < bitsize; i++) {
            if (bit[i] != 0 && bit[i] != 1) {
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

string Bitset::asString() const {
    string value;
    for (int i = 0; i < bitsize; i++) {
        value = value+to_string(bit[i]);
    }
    return value;
}

void Bitset::toggle(intmax_t index) {
    if (index >= 0 && index < bitsize) {
        bit[index] = 1 - bit[index];
    }
}

void Bitset::set(intmax_t index) {
    if (index >= 0 && index < bitsize) {
        bit[index] = 1;
    }
}

void Bitset::reset(intmax_t index) {
    if (index >= 0 && index < bitsize) {
        bit[index] = 0;
    }
}