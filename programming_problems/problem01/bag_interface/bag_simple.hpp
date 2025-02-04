#ifndef STUDENT_BAG_HPP
#define STUDENT_BAG_HPP

#include "abstract_bag.hpp"

template<typename T>
class Bag : public AbstractBag<T> {
public:

  Bag();
  
  ~Bag();

  std::size_t getCurrentSize() const override;

  bool isEmpty() const override;

  bool add(const T& entry) override;

  bool remove(const T& entry) override;

  void clear() override;

  std::size_t getFrequencyOf(const T& entry) const override;

  bool contains(const T& entry) const override;

  static const std::size_t MAXSIZE = 100;
  
private:
  // implementation using fixed automatic storage
  std::size_t size;
  T data[MAXSIZE];
};

#include "bag_simple.tpp"

#endif
