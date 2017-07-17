/**
 * @brief shared_ptr example
 */

#include <memory>

/**
 * @brief creates a shared pointer
 *
 * @param value the value pointed by the pointer
 *
 * @return std::shared_ptr<int>
 */
std::shared_ptr<int> createSharedPointer(const int& value);

/**
 * @brief receives a shared pointer
 *
 * @param pointer the concerned pointer
 */
void receiveSharedPointer(std::shared_ptr<int> pointer);
