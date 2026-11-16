# C++ Laboratory Works

C++ assignments for **Fundamentals of Algorithmization and Programming** (*Основы алгоритмизации и программирования*).

Laboratory works **1–2** were completed as handwritten flowcharts and have no C++ source files in this repository.

## Files

| File | Laboratory work | Contents |
| --- | --- | --- |
| `3rdLab.cpp` | 3 — Linear programs | Mathematical expression and a trip cost calculator. |
| `4thLab.cpp` | 4 — Operators | Extends the trip cost calculator using C++23, `sizeof`, `++`, `--`, `?:`, compound assignments, and `std::print` / `std::println`. |
| `5thLab.cpp` | 5 — Conditional statements | Bank deposit, bank account, animal shelter, and a piecewise function. |
| `6thLab.cpp` | 6 — Loops | `do...while`, Fibonacci numbers, filtered sums, and function tables using `while` and `for`. |
| `7thLab.cpp` | 7 — One-dimensional arrays | Count and sum elements smaller than a given value. |
| `8thLab.cpp` | 8 — Two-dimensional arrays | Sum the main diagonal and transpose a 4×4 matrix. |

The source files are stored directly in the repository root.

## Build and run

Requires a C++ compiler. Laboratory 4 needs C++23 with `<print>` support. The other source files use C++17.

Run from the repository root:

```bash
g++ -std=c++17 3rdLab.cpp -o main && ./main
g++ -std=c++23 4thLab.cpp -o main && ./main
g++ -std=c++17 5thLab.cpp -o main && ./main
g++ -std=c++17 6thLab.cpp -o main && ./main
g++ -std=c++17 7thLab.cpp -o main && ./main
g++ -std=c++17 8thLab.cpp -o main && ./main
```

Each command compiles and runs one laboratory work. The next command overwrites `main`.

## Notes

- Arrays in laboratory works 7–8 are initialized directly in the code, as required by the guide.
- The currency choice in laboratory 4 changes only the displayed currency label; it does not convert exchange rates.