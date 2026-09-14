#pragma once

#include "bagADT.h"
#include <memory> // for std::unique_ptr

template <class E>
class Abag : public Bag<E> { // Abag class inherits from Bag<E>
private:
    std::unique_ptr<E[]> items; // unique pointer to dynamically allocated array. Satisfies the requirement of using a smart pointer for memory management.
    int capacity;               // maximum number of items the bag can hold
    int itemCount;              // current number of items in the bag

public:
    Abag()

    bool addItem(const E& item) override;
    bool removeItem(E& item) override;
    bool removeTop(E& returnValue) override;
    bool find(E& returnValue) const override;
    bool inspectTop(E& item) const override;
    void emptyBag() override;
    bool operator+=(const E& item);
    int numItems() const override;
    int bagCapacity() const override;

};

// Constructor implementation for Abag class
template <class E>
Abag<E>::Abag() : capacity(10), itemCount(0) {
    items = std::make_unique<E[]>(capacity); // allocate memory for the array using unique_ptr
}

// addItem implementation for Abag class
template <class E>
bool Abag<E>::addItem(const E& item) {
    if (itemCount >= capacity) {
        return false; // Bag is full
    }
    items[itemCount++] = item; // Add item and increment count
    return true;
};