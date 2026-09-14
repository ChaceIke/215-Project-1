// Temp File for testing ABag class functionality
#include <iostream>
#include "ABag.h"

int main() {
    ABag<int> bag; // Create an instance of ABag for integers

    // Add items to the bag
    for (int i = 0; i < 10; ++i) {
        if (bag.addItem(i)) {
            std::cout << "Added item: " << i << std::endl;
        } else {
            std::cout << "Failed to add item: " << i << " (Bag is full)" << std::endl;
        }
    }

    // Inspect the top item
    int topItem;
    if (bag.inspectTop(topItem)) {
        std::cout << "The top item in the bag is: " << topItem << std::endl;
    } else {
        std::cout << "The bag is empty." << std::endl;
    };

    // Remove the top item
    int topItemRemoved;
    if (bag.removeTop(topItemRemoved)) {
        std::cout << "Removed item: " << topItemRemoved << std::endl;
    } else {
        std::cout << "Failed to remove item: " << topItemRemoved << std::endl;
    }

    //Remove a specific item
    int itemToRemove = 5;
    if (bag.removeItem(itemToRemove)) {
        std::cout << "Removed item: " << itemToRemove << std::endl;
    } else {
        std::cout << "Failed to remove item: " << itemToRemove << std::endl;
    }
};