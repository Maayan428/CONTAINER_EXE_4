// maayan4282gmail.com

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>
#include <stdexcept>

namespace mycontainers {

template <typename Iter>

class Iterator {
    
private:
    Iter it;
    Iter endIt;

public:
    using iterator_category = std::forward_iterator_tag;
    using value_type        = typename Iter::value_type;
    using difference_type   = std::ptrdiff_t;
    using pointer           = const value_type*;
    using reference         = const value_type&;

    Iterator(Iter current, Iter end) : it(current), endIt(end) {}

    reference operator*() const {
        if (it == endIt) throw std::out_of_range("Cannot dereference end iterator.");
        return *it;
    }

    pointer operator->() const {
        if (it == endIt) throw std::out_of_range("Cannot access member of end iterator.");
        return &(*it);
    }

    Iterator& operator++() {
        ++it;
        return *this;
    }

    Iterator operator++(int) {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const Iterator& other) const { return it == other.it; }
    bool operator!=(const Iterator& other) const { return it != other.it; }
};

} // namespace mycontainers

#endif