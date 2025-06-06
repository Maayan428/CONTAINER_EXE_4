# 📦 Container Iterators Project in Modern C++

This project implements a generic `Container<T>` class along with **six custom iterators** that allow traversing its elements in various orders.  
It is written in modern **C++20** with full object-oriented design, extensive exception safety, and a modular architecture.

All components were thoroughly tested using the `doctest` framework and validated with **Valgrind** to ensure no memory leaks.

---

## 📁 Project Structure

- `main.cpp` – Demonstration of all iterator types with `int` and `std::string` containers.
- `tests/Test.cpp` – Comprehensive unit tests for the container and iterators.
- `headers/Container.hpp` – Main generic container class.
- `headers/Iterator.hpp` – General-purpose template iterator wrapper.
- `headers/Order.hpp` – Iterates in original insertion order.
- `headers/AscendingOrder.hpp` – Iterates from smallest to largest.
- `headers/DescendingOrder.hpp` – Iterates from largest to smallest.
- `headers/ReverseOrder.hpp` – Iterates in reverse insertion order.
- `headers/SideCrossOrder.hpp` – Alternates between smallest and largest.
- `headers/MiddleOutOrder.hpp` – Starts from middle, then alternates left/right outward.
- `Makefile` – Automates build, test, valgrind check, and cleanup.

---

## 🔄 Iterator Behaviors

Each iterator implements the same interface and supports:

- `begin()` / `end()` iteration
- `operator++`, `operator*`, `operator->`
- Range-based `for` support
- `std::out_of_range` exceptions on invalid dereference

| Iterator Type         | Traversal Pattern                                |
|-----------------------|--------------------------------------------------|
| `Order`               | [7, 15, 6, 1, 2]                                  |
| `AscendingOrder`      | [1, 2, 6, 7, 15]                                  |
| `DescendingOrder`     | [15, 7, 6, 2, 1]                                  |
| `ReverseOrder`        | [2, 1, 6, 15, 7]                                  |
| `SideCrossOrder`      | [1, 15, 2, 7, 6]                                  |
| `MiddleOutOrder`      | [6, 2, 7, 1, 15] (center, then outward)           |

---

## 🧪 Unit Testing

The project includes **44+ unit tests** for all iterators and the container, including:

- Correct iteration patterns
- Exception safety
- Edge cases (empty container, single element, duplicates)
- String and character support

Framework used: [`doctest`](https://github.com/doctest/doctest)

---

## ⚙️ Build & Run Instructions

```bash
make test        # Build and run all unit tests
make valgrind    # Check for memory leaks
make main        # Run example demonstration
make clean       # Remove compiled artifacts

💡 Make sure to have make, g++ (C++20), and optionally valgrind installed.

---

## 📝 Example Output

Here’s how the demonstration prints integer and string containers:

```bash
Integer Container: [7, 15, 6, 1, 2]
Insertion Order: 7 15 6 1 2
Ascending Order: 1 2 6 7 15
Descending Order: 15 7 6 2 1
Reverse Order: 2 1 6 15 7
Side Cross Order: 1 15 2 7 6
Middle Out Order: 6 2 7 1 15

String Container: [zebra, apple, monkey, banana, cat]
Insertion Order: zebra apple monkey banana cat
Ascending Order: apple banana cat monkey zebra
Descending Order: zebra monkey cat banana apple
Reverse Order: cat banana monkey apple zebra
Side Cross Order: apple zebra banana monkey cat
Middle Out Order: cat banana monkey apple zebra

---

## 👩‍💻 Author

**Maayan Turgeman**  
📧 maayan428@gmail.com  
🛠️ *C++20 | Containers | Iterators | Testing | Valgrind | OOP*

---