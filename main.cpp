// maayan4282gmail.com

#include <iostream>
#include "headers/Container.hpp"
#include "headers/Order.hpp"
#include "headers/AscendingOrder.hpp"
#include "headers/DescendingOrder.hpp"
#include "headers/ReverseOrder.hpp"
#include "headers/SideCrossOrder.hpp"
#include "headers/MiddleOutOrder.hpp"

using namespace mycontainers;

int main() {
    // ----------------- INT EXAMPLE -----------------
    Container<int> intContainer;
    intContainer.add(7);
    intContainer.add(15);
    intContainer.add(6);
    intContainer.add(1);
    intContainer.add(2);

    std::cout << "Integer Container: " << intContainer << std::endl;

    std::cout << "Insertion Order: ";
    Order<int> orderIt(intContainer);
    for (auto it = orderIt.begin(); it != orderIt.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Ascending Order: ";
    AscendingOrder<int> asc(intContainer);
    for (auto it = asc.begin(); it != asc.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Descending Order: ";
    DescendingOrder<int> desc(intContainer);
    for (auto it = desc.begin(); it != desc.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Reverse Order: ";
    ReverseOrder<int> rev(intContainer);
    for (auto it = rev.begin(); it != rev.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Side Cross Order: ";
    SideCrossOrder<int> sco(intContainer);
    for (auto it = sco.begin(); it != sco.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Middle Out Order: ";
    MiddleOutOrder<int> moo(intContainer);
    for (auto it = moo.begin(); it != moo.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl << std::endl;

    // ----------------- STRING EXAMPLE -----------------
    Container<std::string> strContainer;
    strContainer.add("zebra");
    strContainer.add("apple");
    strContainer.add("monkey");
    strContainer.add("banana");
    strContainer.add("cat");

    std::cout << "String Container: " << strContainer << std::endl;

    std::cout << "Insertion Order: ";
    Order<std::string> orderStr(strContainer);
    for (auto it = orderStr.begin(); it != orderStr.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Ascending Order: ";
    AscendingOrder<std::string> ascStr(strContainer);
    for (auto it = ascStr.begin(); it != ascStr.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Descending Order: ";
    DescendingOrder<std::string> descStr(strContainer);
    for (auto it = descStr.begin(); it != descStr.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Reverse Order: ";
    ReverseOrder<std::string> revStr(strContainer);
    for (auto it = revStr.begin(); it != revStr.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Side Cross Order: ";
    SideCrossOrder<std::string> scoStr(strContainer);
    for (auto it = scoStr.begin(); it != scoStr.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Middle Out Order: ";
    MiddleOutOrder<std::string> mooStr(strContainer);
    for (auto it = mooStr.begin(); it != mooStr.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    return 0;
}