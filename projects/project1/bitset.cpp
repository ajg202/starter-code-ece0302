#include "bitset.hpp"

Bitset::Bitset() {
    // TODO
}

Bitset::Bitset(intmax_t size) {
    // TODO
}

Bitset::Bitset(const std::string & value) {
    // TODO
}

Bitset::~Bitset() {
    // TODO
}

// TODO: other methods

Bitset::bool test(intmax_t index){
    if (index<=0){
        return 0;
    }
}

Bitset::string asString(){
    string result;
    for (size_t i = 0; i < bitsize; i++) {
        result += to_string(bit[i]);
    }
    return result;
}