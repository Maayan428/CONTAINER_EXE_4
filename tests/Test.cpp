#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"
#include "../headers/Container.hpp"
#include "../headers/Order.hpp"
#include "../headers/AscendingOrder.hpp"
#include "../headers/DescendingOrder.hpp"
#include "../headers/ReverseOrder.hpp"
#include "../headers/SideCrossOrder.hpp"
#include "../headers/MiddleOutOrder.hpp"


using namespace mycontainers;

// ------------------ Container Tests ------------------

TEST_CASE("Adding elements to Container") {
    Container<int> c;
    CHECK(c.size() == 0);
    c.add(10);
    c.add(20);
    c.add(30);
    CHECK(c.size() == 3);
}

TEST_CASE("Removing existing element from Container") {
    Container<int> c;
    c.add(1);
    c.add(2);
    c.add(2);
    c.add(3);
    CHECK(c.size() == 4);
    c.remove(2);
    CHECK(c.size() == 2);
    CHECK_THROWS(c.remove(2));
}

TEST_CASE("Removing non-existent element throws") {
    Container<int> c;
    c.add(1);
    CHECK_THROWS_AS(c.remove(99), std::runtime_error);
}

TEST_CASE("Removing from empty container throws") {
    Container<int> c;
    CHECK(c.size() == 0);
    CHECK_THROWS(c.remove(1));
}

TEST_CASE("Output stream operator prints correctly") {
    Container<int> c;
    c.add(5);
    c.add(10);
    c.add(15);

    std::ostringstream oss;
    oss << c;
    CHECK(oss.str() == "[5, 10, 15]");
}

TEST_CASE("Using Container with strings") {
    Container<std::string> c;
    c.add("hello");
    c.add("world");
    CHECK(c.size() == 2);
    CHECK_NOTHROW(c.remove("hello"));
    CHECK(c.size() == 1);
    CHECK_THROWS(c.remove("not_there"));
}

TEST_CASE("Copy constructor and assignment operator") {
    Container<int> original;
    original.add(1);
    original.add(2);

    Container<int> copy = original;
    CHECK(copy.size() == 2);
    CHECK_NOTHROW(copy.remove(1));

    Container<int> assigned;
    assigned = original;
    CHECK(assigned.size() == 2);
    CHECK_NOTHROW(assigned.remove(2));
}

// ------------------ Order Tests ------------------

TEST_CASE("Order iteration yields elements in insertion order") {
    Container<int> c;
    c.add(7);
    c.add(15);
    c.add(6);

    Order<int> o(c);
    auto it = o.begin();

    CHECK(*it == 7);
    ++it;
    CHECK(*it == 15);
    ++it;
    CHECK(*it == 6);
    ++it;
    CHECK(it == o.end());
}

TEST_CASE("Dereferencing end iterator throws") {
    Container<int> c;
    c.add(1);
    Order<int> o(c);
    auto it = o.end();

    CHECK_THROWS_AS(*it, std::out_of_range);
    CHECK_THROWS_AS(it.operator->(), std::out_of_range);
}

TEST_CASE("Iterator handles empty container correctly") {
    Container<int> c;
    Order<int> o(c);
    CHECK(o.begin() == o.end());
}

TEST_CASE("Iterator advances correctly through the container") {
    Container<int> c;
    c.add(100);
    c.add(200);
    c.add(300);

    Order<int> o(c);
    auto it = o.begin();
    int expected[] = {100, 200, 300};
    int index = 0;

    for (; it != o.end(); ++it, ++index) {
        CHECK(*it == expected[index]);
    }
    CHECK(index == 3);
}

TEST_CASE("Iterator comparisons and end behavior") {
    Container<int> c;
    c.add(100);
    c.add(200);
    c.add(300);

    Order<int> order(c);

    auto it1 = order.begin();  
    auto it2 = order.begin();  

    CHECK(it1 == it2);

    auto it = order.begin();
    int lastValue = 0;

    while (it != order.end()) {
        lastValue = *it;
        ++it;
    }

    CHECK(it == order.end());
    CHECK(lastValue == 300); 
}

// ------------------ AscendingOrder Tests ------------------


TEST_CASE("AscendingOrder iterates correctly on sorted integers") {
    Container<int> c;
    c.add(1);
    c.add(2);
    c.add(3);
    AscendingOrder<int> ao(c);

    std::vector<int> expected = {1, 2, 3};
    auto it = ao.begin();
    for (int val : expected) {
        CHECK(it != ao.end());
        CHECK(*it == val);
        ++it;
    }
    CHECK(it == ao.end());
}

TEST_CASE("AscendingOrder iterates correctly on unsorted integers") {
    Container<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);
    AscendingOrder<int> ao(c);

    std::vector<int> expected = {1, 2, 6, 7, 15};
    auto it = ao.begin();
    for (int val : expected) {
        CHECK(it != ao.end());
        CHECK(*it == val);
        ++it;
    }
    CHECK(it == ao.end());
}

TEST_CASE("AscendingOrder throws on dereferencing end iterator") {
    Container<int> c;
    c.add(5);
    AscendingOrder<int> ao(c);
    auto it = ao.begin();
    ++it;
    CHECK_THROWS_AS(*it, std::out_of_range);
    CHECK_THROWS_AS(it.operator->(), std::out_of_range);
}

TEST_CASE("AscendingOrder with empty container") {
    Container<int> c;
    AscendingOrder<int> ao(c);
    auto it = ao.begin();
    CHECK(it == ao.end());
    CHECK_THROWS_AS(*it, std::out_of_range);
}

TEST_CASE("AscendingOrder with duplicates") {
    Container<int> c;
    c.add(4);
    c.add(1);
    c.add(4);
    c.add(3);
    AscendingOrder<int> ao(c);

    std::vector<int> expected = {1, 3, 4, 4};
    auto it = ao.begin();
    for (int val : expected) {
        CHECK(it != ao.end());
        CHECK(*it == val);
        ++it;
    }
    CHECK(it == ao.end());
}

TEST_CASE("AscendingOrder equality and inequality operators") {
    Container<int> c;
    c.add(2);
    c.add(9);
    AscendingOrder<int> ao(c);

    auto it1 = ao.begin();
    auto it2 = ao.begin();
    auto it3 = ao.end();

    CHECK(it1 == it2);
    ++it2;
    CHECK(it1 != it2);
    ++it2;
    CHECK(it2 == it3);
}

// ------------------ DescendingOrder Tests ------------------

TEST_CASE("DescendingOrder - basic iteration") {
    Container<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    DescendingOrder<int> desc(c);

    std::vector<int> expected = {15, 7, 6, 2, 1};
    auto it = desc.begin();
    for (int val : expected) {
        CHECK(it != desc.end());
        CHECK(*it == val);
        ++it;
    }
    CHECK(it == desc.end());
}

TEST_CASE("DescendingOrder - empty container") {
    Container<int> c;
    DescendingOrder<int> desc(c);
    auto it = desc.begin();
    CHECK(it == desc.end());
    CHECK_THROWS_AS(*it, std::out_of_range);
}

TEST_CASE("DescendingOrder - single element") {
    Container<int> c;
    c.add(42);

    DescendingOrder<int> desc(c);
    auto it = desc.begin();
    CHECK(*it == 42);
    ++it;
    CHECK(it == desc.end());
}

TEST_CASE("DescendingOrder - duplicate values") {
    Container<int> c;
    c.add(5);
    c.add(3);
    c.add(5);
    c.add(2);

    DescendingOrder<int> desc(c);
    std::vector<int> expected = {5, 5, 3, 2};
    auto it = desc.begin();
    for (int val : expected) {
        CHECK(it != desc.end());
        CHECK(*it == val);
        ++it;
    }
    CHECK(it == desc.end());
}

TEST_CASE("DescendingOrder - iterator comparison and exceptions") {
    Container<int> c;
    c.add(10);
    c.add(20);

    DescendingOrder<int> desc(c);
    auto it1 = desc.begin();
    auto it2 = desc.begin();
    CHECK(it1 == it2);

    ++it2;
    CHECK(it1 != it2);

    // advance to end
    ++it2;
    CHECK(it2 == desc.end());

    CHECK_THROWS_AS(*it2, std::out_of_range);
    CHECK_THROWS_AS(it2.operator*(), std::out_of_range);
}

// ------------------ Container Tests ------------------

TEST_CASE("ReverseOrder iterates in reverse of insertion order") {
    Container<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    ReverseOrder<int> rev(c);
    std::vector<int> expected = {2, 1, 6, 15, 7};
    size_t index = 0;
    for (auto it = rev.begin(); it != rev.end(); ++it) {
        CHECK(*it == expected[index++]);
    }
    CHECK(index == expected.size());
}

TEST_CASE("ReverseOrder supports string container") {
    Container<std::string> c;
    c.add("first");
    c.add("second");
    c.add("third");

    ReverseOrder<std::string> rev(c);
    std::vector<std::string> expected = {"third", "second", "first"};
    size_t index = 0;
    for (auto it = rev.begin(); it != rev.end(); ++it) {
        CHECK(*it == expected[index++]);
    }
    CHECK(index == expected.size());
}

TEST_CASE("ReverseOrder throws on dereferencing end iterator") {
    Container<int> c;
    c.add(1);
    c.add(2);

    ReverseOrder<int> rev(c);
    auto it = rev.end();
    CHECK_THROWS_AS(*it, std::out_of_range);
    CHECK_THROWS_AS(it.operator*(), std::out_of_range);
}

TEST_CASE("ReverseOrder empty container yields begin == end") {
    Container<int> c;
    ReverseOrder<int> rev(c);
    CHECK(rev.begin() == rev.end());
}

TEST_CASE("ReverseOrder iterator comparison and traversal") {
    Container<int> c;
    c.add(5);
    c.add(10);
    c.add(15);

    ReverseOrder<int> rev(c);
    auto it1 = rev.begin();
    auto it2 = rev.begin();

    CHECK(it1 == it2);
    ++it2;
    CHECK(it1 != it2);

    int count = 0;
    for (auto it = rev.begin(); it != rev.end(); ++it) {
        ++count;
    }
    CHECK(count == c.size());
}

// ------------------ Container Tests ------------------

TEST_CASE("SideCrossOrder basic iteration") {
    Container<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    SideCrossOrder<int> sco(c);
    std::vector<int> result;
    for (int val : sco) {
        result.push_back(val);
    }

    CHECK(result == std::vector<int>{1, 15, 2, 7, 6});
}

TEST_CASE("SideCrossOrder iteration with even number of elements") {
    Container<int> c;
    c.add(8);
    c.add(3);
    c.add(10);
    c.add(1);

    // sorted: [1, 3, 8, 10]
    // expected side-cross: 1, 10, 3, 8

    SideCrossOrder<int> sco(c);
    std::vector<int> result;
    for (int val : sco) {
        result.push_back(val);
    }

    CHECK(result == std::vector<int>{1, 10, 3, 8});
}

TEST_CASE("SideCrossOrder with one element") {
    Container<int> c;
    c.add(42);

    SideCrossOrder<int> sco(c);
    auto it = sco.begin();
    CHECK(*it == 42);
    ++it;
    CHECK(it == sco.end());
}

TEST_CASE("SideCrossOrder with two elements") {
    Container<int> c;
    c.add(100);
    c.add(50);

    SideCrossOrder<int> sco(c);
    std::vector<int> result;
    for (int val : sco) {
        result.push_back(val);
    }

    CHECK(result == std::vector<int>{50, 100});
}

TEST_CASE("SideCrossOrder empty container") {
    Container<int> c;
    SideCrossOrder<int> sco(c);
    CHECK(sco.begin() == sco.end());
}

TEST_CASE("SideCrossOrder throws on dereferencing end()") {
    Container<int> c;
    c.add(1);
    SideCrossOrder<int> sco(c);
    auto it = sco.end();
    CHECK_THROWS_AS(*it, std::out_of_range);
    CHECK_THROWS_AS(it.operator*(), std::out_of_range);
}

TEST_CASE("SideCrossOrder with characters") {
    Container<char> c;
    c.add('d');
    c.add('a');
    c.add('e');
    c.add('b');
    c.add('c');

    // sorted: ['a', 'b', 'c', 'd', 'e']
    // expected side-cross: a, e, b, d, c

    SideCrossOrder<char> sco(c);
    std::vector<char> result;
    for (char ch : sco) {
        result.push_back(ch);
    }

    CHECK(result == std::vector<char>{'a', 'e', 'b', 'd', 'c'});
}

TEST_CASE("SideCrossOrder with strings") {
    Container<std::string> c;
    c.add("zebra");
    c.add("apple");
    c.add("monkey");
    c.add("banana");
    c.add("cat");

    // sorted: ["apple", "banana", "cat", "monkey", "zebra"]
    // expected side-cross: apple, zebra, banana, monkey, cat

    SideCrossOrder<std::string> sco(c);
    std::vector<std::string> result;
    for (const auto& s : sco) {
        result.push_back(s);
    }

    CHECK(result == std::vector<std::string>{"apple", "zebra", "banana", "monkey", "cat"});
}

TEST_CASE("SideCrossOrder empty container should not crash") {
    Container<int> c;
    SideCrossOrder<int> sco(c);

    auto it = sco.begin();
    auto end = sco.end();
    CHECK(it == end);  // Must be empty
}

// ------------------ Container Tests ------------------

TEST_CASE("MiddleOutOrder iteration with odd number of integers") {
    Container<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    MiddleOutOrder<int> moo(c);
    std::vector<int> result;
    for (int val : moo) {
        result.push_back(val);
    }
}

TEST_CASE("MiddleOutOrder iteration with even number of integers") {
    Container<int> c;
    c.add(10);
    c.add(20);
    c.add(30);
    c.add(40);

    MiddleOutOrder<int> moo(c);
    std::vector<int> result;
    
    for (int val : moo) {
        std::cout << val << ", "; 
        result.push_back(val);
    }
    std::cout << std::endl;

    CHECK(result == std::vector<int>{30, 20, 40, 10});
}

TEST_CASE("MiddleOutOrder iteration with characters") {
    Container<char> c;
    c.add('a');
    c.add('b');
    c.add('c');
    c.add('d');
    c.add('e');

    MiddleOutOrder<char> moo(c);
    std::vector<char> result;
    for (char val : moo) {
        std::cout << val << " ";  // הדפסת כל ערך

        result.push_back(val);
    }
    std::cout << std::endl;


    CHECK(result == std::vector<char>{'c', 'b', 'd', 'a', 'e'});
}

TEST_CASE("MiddleOutOrder iteration with strings") {
    Container<std::string> c;
    c.add("apple");
    c.add("banana");
    c.add("cherry");
    c.add("date");
    c.add("fig");
    c.add("grape");

    MiddleOutOrder<std::string> moo(c);
    std::vector<std::string> result;
    for (const std::string& val : moo) {
        std::cout << val << " ";  // הדפסת כל ערך

        result.push_back(val);
    }
    std::cout << std::endl;


    CHECK(result == std::vector<std::string>{"date", "cherry", "fig", "apple", "grape", "banana"});
}

TEST_CASE("MiddleOutOrder empty container") {
    Container<int> c;
    MiddleOutOrder<int> moo(c);
    auto it = moo.begin();
    auto end = moo.end();
    CHECK(it == end); // Should not crash
}

TEST_CASE("MiddleOutOrder with single element") {
    Container<int> c;
    c.add(42);

    MiddleOutOrder<int> moo(c);
    std::vector<int> result;
    for (int val : moo) {
        result.push_back(val);
    }

    CHECK(result == std::vector<int>{42});
}

TEST_CASE("MiddleOutOrder with duplicate elements") {
    Container<int> c;
    c.add(3);
    c.add(1);
    c.add(3);
    c.add(1);
    c.add(2);

    MiddleOutOrder<int> moo(c);
    std::vector<int> result;
    for (int val : moo) {
        std::cout << val << " ";  // הדפסת כל ערך

        result.push_back(val);
    }
    std::cout << std::endl;


    CHECK(result == std::vector<int>{3, 1, 1, 3, 2});
}