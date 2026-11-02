# C++ Laboratory Works

A collection of C++ laboratory assignments for the **Fundamentals of Algorithmization and Programming** course (*Основы алгоритмизации и программирования*).

The programs cover basic calculations, operators, conditional statements, loops, functions, and arrays. Each laboratory work is a separate console application.

## Repository Structure

```text
3rd_lab/3rd_lab.cpp   # Lab 3: formulas and trip cost
4th_lab/4th_lab.cpp   # Lab 4: operators and expressions
5th_lab/5th_lab.cpp   # Lab 5: conditions and functions
6th_lab/6th_lab.cpp   # Lab 6: loops
7th_lab/7th_lab.cpp   # Lab 7: one-dimensional arrays
8th_lab/8th_lab.cpp   # Lab 8: two-dimensional arrays
README.md
```

## Laboratory Works

| Lab | Topic | What the program does |
| --- | --- | --- |
| **3** | Linear programs | Calculates an expression for the individual variant and estimates trip/fuel costs. |
| **4** | Operators and expressions | Extends the trip cost calculator and demonstrates `sizeof`, increment/decrement, ternary and compound assignment operators, and C++23 output. |
| **5** | Conditions and functions | Includes deposit interest, a simple bank account menu, animal shelter food expenses, and the function `f(x) = 3x + 2`. |
| **6** | Loops | Calculates sums and counts, Fibonacci numbers, a sum of positive odd values, and a function table. |
| **7** | One-dimensional arrays | Counts and sums array elements smaller than a user-entered value `B`. |
| **8** | Two-dimensional arrays | Calculates the sum of the main diagonal and transposes a 4×4 matrix. |

The assignments use **individual variant 28**. For Labs 7–8, the guide contains 16 variants, so variant 28 corresponds to task variant 12. The earlier assignments use the numbering applicable to their own guides.

## Requirements

- A C++ compiler such as `g++`.
- **C++23** support, including `std::print` / `std::println`, for Lab 4.
- **C++17** is sufficient for Labs 5–8.
- VS Code and WSL Debian are optional; any suitable C++ development environment can be used.

## Build and Run

Run these commands from the repository root.

For Lab 3:

```bash
g++ -std=c++17 3rd_lab/3rd_lab.cpp -o lab3
./lab3
```

For Lab 4 (requires C++23 support):

```bash
g++ -std=c++23 4th_lab/4th_lab.cpp -o lab4
./lab4
```

For Labs 5–8:

```bash
g++ -std=c++17 5th_lab/5th_lab.cpp -o lab5
./lab5

g++ -std=c++17 6th_lab/6th_lab.cpp -o lab6
./lab6

g++ -std=c++17 7th_lab/7th_lab.cpp -o lab7
./lab7

g++ -std=c++17 8th_lab/8th_lab.cpp -o lab8
./lab8
```

Each program runs independently and provides a console menu for its tasks.

## Notes

The source code is kept simple and readable for introductory C++ practice. Array values in Labs 7 and 8 are initialized directly in the code, as required by the assignment.
