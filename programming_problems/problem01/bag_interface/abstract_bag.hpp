#ifndef _ABSTRACT_BAG_HPP_
#define _ABSTRACT_BAG_HPP_

#include <cstdlib>

/**
 * @class AbstractBag
 * @brief represents the bag ADT
 */
template <typename T>class AbstractBag {
    public:
    /**
     * @brief Destructor
     */
    virtual ~AbstractBag() {}

    /**
     * @brief Gets the size of the bag
     * @return returns the size of the bag
     */
    virtual std::size_t getCurrentSize() const = 0;

    /**
     * @brief checks if the bag is empty
     * @return true if the bag is empty
     */
    virtual bool isEmpty() const = 0;

    /**
     * @brief adds an entry to the bag
     * @param entry gets the entry that needs to be added
     * @return returns true if the entry was added
     */
    virtual bool add(const T& entry) = 0;

    /**
     * @brief removes an entry from the bag.
     * @param entry gets the entry needed to be removed
     * @return retruns true is the entry was removed
     */
    virtual bool remove(const T& entry) = 0;

    /**
     * @brief clears all entries from the bag.
     */
    virtual void clear() = 0;

    /**
     * @brief gets the frequency of an entry in the bag
     * @param entry gets which entry to get frequency of
     * @return returns the frequency of the entry in the bag.
     */
    virtual std::size_t getFrequencyOf(const T& entry) const = 0;

    /**
     * @brief checks if the bag contains a certain entry
     * @param entry gets the entry to check for
     * @return retruns true if it has that entry
     */
    virtual bool contains(const T& entry) const = 0;
};

#endif
