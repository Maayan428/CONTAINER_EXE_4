#ifndef MYCONTAINERS_CONTAINER_HPP
#define MYCONTAINERS_CONTAINER_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

namespace mycontainers {

/**
 * @brief A generic container class that stores comparable elements.
 * 
 * The container supports adding, removing, and accessing the size of its elements.
 * It also supports printing via the output stream operator.
 * 
 * @tparam T The type of elements stored in the container. Must support comparison and stream output.
 */
template <typename T = int>

class Container {

private:
    std::vector<T> data; ///< Internal dynamic array to store elements

public:

    /** @brief Default constructor. Initializes an empty container. */
    Container() = default;

    /**
     * @brief Copy constructor.
     * 
     * Creates a new container by copying another container.
     * 
     * @param other The container to copy from.
     */
    Container(const Container& other) : data(other.data) {}

    /**
     * @brief Copy assignment operator.
     * 
     * Assigns the contents of another container to this one.
     * 
     * @param other The container to assign from.
     * @return Container& Reference to this container.
     */
    Container& operator=(const Container& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    /**
     * @brief Destructor.
     * 
     * Automatically cleans up the internal vector.
     */
    ~Container() = default;

    /**
     * @brief Adds a new element to the container.
     * 
     * @param value The element to add.
     */
    void add(const T& value) {
        data.push_back(value);
    }

    /**
     * @brief Removes all occurrences of the given element from the container.
     * 
     * If the element is not found, an exception is thrown.
     * 
     * @param value The element to remove.
     * @throws std::runtime_error if the element is not found.
     */
    void remove(const T& value) {
        auto originalSize = data.size();
        data.erase(std::remove(data.begin(), data.end(), value), data.end());
        if (data.size() == originalSize) {
            throw std::runtime_error("Element not found in container.");
        }
    }

    /**
     * @brief Returns the number of elements in the container.
     * 
     * @return size_t The number of elements.
     */
    size_t size() const {
        return data.size();
    }

    /**
     * @brief Returns a const reference to the internal data vector.
     * 
     * This is useful for passing the data to iterators.
     * 
     * @return const std::vector<T>&
     */
    const std::vector<T>& getData() const {
        return data;
    }

    /**
     * @brief Overloads the stream output operator to print the container.
     * 
     * @param os Output stream.
     * @param c The container to print.
     * @return std::ostream& Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Container<T>& c) {
        os << "[";
        for (size_t i = 0; i < c.data.size(); ++i) {
            os << c.data[i];
            if (i < c.data.size() - 1) os << ", ";
        }
        os << "]";
        return os;
    }
};

} // namespace mycontainers

#endif // MYCONTAINERS_CONTAINER_HPP