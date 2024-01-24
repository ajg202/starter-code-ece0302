#ifndef BITSET_HPP
#define BITSET_HPP
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

class Bitset{
public:

  // basic constructor, sets the size to 8, initializes array with that size, sets every value in the array to 0
  Bitset();

  // constructor with input, takes the input and uses it to set the size, initializes array with that size, sets every value in the array to 0
  Bitset(intmax_t size);

  // constructor with input, takes the input value and gets the size of it to set for the bit size, initializes array with that size, sets the values of the array to the value of the input
  Bitset(const std::string & value);

  // basic deconstructor
  ~Bitset();

  // other deconstructors
  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // returns the size the array is set to as an intmax_t
  intmax_t size() const;

  // first checks if the size of the array is greater than 0, next checks if each value in the array is either 1 or 0, if not then it returns false as a bool
  bool good() const;

  // gets an input, this input is the array value that is going to get set to 1, checks if the input is between 0 and the size of the array-1, if it is it sets that value in the array to 1
  void set(intmax_t index);

  // gets an input, this input is the array value that is going to get set to 0, checks if the input is between 0 and the size of the array-1, if it is it sets that value in the array to 0
  void reset(intmax_t index);

  // gets an input, this input is the array value that is going be toggled, checks if the input is between 0 and the size of the array-1, if it is it toggles the value in the array (1 goes to 0, 0 goes to 1)
  void toggle(intmax_t index);

  // gets an input, this input is the array value that will be checked if it is 1 or 0, if 1 it returns true, if 0 it returns false as a bool
  bool test(intmax_t index);

  // takes every value in the array and changes it to a string so it is the same as the array but as a string
  std::string asString() const;

private:
  //value used for the size of the array
  intmax_t bitsize;
  //value used for the array
  int *bit;
};

#endif
