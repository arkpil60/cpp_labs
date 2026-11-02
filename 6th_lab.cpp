#include <cmath>
#include <iomanip>
#include <iostream>

void task1() {
    int number{};
    int sum = 0;
    int count = 0;

    std::cout << "\nTask 1: Sum and count\n"
              << "Enter positive integers (0 to finish):\n";

    while (true) {
        if (!(std::cin >> number)) {
            std::cout << "Invalid input.\n";
            return;
        }

        if (number == 0) {
            break;
        }

        if (number < 0) {
            std::cout << "Please enter a positive integer or 0 to finish.\n";
            continue;
        }

        sum += number;
        ++count;
    }

    std::cout << "Sum: " << sum << '\n'
              << "Count: " << count << '\n';
}

void task2() {
    int n{};

    std::cout << "\nTask 2: Fibonacci number\n"
              << "Enter n (0-46): ";

    if (!(std::cin >> n) || n < 0 || n > 46) {
        std::cout << "Please enter an integer from 0 to 46.\n";
        return;
    }

    if (n == 0) {
        std::cout << "F(0) = 0\n";
        return;
    }
    if (n == 1) {
        std::cout << "F(1) = 1\n";
        return;
    }

    int previous = 0;
    int current = 1;

    for (int i = 2; i <= n; ++i) {
        const int next = previous + current;
        previous = current;
        current = next;
    }

    std::cout << "F(" << n << ") = " << current << '\n';
}

void task3() {
    int number{};
    int totalCount = 0;
    int nonPositiveSum = 0;

    std::cout << "\nTask 3: Non-positive numbers\n"
              << "Enter integers (input stops at the first negative number):\n";

    while (true) {
        if (!(std::cin >> number)) {
            std::cout << "Invalid input.\n";
            return;
        }

        ++totalCount;

        if (number <= 0) {
            nonPositiveSum += number;
        }

        if (number < 0) {
            break;
        }
    }

    std::cout << "Sum of non-positive numbers: " << nonPositiveSum << '\n'
              << "Total numbers entered: " << totalCount << '\n';
}

void task4() {
    int number{};
    int oddPositiveSum = 0;

    std::cout << "\nTask 4: Positive odd numbers\n"
              << "Enter five integers:\n";

    for (int i = 0; i < 5; ++i) {
        if (!(std::cin >> number)) {
            std::cout << "Invalid input.\n";
            return;
        }

        if (number <= 0) {
            continue;
        }

        if (number % 2 == 0) {
            continue;
        }

        oddPositiveSum += number;
    }

    std::cout << "Sum of positive odd numbers: " << oddPositiveSum << '\n';
}

void task5() {
    constexpr double a = 2.0;
    constexpr double b = 40.0;
    double x = a;
    double result{};

    std::cout << "\nTask 5: Function table\n"
              << "Given a = 2, b = 40, step = 2\n\n"
              << std::setw(8) << "x"
              << std::setw(12) << "F(x)" << '\n';

    std::cout << std::fixed;
    while (x <= b) {
        if (x < std::abs(a - b)) {
            result = (a + 4.0 * b - x) / x;
        } else if (x > std::abs(a - b)) {
            result = (x * a - x * b) / x;
        } else {
            result = (2.0 * x - a - b) / (x - 10.0);
        }

        std::cout << std::setw(8) << std::setprecision(0) << x
                  << std::setw(12) << std::setprecision(2) << result << '\n';
        x += 2.0;
    }
}

int main() {
    int choice{};

    std::cout << "Laboratory Work No. 6: Loops\n"
              << "1 - Sum and count positive integers\n"
              << "2 - Fibonacci number\n"
              << "3 - Sum non-positive numbers until a negative number\n"
              << "4 - Sum five positive odd integers\n"
              << "5 - Print a function table\n"
              << "Choose a task (1-5): ";

    if (!(std::cin >> choice)) {
        std::cout << "Invalid input. Enter a number from 1 to 5.\n";
        return 1;
    }

    switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        default:
            std::cout << "Unknown task. Choose a number from 1 to 5.\n";
            return 1;
    }

    return 0;
}
