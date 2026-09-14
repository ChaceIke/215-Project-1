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

    return 0;
}