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

// The removeItem method will use the bag data structure property of last in first out to find and then remove the item from the bag.
template <class E>
bool ABag<E>::removeItem(E& item) {
    for (int i = itemCount - 1; i >= 0; --i) {
        if (items[i] == item) {
            item = items[i]; // Update the item with the found item
            items[i] = items[itemCount - 1];
            --itemCount; // Decrement itemCount
            return true; // Item found and removed. Unique_ptr automatically manages memory, so no need to delete.
        }
    }
    return false; // Item not found
};

template <class E>
bool ABag<E>::removeTop(E& returnValue) {
    if (itemCount == 0) {
        return false; // Bag is empty
    }
    returnValue = items[--itemCount]; // Decrement itemCount and return the last item added
    return true;
};

// This is a bag data structure, so the find method will begin its search from the last item added and work its way to the first item added.
template <class E>
bool ABag<E>::find(E& returnValue) const {
    for (int i = itemCount - 1; i >= 0; --i) {
        if (items[i] == returnValue) {
            returnValue = items[i]; // Update the returnValue with the found item
            return true; // Item found
        }
    }
    return false; // Item not found
};

template <class E>
bool ABag<E>::inspectTop(E& item) const {
    if (itemCount == 0) {
        return false; // Bag is empty
    }
    item = items[itemCount - 1]; // Get the last item added
    return true;
};

template <class E>
void ABag<E>::emptyBag() {
    itemCount = 0; // Reset item count to zero. No need to delete items as unique_ptr will handle memory management automatically.
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