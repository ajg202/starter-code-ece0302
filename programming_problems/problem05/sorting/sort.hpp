#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"

template<typename T> LinkedList<T> sort(LinkedList<T> list)
{
	// your code should go here.
    std::size_t size = list.getLength();

    if (size < 2) {
        return list;
    }

    for (std::size_t i = 0; i < size - 1; ++i) {
        for (std::size_t j = 0; j < size - i - 1; ++j) {
            if (list.getEntry(j) > list.getEntry(j + 1)) {
                T temp = list.getEntry(j);
                list.setEntry(j, list.getEntry(j + 1));
                list.setEntry(j + 1, temp);
            }
        }
    }

    return list;
}

#endif
