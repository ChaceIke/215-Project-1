#pragma once

#include "bagADT.h"
#include <memory> // for std::unique_ptr

template <class E>
class Abag : public Bag<E> {
private:
    std::unique_ptr<E[]> items; // unique pointer to dynamically allocated array
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