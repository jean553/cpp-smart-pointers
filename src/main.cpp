#include <iostream>

#include "unique_pointer.hpp"
#include "shared_pointer.hpp"

void customDeleter(int* pointer) {
    delete pointer;
    std::cout << "other pointer deleted !" << std::endl;
}

int main() {

    /* simple unique pointers */

    constexpr int FIRST_VALUE {10};
    auto firstUniquePointer = createUniquePointer(FIRST_VALUE);
    receiveUniquePointer(std::move(firstUniquePointer));

    constexpr int SECOND_VALUE {0};
    auto secondUniquePointer = createUniquePointer(SECOND_VALUE);
    receiveUniquePointer(std::move(secondUniquePointer));

    /* unique pointers with custom deleters */

    auto deleter = [](int* pointer) {
        delete pointer;
        std::cout << "pointer deleted !" << std::endl;
    };

    std::unique_ptr<int, decltype(deleter)> pointer(new int(10), deleter);
    std::cout << *pointer << std::endl;

    std::unique_ptr<int, void (*)(int*)> otherPointer(new int(100), customDeleter);
    std::cout << *otherPointer << std::endl;

    /* shared pointer */

    constexpr int FIRST_SHARED_PTR_VALUE {50};
    auto firstSharedPtr = createSharedPointer(FIRST_SHARED_PTR_VALUE);
    receiveSharedPointer(firstSharedPtr);

    /* shared pointer on `this` */

    auto pointerToObject = std::make_shared<Example>();
    pointerToObject->set();

    /* weak pointer */

    auto firstPtr = std::make_shared<Example>(); // shared_ptr
    std::weak_ptr<Example> secondPtr(firstPtr);

    if (not secondPtr.expired()) {
        auto thirdPtr = secondPtr.lock(); // shared_ptr
    }

    return EXIT_SUCCESS;
}
