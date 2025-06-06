// maayan4282gmail.com

#ifndef MYCONTAINERS_MIDDLE_OUT_ORDER_HPP
#define MYCONTAINERS_MIDDLE_OUT_ORDER_HPP

#include "Container.hpp"
#include "Iterator.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>

namespace mycontainers {

/**
 * @brief An iterator that traverses the container starting from the middle,
 * then alternates between left and right elements.
 *
 * For example, if the container contains [7, 15, 6, 1, 2],
 * this iterator will yield: 6, 15, 1, 7, 2.
 *
 * For even-sized containers, the middle is floor(size/2).
 *
 * @tparam T The type of the container elements.
 */
template <typename T = int>
class MiddleOutOrder {

private:
    std::vector<T> middleOutData; ///< Container's data reordered in middle-out order

public:
    /**
     * @brief Constructor that takes a reference to a container and
     *        reorders its data in middle-out order.
     *
     * @param c The container to iterate over.
     */
    explicit MiddleOutOrder(const Container<T>& c) {
        const auto& data = c.getData();
    
        if (data.empty()) {
            return; // allow empty traversal (begin == end)
        }
    
        std::vector<T> temp = data;    
        size_t n = temp.size();
        int mid=0;
        if (n%2==0) {
            mid = (n) / 2;} // Round UP for even n
        else{
            mid = (n-1) / 2;
        }
    
        middleOutData.push_back(temp[mid]);
    
        int offset = 1;
        while ((mid - offset) >= 0 || (mid + offset) < static_cast<int>(n)) {
            if ((mid - offset) >= 0) {
                middleOutData.push_back(temp[mid - offset]);
            }
            if ((mid + offset) < static_cast<int>(n)) {
                middleOutData.push_back(temp[mid + offset]);
            }
            ++offset;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Returns an iterator to the beginning of the MiddleOut-ordered container.
     */
    Iterator<typename std::vector<T>::const_iterator> begin() const {
        return Iterator<typename std::vector<T>::const_iterator>(
            middleOutData.begin(), middleOutData.end());
    }

    /**
     * @brief Returns an iterator to the end of the MiddleOut-ordered container.
     */
    Iterator<typename std::vector<T>::const_iterator> end() const {
        return Iterator<typename std::vector<T>::const_iterator>(
            middleOutData.end(), middleOutData.end());
    }
};

} // namespace mycontainers

#endif // MYCONTAINERS_MIDDLE_OUT_ORDER_HPP