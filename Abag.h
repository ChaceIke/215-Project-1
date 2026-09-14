#pragma once

#include "bagADT.h"
#include <memory> // for std::unique_ptr

template <class E>
class ABag : public Bag<E> { // ABag class inherits from Bag<E>
private:
    std::unique_ptr<E[]> items; // unique pointer to dynamically allocated array. Satisfies the requirement of using a smart pointer for memory management.
    int capacity;               // maximum number of items the bag can hold
    int itemCount;              // current number of items in the bag

public:
    ABag(); // Constructor

    bool addItem(const E& item) override;
    bool removeItem(E& item) override;
    bool removeTop(E& returnValue) override;
    bool find(E& returnValue) const override;
    bool inspectTop(E& item) const override;
    void emptyBag() override;
    bool operator+=(const E& item) override;
    int numItems() const override;
    int bagCapacity() const override;

};

// Constructor implementation for ABag class
template <class E>
ABag<E>::ABag() : capacity(10), itemCount(0) {
    items = std::make_unique<E[]>(capacity); // allocate memory for the array using unique_ptr
};

// addItem implementation for ABag class
template <class E>
bool ABag<E>::addItem(const E& item) {
    if (itemCount >= capacity) {
        return false; // Bag is full
    };

    items[itemCount++] = item; // Add item and increment count
    return true;
};

template <class E>
bool ABag<E>::removeItem(E& item) {
    return false; // Stub implementation
};

// Everything below is a stub implementation for now.
template <class E>
bool ABag<E>::removeTop(E& returnValue) {
    return false; // Stub implementation
};

template <class E>
bool ABag<E>::find(E& returnValue) const {
    return false; // Stub implementation
};

template <class E>
bool ABag<E>::inspectTop(E& item) const {
    if (itemCount == 0) {
        return false; // Bag is empty
    }
    item = items[itemCount - 1]; // Get the last item addded
    return true;
};

template <class E>
void ABag<E>::emptyBag() {
    itemCount = 0; // Reset item count to zero
};

template <class E>
bool ABag<E>::operator+=(const E& item) {
    return addItem(item); // Use addItem functionality for operator+=
};

template <class E>
int ABag<E>::numItems() const {
    return itemCount; // Return the current number of items in the bag
};

template <class E>
int ABag<E>::bagCapacity() const {
    return capacity; // Return the maximum capacity of the bag
};