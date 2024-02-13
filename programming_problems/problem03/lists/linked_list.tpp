#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), itemCount(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
  clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x) : head(nullptr), itemCount(0) {
    Node<T>* xCurrent = x.head;
    while (xCurrent != nullptr) {
        insert(itemCount, xCurrent->getItem());
        xCurrent = xCurrent->getNext();
    }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x) {
    swap(x);
    return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList& x) {
  std::swap(head, x.head);
  std::swap(itemCount, x.itemCount);
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept {
    return itemCount == 0;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept {
    return itemCount;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item) {
    if (position > itemCount) {
        return false;
    }

    Node<T>* newNode = new Node<T>(item);
    if (position == 0) {
        newNode->setNext(head);
        head = newNode;
    } else {
        Node<T>* previous = getNodeAt(position - 1);
        newNode->setNext(previous->getNext());
        previous->setNext(newNode);
    }

    ++itemCount;
    return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position) {
    if (position >= itemCount || isEmpty()) {
        return false;
    }

    Node<T>* current = head;
    if (position == 0) {
        head = head->getNext();
    } else {
        Node<T>* previous = getNodeAt(position - 1);
        current = previous->getNext();
        previous->setNext(current->getNext());
    }

    delete current;
    current = nullptr;

    --itemCount;
    return true;
}

template <typename T>
void LinkedList<T>::clear() {
    while (!isEmpty()) {
        remove(0);
    }
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const {
  if (position >= itemCount || position < 0) {
    return T();
  }

  Node<T>* nodePtr = getNodeAt(position);
  return nodePtr->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue) {
    if (position < itemCount) {
        Node<T>* nodePtr = getNodeAt(position);
        nodePtr->setItem(newValue);
    }
}

template <typename T>
Node<T>* LinkedList<T>::getNodeAt(std::size_t position) const {
    Node<T>* current = head;
    for (std::size_t i = 0; i < position; ++i) {
        current = current->getNext();
    }
    return current;
}
