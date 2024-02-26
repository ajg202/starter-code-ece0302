#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test adding a non-allowable word", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}

TEST_CASE("test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(!b.add("AA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("test add invalid", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(!b.add("a_"));
	REQUIRE(b.add("AA"));
	REQUIRE(!b.add("Aa2A"));
	REQUIRE(!b.add("AA"));
	REQUIRE(b.number() == 2);
}

TEST_CASE("test recursion3", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("kayaaa"));
	//REQUIRE(!b.add("kayaaa"));
	//REQUIRE(b.number() == 2);
}

TEST_CASE("test add vector", "[FindPalindrome]"){
	FindPalindrome b;

	std::vector<std::string> strings = {"hello", "world", "level"};
	REQUIRE(b.add(strings));
	std::vector<std::string> strings2 = {"level", "two", "purple"};
	REQUIRE(!b.add(strings2));
	std::vector<std::string> strings3 = {"LEAR_N", "one", "yes"};
	REQUIRE(!b.add(strings3));
	std::vector<std::string> strings4 = {"H2O", "place", "TON"};
	REQUIRE(!b.add(strings4));
}

TEST_CASE("test racecar,recur", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("race"));
	REQUIRE(b.add("car"));
	REQUIRE(b.number() == 2);
}

TEST_CASE("test zero", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.number() == 0);
	REQUIRE(b.add("race"));
	REQUIRE(b.add("car"));
	b.clear();
	REQUIRE(b.number() == 0);
}

/*TEST_CASE("test string vector", "[FindPalindrome]"){
	FindPalindrome b;

	std::vector<std::string> strings = {"sit","on","a","potato","otis"};
	REQUIRE(b.number() == 1);
}*/

TEST_CASE("test cuttest1", "[FindPalindrome]"){
	FindPalindrome b;

	std::vector<std::string> strings = {"level"};
	REQUIRE(b.cutTest1(strings));
	std::vector<std::string> strings1 = {"ooonnne"};
	REQUIRE(!b.cutTest1(strings1));
}

TEST_CASE("test cuttest2", "[FindPalindrome]"){
	FindPalindrome b;

	std::vector<std::string> strings1 = {"race"};
	std::vector<std::string> strings2 = {"car"};
	REQUIRE(b.cutTest2(strings1,strings2));
	std::vector<std::string> strings3 = {"river"};
	std::vector<std::string> strings4 = {"ten"};
	REQUIRE(!b.cutTest2(strings3,strings4));
}
