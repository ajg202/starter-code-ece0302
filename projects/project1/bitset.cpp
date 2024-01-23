#include "bitset.hpp"

Bitset::Bitset() : bitsize(0), bit(new int(bitsize)) {
    // TODO
}

Bitset::Bitset(intmax_t size) : bitsize(size), bit(new int (bitsize)){
    for (size_t i=0;i<bitsize;i++){
        bit[i] = 0;
    }
    // TODO
}

Bitset::Bitset(const std::string & value) {
    for (size_t i=0;i<bitsize;i++){
        if (value[i] != '0' && value[i] != '1'){
            exit(1);
        }
        else {
            bit[i] = value[i] - '0';
        }
    }
    // TODO
}

Bitset::~Bitset() {
    // TODO
}

// TODO: other methods

bool Bitset::test(intmax_t index){
    if (bitsize<=0){
        return 0;
    }
    else{
        return 1;
    }
}

intmax_t Bitset::size() const {
    return bitsize;
}

bool Bitset::good() const {
    return bitsize > 0;
}

string Bitset::asString()const{
    string value;
    for (size_t i = 0; i < bitsize; i++) {
        value += to_string(bit[i]);
    }
    return value;
}

void Bitset::toggle(intmax_t index) {
    if (index >= 0 && static_cast<size_t>(index) < bitsize) {
        bit[index] = 1 - bit[index];
    }
}

void Bitset::set(intmax_t index) {
    if (index >= 0 && static_cast<size_t>(index) < bitsize) {
        bit[index] = 1;
    }
}

void Bitset::reset(intmax_t index) {
    if (index >= 0 && static_cast<size_t>(index) < bitsize) {
        bit[index] = 0;
    }
}
