#pragma once

#include "dictionaryADT.h"
#include "kvpair.h"
#include "ABag.h"

template <class Key, class Value>
class BDictionary : public Dictionary<Key, Value> {
    private:
        ABag<KVpair<Key, Value>> bag; // Use Abag to store key value pairs
    public:
        BDictionary() = default;
        BDictionary(int size) : bag() {} // Initialize the bag with a default size

        void clear() override {
            bag.emptyBag(); // Clear the bag
        }

        bool insert(const Key& k, const Value& e) override {
            KVpair<Key, Value> newPair(k, e); // Create a new key value pair
            return bag.addItem(newPair); // Add the new pair to the bag
        }

        bool remove(const Key& k, Value& returnValue) override {
            KVpair<Key, Value> tempPair(k, Value()); // Create a temporary key value pair
            if (bag.removeItem(tempPair)) {
                returnValue = tempPair.value(); // Update returnValue with the value from the removed pair
                return true; // Successfully removed
            }
            return false;
        }

        bool removeAny(Value& returnValue) override {
            KVpair<Key, Value> tempPair; // Create a temporary key value pair
            if (bag.removeTop(tempPair)) {
                returnValue = tempPair.value(); // Update returnValue with the value from the removed pair
                return true; // Successfully removed
            }
            return false; // Bag is empty
        }

        bool search(const Key& k, Value& returnValue) const override {
            KVpair<Key, Value> tempPair(k, Value()); // Create a temporary key value pair
            if (bag.find(tempPair)) {
                returnValue = tempPair.value(); // Update returnValue with the value from the found pair
                return true; // Successfully found
            }
            return false; // Not found
        }

        int size() const override {
            return bag.numItems(); // Return the number of items in the bag
        }
};