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

    // Attempt to add one more item to test capacity limit
    if (!bag.addItem(10)) {
        std::cout << "Failed to add item: 10 (Bag is full)" << std::endl;
    }

    return 0;
}