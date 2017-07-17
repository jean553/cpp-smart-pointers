/**
 * @brief shared_ptr example
 */

#include "shared_pointer.hpp"

#include <iostream>

/**
 *
 */
std::shared_ptr<int> createSharedPointer(const int& value) {
    return std::make_shared<int>(value);
}

/**
 *
 */
void receiveSharedPointer(std::shared_ptr<int> pointer) {
    std::cout << *pointer << std::endl;
}
