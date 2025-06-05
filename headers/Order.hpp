#ifndef MYCONTAINERS_ORDER_HPP
#define MYCONTAINERS_ORDER_HPP

#include "Container.hpp"
#include "Iterator.hpp" // שימוש באיטרטור הכללי

#include <vector>

namespace mycontainers {

/**
 * @brief An iterator that traverses the container in insertion order (left to right).
 * 
 * For example, if the container contains [7, 15, 6, 1, 2],
 * this iterator will yield: 7, 15, 6, 1, 2.
 * 
 * @tparam T The type of the container elements.
 */
template <typename T = int>

class Order {
    
private:
    const Container<T>& container; ///< Reference to the container being iterated

public:
    using const_iterator = Iterator<typename std::vector<T>::const_iterator>;

    /**
     * @brief Constructor that receives a reference to the container.
     * 
     * @param c The container to iterate over.
     */
    explicit Order(const Container<T>& c) : container(c) {}

    /**
     * @brief Returns an iterator to the beginning of the container.
     */
    const_iterator begin() const {
        return const_iterator(container.getData().begin(), container.getData().end());
    }

    /**
     * @brief Returns an iterator to the end of the container.
     */
    const_iterator end() const {
        return const_iterator(container.getData().end(), container.getData().end());
    }
};

} // namespace mycontainers

#endif // MYCONTAINERS_ORDER_HPP