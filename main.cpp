#include "headers/Container.hpp"
#include "headers/Order.hpp"
#include <iostream>
#include <string>

using namespace mycontainers;

int main() {
    Container<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    Order<int> ord(c);
    std::cout << "Order Iterator over ints: ";
    for (auto val : ord) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Test with strings
    Container<std::string> strContainer;
    strContainer.add("apple");
    strContainer.add("banana");
    strContainer.add("cherry");

    Order<std::string> strOrder(strContainer);
    std::cout << "Order Iterator over strings: ";
    for (const auto& s : strOrder) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}