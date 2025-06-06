// maayan4282gmail.com

#ifndef MYCONTAINERS_DESCENDING_ORDER_HPP
#define MYCONTAINERS_DESCENDING_ORDER_HPP

#include "Container.hpp"
#include "Iterator.hpp"
#include <vector>
#include <algorithm>

namespace mycontainers {

/**
 * @brief An iterator that traverses the container in descending order (largest to smallest).
 * 
 * For example, if the container contains [7, 15, 6, 1, 2],
 * this iterator will yield: 15, 7, 6, 2, 1.
 * 
 * @tparam T The type of the container elements.
 */
template <typename T = int>
class DescendingOrder {

private:
    std::vector<T> sortedData; ///< A sorted copy of the container's data, in descending order.

public:
    using const_iterator = Iterator<typename std::vector<T>::const_iterator>;

    /**
     * @brief Constructor that takes a reference to a container and copies its data sorted in descending order.
     * 
     * @param c The container to traverse in descending order.
     */
    explicit DescendingOrder(const Container<T>& c) {
        const auto& data = c.getData();
        
        if (data.empty()) {
            return; // allow empty traversal (begin == end)
        }
        
        sortedData = data;
        std::sort(sortedData.begin(), sortedData.end(), std::greater<T>());
    }

    /**
     * @brief Returns an iterator to the beginning of the sorted (descending) container.
     */
    const_iterator begin() const {
        return const_iterator(sortedData.begin(), sortedData.end());
    }

    /**
     * @brief Returns an iterator to the end of the sorted (descending) container.
     */
    const_iterator end() const {
        return const_iterator(sortedData.end(), sortedData.end());
    }
};

} // namespace mycontainers

#endif // MYCONTAINERS_DESCENDING_ORDER_HPP
