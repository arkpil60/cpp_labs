# C++ Laboratory Works

A collection of C++ programming assignments completed as part of the *Fundamentals of Algorithmization and Programming* course. The projects focus on basic calculations, user input, expressions, operators, and formatted console output.

## Repository Structure

- `first.cpp` — Laboratory Work No. 3: an interactive program with a mathematical formula calculator and a fuel/trip cost calculator.
- `4th_lab.cpp` — Laboratory Work No. 4: an updated trip cost calculator demonstrating additional C++ operators and C++23 formatted output.
- `.gitignore` — excludes compiled binaries and other generated files from version control.

> If your source files use different names, update the filenames in this section to match the repository.

## Laboratory Work No. 3 — Linear Programs

- **Individual task (Variant 28):** calculates a mathematical expression using functions from `<cmath>`. According to the cyclic numbering rule, Variant 28 corresponds to Variant 13 in the methodical guide.
- **Trip cost calculator:** asks the user for the trip distance, fuel consumption, fuel price, and additional costs, then calculates the estimated fuel required and total trip cost.

## Laboratory Work No. 4 — Operators and Expressions

This assignment extends the trip cost calculator from Laboratory Work No. 3 and demonstrates:

- `++` and `--` increment and decrement operators;
- `sizeof` for checking the sizes of `int`, `double`, `bool`, and `char`;
- the ternary operator (`?:`) for selecting a currency label;
- compound assignment operators such as `+=` and `*=`;
- C++23 formatted output with `std::print` and `std::println`;
- comments explaining the added operators and changes.

## Requirements

- A C++23-compatible compiler and standard library.
- `g++` (recent version recommended for `std::print` and `std::println`).
- Linux, WSL Debian, or another environment with a C++ compiler.

## Build and Run

Compile Laboratory Work No. 3:

```bash
g++ -std=c++23 -Wall -Wextra -Wpedantic first.cpp -o lab3
./lab3
```

Compile Laboratory Work No. 4:

```bash
g++ -std=c++23 -Wall -Wextra -Wpedantic 4th_lab.cpp -o lab4
./lab4
```

Run the commands from the directory containing the source files. If `std::print` or `std::println` is not available, install or select a newer compiler and standard library with C++23 support.

## Development Environment

The programs are intended to be edited in Visual Studio Code and compiled in a Debian environment through Windows Subsystem for Linux (WSL).

## License

This repository is intended for educational and portfolio purposes.