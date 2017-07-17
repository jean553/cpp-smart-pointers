/**
 * @brief unique_ptr example
 */

#include "unique_pointer.hpp"

#include <iostream>

/**
 *
 */
std::unique_ptr<int> createUniquePointer(const int& value) {

    switch(value)
    {
    case 10:
    {
        return std::make_unique<int>(value);
    }
    default:
    {
        return std::make_unique<int>(0);
    }
    }
}

/**
 *
 */
void receiveUniquePointer(std::unique_ptr<int> pointer) {

    std::cout << *pointer << std::endl;
}
