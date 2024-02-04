#include "bitset.hpp"

Bitset::Bitset() : bitsize(8), bit(new int[bitsize]) {
    validity=true;
    for (size_t i = 0; i < bitsize; i++) {
        bit[i] = 0;
    }
}

Bitset::Bitset(intmax_t size) : bitsize(size >= 0 ? size :0), bit(new int[bitsize]) {
    validity=true;
    if (size<=0){
        validity = false;
    }
    for (size_t i = 0; i < bitsize; i++) {
        bit[i] = 0;
    }
}

Bitset::Bitset(const std::string &value) : bitsize(value.size()), bit(new int[bitsize]) {
	validity=true;
    if (bitsize<=0){
        validity = false;
    }
    for (size_t i = 0; i < bitsize; i++) {
			bit[i] = value[i] - '0';
            if (bit[i] != 0 && bit[i] != 1){
                validity = false;
            }
	}
}

Bitset::~Bitset() {
    delete[] bit;
}

bool Bitset::test(intmax_t index) {
    if (index >= 0 && index < bitsize) {
        if (bit[index] == 1){
            return true;
        }
        else if (bit[index] == 0){
            return false;
        }
        else{
            validity = false;
            return false;
        }
    }
    else{
        validity = false;
        return false;
    }
}

intmax_t Bitset::size() const {
    return bitsize;
}

bool Bitset::good() const {
    if (bitsize <= 0 || bitsize > 50000){
        validity = true;
        return false;
    }
    
    if (validity == false){
        validity = true;
        return false;
    }

    for (int i = 0; i < bitsize; i++) {
        if (bit[i] != 0 && bit[i] != 1) {
            validity = true;
            return false;
        }
    }
    return true;
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
        if (bit[index] == 0){
            bit[index] = 1;
        }
        else if (bit[index] == 1){
            bit[index] = 0;
        }
        else{
            validity = false;
        }
    }
    else {
        validity = false;
    }
}

void Bitset::set(intmax_t index) {
    if (index >= 0 && index < bitsize) {
        if (bit[index] == 0) {
            bit[index] = 1;
        }
    }
    else{
        validity = false;
    }
}

void Bitset::reset(intmax_t index) {
    if (index >= 0 && index < bitsize) {
        if (bit[index] == 1) {
            bit[index] = 0;
        }
    }
    else{
        validity = false;
    }
}