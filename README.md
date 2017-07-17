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

## Shared pointers

Shared pointers are pointers that can point to the same resource.
They also point to a `control block` containing the custom deleter,
the references counter... etc...

Only one control block should exist per resource, as long as at least
one shared pointer points to it.

According how the shared pointer is created, it will create a control block or not.

When the shared pointer is copied, the references counter is incremented;
the references counter is not incremented when the shared pointer is moved.

```cpp
constexpr int FIRST_SHARED_PTR_VALUE {50};
auto firstSharedPtr = createSharedPointer(FIRST_SHARED_PTR_VALUE);
receiveSharedPointer(firstSharedPtr);
```

## Shared pointers with `std::enable_shared_from_this`

```cpp
class Example : public std::enable_shared_from_this<Example> {

public:

    /**
     * @brief sets the pointer to point to the current object
     */
    void set();

private:

    std::shared_ptr<Example> pointer {nullptr};
};

/**
 *
 */
void Example::set() {

    pointer = shared_from_this();
}

auto pointerToObject = std::make_shared<Example>();
pointerToObject->set();
```

## Weak pointers

`std::weak_ptr` can be dangling pointers.
They are used with shared pointers.
It is not possible to dereference a weak pointer.

They are used with cache systems and with entities that point to each other.

It is possible to check if a weak pointer is dangling through `expired()` method.
It is possible to create a shared pointer from a weak pointer using `lock()`.

```cpp
auto firstPtr = std::make_shared<Example>(); // shared_ptr
std::weak_ptr<Example> secondPtr(firstPtr);

if (not secondPtr.expired()) {
    auto thirdPtr = secondPtr.lock(); // shared_ptr
}
```
