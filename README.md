# cpp-smart-pointers

Smart pointers usage examples.

## Run examples

Compilation:

```bash
mkdir build && cd build/
cmake ..
make
```

Run:

```bash
./bin/cpp-smart-pointers
```

## Unique pointers

Unique pointers must be the priority when using pointers.
They are as small as raw pointers.
They cannot be copied, they can only be moved.
By using unique pointers, we have the guarantee that only
one pointer points at a time to a given resource.

```cpp
/**
 * @brief creates an unique pointer with the given integer
 *
 * @param data the value of the pointer's pointed data
 *
 * @return std::unique_ptr<int>
 */
std::unique_ptr<int> createUniquePointer(const int& data) {
    return std::make_unique<int>(data);
}

/**
 * @brief takes an unique pointer and displays its pointed resource value
 *
 * @param pointer the given pointer
 */
void receiveUniquePointer(std::unique_ptr<int> pointer) {
    std::cout << *pointer << std::endl;
}

auto pointer = createUniquePointer(10);
receiveUniquePointer(std::move(pointer));
```

## Unique pointers with custom deleters

It is possible to specify what happens when an unique pointer is deleted.
To do so, we have to use custom deleters. A custom deleter can be a function
or a lambda function.

```cpp
void customDeleter(int* pointer) {
    delete pointer;
    std::cout << "other pointer deleted !" << std::endl;
}

auto deleter = [](int* pointer) {
    delete pointer;
    std::cout << "pointer deleted !" << std::endl;
};

std::unique_ptr<int, decltype(deleter)> pointer(new int(10), deleter);
std::cout << *pointer << std::endl;

std::unique_ptr<int, void (*)(int*)> otherPointer(new int(100), customDeleter);
std::cout << *otherPointer << std::endl;
```
