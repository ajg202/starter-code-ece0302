#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() : bagSize(0) , items(new T[maxsize]){}

template<typename T>
bool LimitedSizeBag<T>::add(const T& item) {
  if (bagSize < maxsize) {
    items[bagSize++] = item;
    return true;
  }
  return false;
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item) {
  for (std::size_t i = 0; i < bagSize; ++i) {
    if (items[i] == item) {
      for (std::size_t j = i; j < bagSize - 1; ++j) {
        items[j] = items[j + 1];
      }
      --bagSize;
      return true;
    }
  }
  return false;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const {
  return bagSize == 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const {
  return bagSize;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const {
  for (std::size_t i = 0; i < bagSize; ++i) {
    if (items[i] == item) {
      return true;
    }
  }
    return false;
}

template<typename T>
void LimitedSizeBag<T>::clear() {
  bagSize = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T& item) const {
  std::size_t frequency = 0;
  for (std::size_t i = 0; i < bagSize; ++i) {
    if (items[i] == item) {
      ++frequency;
    }
  }
  return frequency;
}
