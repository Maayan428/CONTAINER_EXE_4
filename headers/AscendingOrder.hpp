// maayan4282gmail.com

#ifndef MYCONTAINERS_ASCENDING_ORDER_HPP
#define MYCONTAINERS_ASCENDING_ORDER_HPP

#include "Container.hpp"
#include "Iterator.hpp"
#include <vector>
#include <algorithm>

namespace mycontainers {

/**
 * @brief An iterator that traverses the container in ascending order (smallest to largest).
 * 
 * For example, if the container contains [7, 15, 6, 1, 2],
 * this iterator will yield: 1, 2, 6, 7, 15.
 *
 * @tparam T The type of the container elements.
 */
template <typename T = int>
class AscendingOrder {

private:
    std::vector<T> sortedData; ///< A sorted copy of the container's data

public:
    using const_iterator = Iterator<typename std::vector<T>::const_iterator>;

    /**
     * @brief Constructor that takes a reference to a container and copies its data sorted.
     * 
     * @param c The container to traverse in ascending order.
     */
    explicit AscendingOrder(const Container<T>& c) {
        const auto& data = c.getData();

        if (data.empty()) {
            return; // allow empty traversal (begin == end)
        }
        
        sortedData = data;
        std::sort(sortedData.begin(), sortedData.end());
    }

    /**
     * @brief Returns an iterator to the beginning of the sorted container.
     */
    const_iterator begin() const {
        return const_iterator(sortedData.begin(), sortedData.end());
    }

    /**
     * @brief Returns an iterator to the end of the sorted container.
     */
    const_iterator end() const {
        return const_iterator(sortedData.end(), sortedData.end());
    }
};

} // namespace mycontainers

#endif // MYCONTAINERS_ASCENDING_ORDER_HPP
