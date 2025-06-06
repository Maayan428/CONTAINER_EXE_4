// maayan4282gmail.com

#ifndef MYCONTAINERS_REVERSE_ORDER_HPP
#define MYCONTAINERS_REVERSE_ORDER_HPP

#include "Container.hpp"
#include "Iterator.hpp"
#include <vector>
#include <algorithm>

namespace mycontainers {

/**
 * @brief An iterator that traverses the container in reverse insertion order.
 * 
 * For example, if the container contains [7, 15, 6, 1, 2],
 * this iterator will yield: 2, 1, 6, 15, 7.
 *
 * @tparam T The type of the container elements.
 */
template <typename T = int>
class ReverseOrder {

private:
    std::vector<T> reversedData; ///< Reversed copy of the container's data

public:
    /**
     * @brief Constructor that takes a reference to a container and copies its data in reverse.
     * 
     * @param c The container to iterate over in reverse order.
     */
    explicit ReverseOrder(const Container<T>& c) {
        const auto& data = c.getData();

        if (data.empty()) {
            return; // allow empty traversal (begin == end)
        }
        
        reversedData = data;
        std::reverse(reversedData.begin(), reversedData.end());
    }

    /**
     * @brief Returns an iterator to the beginning of the reversed container.
     * 
     * @return Iterator to the first element in reverse order.
     */
    Iterator<typename std::vector<T>::const_iterator> begin() const {
        return Iterator<typename std::vector<T>::const_iterator>(reversedData.begin(), reversedData.end());
    }

    /**
     * @brief Returns an iterator to the end of the reversed container.
     * 
     * @return Iterator past the last element in reverse order.
     */
    Iterator<typename std::vector<T>::const_iterator> end() const {
        return Iterator<typename std::vector<T>::const_iterator>(reversedData.end(), reversedData.end());
    }
};

} // namespace mycontainers

#endif // MYCONTAINERS_REVERSE_ORDER_HPP