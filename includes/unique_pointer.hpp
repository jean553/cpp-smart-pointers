/**
 * @brief unique_ptr example
 */

#include <memory>

/**
 * @brief returns an unique pointer pointing to 10 if the given value is 10
 *
 * @param value used for the pointer construction
 *
 * @return std::unique_ptr<int>
 */
std::unique_ptr<int> createUniquePointer(const int& value);

/**
 * @brief displays the value pointed by the unique pointer
 *
 * @param pointer the concerned unique pointer
 */
void receiveUniquePointer(std::unique_ptr<int> pointer);
