// maayan4282gmail.com

#ifndef MYCONTAINERS_SIDECROSS_ORDER_HPP
#define MYCONTAINERS_SIDECROSS_ORDER_HPP

#include "Container.hpp"
#include "Iterator.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace mycontainers {

/**
 * @brief An iterator that traverses the container in SideCross order:
 * smallest, largest, second smallest, second largest, etc.
 *
 * For example, if the container contains [7, 15, 6, 1, 2],
 * this iterator will yield: 1, 15, 2, 7, 6.
 *
 * @tparam T The type of the container elements.
 */
template <typename T = int>
class SideCrossOrder {

private:
    std::vector<T> sideCrossData; ///< The container's data reordered in SideCross order.

public:
    /**
     * @brief Constructor that takes a reference to a container and
     *        reorders its data in SideCross order.
     * 
     * @param c The container to iterate over.
     */
    explicit SideCrossOrder(const Container<T>& c) {
        const auto& data = c.getData();
        std::vector<T> sorted = data;
        std::sort(sorted.begin(), sorted.end());

        // Guard: do nothing if empty
        if (sorted.empty()) return;

        // Reorder: smallest, largest, second smallest, second largest, etc.
        size_t left = 0;
        size_t right = sorted.size() - 1;
        bool pickLeft = true;
        while (left <= right) {
            if (pickLeft) {
                sideCrossData.push_back(sorted[left++]);
            } else {
                sideCrossData.push_back(sorted[right--]);
            }
            pickLeft = !pickLeft;
        }
    }
    
    /**
     * @brief Returns an iterator to the beginning of the SideCross-ordered container.
     */
    Iterator<typename std::vector<T>::const_iterator> begin() const {
        return Iterator<typename std::vector<T>::const_iterator>(
            sideCrossData.begin(), sideCrossData.end());
    }

    /**
     * @brief Returns an iterator to the end of the SideCross-ordered container.
     */
    Iterator<typename std::vector<T>::const_iterator> end() const {
        return Iterator<typename std::vector<T>::const_iterator>(
            sideCrossData.end(), sideCrossData.end());
    }
};

} // namespace mycontainers

#endif // MYCONTAINERS_SIDECROSS_ORDER_HPP