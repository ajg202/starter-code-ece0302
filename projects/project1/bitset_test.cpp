#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include <iostream>
#include "bitset.hpp"

TEST_CASE( "Test bitset default construction", "[bitset]" ) {
    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE( "Test bitset construction with asString", "[bitset]" ) {
    Bitset b;
    REQUIRE(b.asString().compare("00000000") == 0);
}

TEST_CASE( "Test bitset construction size", "[bitset]" ) {
    Bitset b(64);
    std::string s(64, '0');
    REQUIRE(b.size() == 64);
    REQUIRE(b.good());
}

TEST_CASE( "Test bitset construction string", "[bitset]" ) {
    std::string s("00101110000011000001101000001");
    Bitset b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test bitset construction invalid string", "[bitset]" ) {
    std::string s("00101110000011002001101000001");
    Bitset b(s);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Test set", "[bitset]" ) {
    std::string s("00010001");
    Bitset b;
    b.set(3);
    b.set(7);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test set with size init", "[bitset]" ) {
    std::string s("00010");
    Bitset b(5);
    b.set(3);
    REQUIRE(b.size() == 5);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test combined", "[bitset]" ) {
    std::string s((1<<15) + 3, '0');
    Bitset b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);

    for (int i = 1; i < (1<<10); i++) {
        b.set(i);
        b.reset(i + (1<<10));
        b.toggle(i + (1<<11));
        REQUIRE(b.good());
        REQUIRE(b.test(i));
        REQUIRE_FALSE(b.test(i + (1<<10)));
        REQUIRE(((b.test(i + (1<<11)) == true && s.at(i + (1<<11)) == '0') || (b.test(i + (1<<11)) == false && s.at(i + (1<<11)) == '1')));
    }
}

//Extreme test cases
TEST_CASE( "Test negative size and test outside of range", "[Bitset]" ){
    Bitset a(-64);
    REQUIRE(a.size() == 0);
    REQUIRE_FALSE(a.test(4));
    REQUIRE_FALSE(a.good());
}

TEST_CASE( "Test test when it has anything besides 0 and 1", "[Bitset]" ){
    Bitset b("1201010");
    REQUIRE_FALSE(b.test(1));
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Test set outside of range", "[Bitset]" ){
    Bitset c("0012011010101");
    c.set(3);
    REQUIRE_FALSE(c.good());
}

TEST_CASE( "Test reset outside of range", "[Bitset]" ){
    Bitset d("0012011010101");
    d.reset(3);
    REQUIRE_FALSE(d.good());
}

TEST_CASE( "Test toggle outside of range", "[Bitset]" ){
    Bitset e("0012011010101");
    e.toggle(3);
    REQUIRE_FALSE(e.good());
}

TEST_CASE( "Test validity of set, reset, and toggle on normal conditions", "[Bitset]" ){
    Bitset f("0010011010101");
    f.set(2);
    f.set(3);
    f.reset(4);
    f.reset(5);
    f.toggle(6);
    f.toggle(7);
    REQUIRE(f.good());
    REQUIRE(f.asString().compare("0011000110101") == 0);
}