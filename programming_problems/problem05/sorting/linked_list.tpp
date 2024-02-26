#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), length(0)
{
  //TODO
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  //TODO
  clear();
  length = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  //TODO
  head = nullptr;
  length = 0;

  Node<T>* current = x.head;
  Node<T>* lastNode = nullptr;

  while (current != nullptr) {
    Node<T>* newNode = new Node<T>(current->getItem());

    if (lastNode == nullptr) {
      head = newNode;
    } 
    else {
      lastNode->setNext(newNode);
    }

    lastNode = newNode;
    current = current->getNext();
    length++;
  }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  //TODO
  swap(x);
  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  //TODO
  Node<T>* temp = head;
  head = x.head;
  x.head = temp;
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  //TODO
  return head == nullptr;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  //TODO
  std::size_t length = 0;
  Node<T>* current = head;
  while (current) {
    ++length;
    current = current->getNext();
  }
  return length;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  //TODO
  if (position > getLength()) {
      return false;
  }

  Node<T>* newNode = new Node<T>(item);

  if (position == 0) {
    newNode->setNext(head);
    head = newNode;
  } 
  else {
    Node<T>* current = head;
    for (std::size_t i = 0; i < position - 1; ++i) {
      current = current->getNext();
    }

    newNode->setNext(current->getNext());
    current->setNext(newNode);
  }

  length++;

  return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //TODO
  if (position >= getLength()) {
    return false;
  }

  if (position == 0) {
    Node<T>* temp = head;
    head = head->getNext();
    delete temp;
  } 
  else {
    Node<T>* current = head;
    for (std::size_t i = 0; i < position - 1; ++i) {
      current = current->getNext();
    }

    Node<T>* temp = current->getNext();
    current->setNext(current->getNext());
    delete temp;
  }

  length--;

  return true;
}

template <typename T>
void LinkedList<T>::clear()
{
  //TODO
  while (head != nullptr) {
    Node<T>* temp = head;
    head = head->getNext();
    delete temp;
  }
  length=0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //TODO
  if (position >= getLength()) {
    return T();
  }

  Node<T>* current = head;
  for (std::size_t i = 0; i < position; ++i) {
    current = current->getNext();
  }

  return current->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
//TODO
  if (position >= getLength()) {
    return;
  }

  Node<T>* current = head;
  for (std::size_t i = 0; i < position; ++i) {
    current = current->getNext();
  }

  current->setItem(newValue);
}
