#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

// Force class expansion
template class ArrayList<int>;

TEST_CASE("Test", "[ArrayList]") {
    ArrayList<int> list;

    REQUIRE(list.getLength() == 0);
    REQUIRE(list.isEmpty() == true);

    ArrayList<int> list2(list);

    REQUIRE(list2.getLength() == 0);
    REQUIRE(list2.isEmpty() == true);

    list2.insert(2, 3);
    REQUIRE(list2.getLength() == 1);
    REQUIRE(list2.getEntry(0) == 3);

    list2.remove(5);
    REQUIRE(list2.getLength() == 1);

    REQUIRE(list2.getEntry(8) == 0);

    list2.setEntry(6, 8);
    REQUIRE(list2.getLength() == 1);
    REQUIRE(list2.getEntry(6) == 0);

    list2.clear();
    REQUIRE(list2.isEmpty() == true);
}

TEST_CASE("Extreme Tests1", "[ArrayList]") {
    ArrayList<int> list;

    REQUIRE(list.getLength() == 0);
    REQUIRE(list.isEmpty() == true);

    ArrayList<int> list2(list);

    REQUIRE(list2.getLength() == 0);
    REQUIRE(list2.isEmpty() == true);

    list2.insert(-2, 3);
    REQUIRE(list2.getLength() == 0);

    list2.remove(5);
    REQUIRE(list2.getLength() == 0);

    REQUIRE(list2.getEntry(8) == 0);

    list2.setEntry(-6, 8);
    REQUIRE(list2.getLength() == 0);

    list2.clear();
    REQUIRE(list2.isEmpty() == true);
}

TEST_CASE("Extreme Tests2", "[ArrayList]") {
    ArrayList<int> list;

    REQUIRE(list.getLength() == 0);
    REQUIRE(list.isEmpty() == true);

    ArrayList<int> list2(list);

    REQUIRE(list2.getLength() == 0);
    REQUIRE(list2.isEmpty() == true);

    list2.insert(2000, 3);
    REQUIRE(list2.getLength() == 0);

    list2.remove(-5);
    REQUIRE(list2.getLength() == 0);

    REQUIRE(list2.getEntry(-8) == 0);

    list2.setEntry(60000, 8);
    REQUIRE(list2.getLength() == 0);

    list2.clear();
    REQUIRE(list2.isEmpty() == true);
}
