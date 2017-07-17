#include <iostream>

#include "unique_pointer.hpp"

int main() {

    constexpr int FIRST_VALUE {10};
    auto firstUniquePointer = createUniquePointer(FIRST_VALUE);
    receiveUniquePointer(std::move(firstUniquePointer));

    constexpr int SECOND_VALUE {0};
    auto secondUniquePointer = createUniquePointer(SECOND_VALUE);
    receiveUniquePointer(std::move(secondUniquePointer));

    return EXIT_SUCCESS;
}
