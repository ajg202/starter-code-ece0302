#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() : bagSize(0), items(nullptr){}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T>& x) : bagSize(x.bagSize),items(nullptr){
  if (bagSize > 0) {
    items = new T[bagSize];
    for (int i = 0; i < bagSize; ++i) {
      items[i] = x.items[i];
    }
  }
}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  delete[] items;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{  
  swap(x);
  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){
  std::swap(bagSize, x.bagSize);
  std::swap(items, x.items);
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  T* tempItems = new T[bagSize + 1];

  if (tempItems == nullptr) {
    return false;
  }

  for (int i = 0; i < bagSize; ++i) {
    tempItems[i] = items[i];
  }

  tempItems[bagSize] = item;

  delete[] items;
  items = tempItems;
  ++bagSize;

  return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  int foundIndex = -1;

  for (int i = 0; i < bagSize; ++i) {
    if (items[i] == item) {
      foundIndex = i;
      break;
    }
  }

  if (foundIndex == -1) {
    return false;
  }

  T* tempItems = new T[bagSize - 1];

  for (int i = 0, j = 0; i < bagSize; ++i) {
    if (i != foundIndex) {
      tempItems[j++] = items[i];
    }
  }

  delete[] items;
  items = tempItems;
  --bagSize;

  return true;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return bagSize == 0;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return bagSize;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  for (int i = 0; i < bagSize; ++i) {
    if (items[i] == item) {
      return true;
    }
  }
  return false;
}

template<typename T>
void DynamicBag<T>::clear(){
  delete[] items;
  items = nullptr;
  bagSize = 0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t frequency = 0;

  for (int i = 0; i < bagSize; ++i) {
    if (items[i] == item) {
      ++frequency;
    }
  }

  return frequency;
};
