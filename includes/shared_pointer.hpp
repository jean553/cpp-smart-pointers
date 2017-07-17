/**
 * @brief shared_ptr example
 */

#include <memory>

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
