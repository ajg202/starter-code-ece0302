#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() : arrSize(0), arr(nullptr) {}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] arr;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs) : arrSize(rhs.arrSize), arr(new T[arrSize]) {
    for (size_t i = 0; i < arrSize; ++i) {
        arr[i] = rhs.arr[i];
    }
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs) {
    swap(rhs);
    return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList& rhs) {
    std::swap(arr, rhs.arr);
    std::swap(arrSize, rhs.arrSize);
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept {
    return arrSize == 0;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept {
    return arrSize;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item) {
    if (position < 0 || position > arrSize) {
        return false;
    }

    T* arrCopy = new T[arrSize + 1];
    
    for (std::size_t i = 0, j = 0; i < arrSize + 1; ++i) {
        if (i == position) {
            arrCopy[i] = item;
        } else {
            arrCopy[i] = arr[j++];
        }
    }

    delete[] arr;
    arr = arrCopy;
    ++arrSize;

    return true;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position) {
    if (position >= arrSize || position < 0) {
        return false;
    }

    T* arrCopy = new T[arrSize - 1];

    for (std::size_t i = 0, j = 0; i < arrSize - 1; ++i) {
        if (i == position) {
            ++j;
        } else {
            arrCopy[i] = arr[j++];
        }
    }

    delete[] arr;
    arr = arrCopy;
    --arrSize;

    return true;
}

template <typename T>
void ArrayList<T>::clear() {
    delete[] arr;
    arr = nullptr;
    arrSize = 0;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
    if (position > 0 || position <= arrSize) {
        return arr[position];
    } else {
        return T();
    }
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
    if (position >= 0 && position < arrSize) {
        arr[position] = newValue;
    }
}
