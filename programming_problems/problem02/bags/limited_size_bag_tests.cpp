#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);

}

TEST_CASE("Different Numbers", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(10);
  b.add(20);
  b.getFrequencyOf(20);
  b.remove(20);
  b.isEmpty();
  b.getCurrentSize();
  b.getFrequencyOf(10);
  b.clear();
  b.getCurrentSize();;
  b.contains(0);
}

TEST_CASE("Negative Numbers", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(-10);
  b.add(0);
  b.add(10);
  b.add(-20);
  b.getFrequencyOf(-10);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.getFrequencyOf(0);
  b.clear();
  b.getCurrentSize();;
  b.contains(-10);
}

TEST_CASE("Over Numbers", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(1000);
  b.add(0);
  b.add(10);
  b.add(-300);
  b.getFrequencyOf(1000);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.getFrequencyOf(0);
  b.clear();
  b.getCurrentSize();;
  b.contains(-300);
}