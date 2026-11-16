#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

void task1() {
    int number{};
    int sum = 0;
    int count = 0;

    std::cout << "\nTask 1: Sum and count positive integers\n"
              << "Enter positive integers (0 to finish):\n";

    // do...while reads at least one number.
    do {
        if (!(std::cin >> number)) {
            std::cout << "Invalid input.\n";
            return;
        }
        if (number < 0) {
            std::cout << "Enter a positive integer or 0.\n";
            continue;
        }
        if (number != 0) {
            sum += number;
            ++count;
        }
    } while (number != 0);

    std::cout << "Sum: " << sum << '\n'
              << "Count: " << count << '\n';
}

// Add two non-negative integers represented as decimal strings.
// This allows exact Fibonacci numbers up to F(10000) without integer overflow.
std::string addNumbers(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    const std::size_t length = std::max(a.size(), b.size());

    for (std::size_t i = 0; i < length || carry != 0; ++i) {
        int digit = carry;
        if (i < a.size()) digit += a[a.size() - 1 - i] - '0';
        if (i < b.size()) digit += b[b.size() - 1 - i] - '0';
        result += static_cast<char>('0' + digit % 10);
        carry = digit / 10;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

void task2() {
    int n{};
    std::cout << "\nTask 2: Fibonacci number\nEnter n (0-10000): ";
    if (!(std::cin >> n) || n < 0 || n > 10000) {
        std::cout << "Enter an integer from 0 to 10000.\n";
        return;
    }

    std::string previous = "0";
    std::string current = "1";
    for (int i = 0; i < n; ++i) {
        const std::string next = addNumbers(previous, current);
        previous = current;
        current = next;
    }
    std::cout << "F(" << n << ") = " << previous << '\n';
}

void task3() {
    int number{};
    int totalCount = 0;
    int nonPositiveSum = 0;

    std::cout << "\nTask 3: Sum non-positive numbers\n"
              << "Enter integers (the first negative number stops input):\n";
    while (true) {
        if (!(std::cin >> number)) {
            std::cout << "Invalid input.\n";
            return;
        }
        ++totalCount;
        if (number <= 0) nonPositiveSum += number;
        if (number < 0) break;
    }

    std::cout << "Sum of non-positive numbers: " << nonPositiveSum << '\n'
              << "Total numbers entered: " << totalCount << '\n';
}

void task4() {
    int number{};
    int oddPositiveSum = 0;
    std::cout << "\nTask 4: Sum of positive odd numbers\nEnter five integers:\n";
    for (int i = 0; i < 5; ++i) {
        if (!(std::cin >> number)) {
            std::cout << "Invalid input.\n";
            return;
        }
        if (number <= 0) continue;
        if (number % 2 == 0) continue;
        oddPositiveSum += number;
    }
    std::cout << "Sum of positive odd numbers: " << oddPositiveSum << '\n';
}

// Task 5. Assuming variant 28 cycles through 25 variants: 28 -> 3.
// Variant 3: F(k) = m^2 + k^3 if k < 3, otherwise sin(k) + m.
double calculateF(double k) {
    constexpr double m = 4.0;
    if (k < 3.0) return m * m + k * k * k;
    return std::sin(k) + m;
}

void printTableHeader() {
    // Replace this placeholder with your real surname before submitting.
    std::cout << "Surname: YOUR_SURNAME\n";
    std::cout << std::setw(10) << "k" << std::setw(14) << "F(k)" << '\n';
}

void task5While() {
    printTableHeader();
    double k = 1.0;
    while (k <= 5.0 + 1e-9) {
        std::cout << std::fixed << std::setprecision(2)
                  << std::setw(10) << k << std::setw(14) << calculateF(k) << '\n';
        k += 0.5;
    }
}

void task5For() {
    printTableHeader();
    const double values[] = {1.6, 3.0, 3.8, 4.5};
    for (double k : values) {
        std::cout << std::fixed << std::setprecision(2)
                  << std::setw(10) << k << std::setw(14) << calculateF(k) << '\n';
    }
}

int main() {
    int choice{};
    std::cout << "Laboratory Work No. 6: Loops\n"
              << "1 - Sum and count positive integers (do...while)\n"
              << "2 - Fibonacci number\n"
              << "3 - Sum non-positive numbers until negative\n"
              << "4 - Sum of positive odd numbers\n"
              << "5 - Function table (while, variant 3)\n"
              << "6 - Function table (for, variant 3)\n"
              << "Choose a task (1-6): ";
    if (!(std::cin >> choice)) {
        std::cout << "Invalid input.\n";
        return 1;
    }

    switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5While(); break;
        case 6: task5For(); break;
        default: std::cout << "Unknown task.\n"; return 1;
    }
    return 0;
}
