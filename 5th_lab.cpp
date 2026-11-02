#include <iomanip>
#include <iostream>

void task1() {
    constexpr double minVznos = 100.0;
    double summaSheta{};

    std::cout << "\nTask 1: Bank deposit\nEnter the deposit amount: ";
    if (!(std::cin >> summaSheta) || summaSheta < 0.0) {
        std::cout << "Error: enter a non-negative amount.\n";
        return;
    }
    if (summaSheta < minVznos)
        std::cout << "The deposit is below the minimum amount of " << minVznos << ".\n";

    double procent{};
    if (summaSheta < 1000.0)
        procent = (summaSheta / 100.0) * 1.0;
    else
        procent = 15.0 + ((summaSheta - 1000.0) / 100.0) * 1.5;

    std::cout << std::fixed << std::setprecision(2)
              << "Interest amount: " << procent << '\n';
}

void task2() {
    constexpr int correctAccountNumber = 5143;
    double balance = 2560.0;
    int accountNumber{}, choice{};
    std::cout << "\nTask 2: Bank account\nEnter account number: ";
    if (!(std::cin >> accountNumber)) {
        std::cout << "Error: account number must be an integer.\n";
        return;
    }
    if (accountNumber != correctAccountNumber) {
        std::cout << "Incorrect account number.\n";
        return;
    }

    std::cout << "1 - View balance\n2 - Deposit money\n3 - Withdraw money\nChoose an action: ";
    if (!(std::cin >> choice)) {
        std::cout << "Error: enter a menu number.\n";
        return;
    }

    double amount{};
    switch (choice) {
        case 1:
            std::cout << std::fixed << std::setprecision(2) << "Current balance: " << balance << '\n';
            break;
        case 2:
            std::cout << "Enter amount to deposit: ";
            if (!(std::cin >> amount) || amount <= 0.0) {
                std::cout << "Error: amount must be greater than zero.\n";
                return;
            }
            balance += amount;
            std::cout << std::fixed << std::setprecision(2) << "Deposit completed. New balance: " << balance << '\n';
            break;
        case 3:
            std::cout << "Enter amount to withdraw: ";
            if (!(std::cin >> amount) || amount <= 0.0) {
                std::cout << "Error: amount must be greater than zero.\n";
                return;
            }
            if (amount > balance) {
                std::cout << "Insufficient funds.\n";
            } else {
                balance -= amount;
                std::cout << std::fixed << std::setprecision(2) << "Withdrawal completed. New balance: " << balance << '\n';
            }
            break;
        default:
            std::cout << "Unknown menu option.\n";
            break;
    }
}

void task3() {
    constexpr int correctPassword = 5143;
    constexpr int cats = 15;
    constexpr int dogs = 2;
    int enteredPassword{}, choice{};
    double catCost{}, dogCost{};

    std::cout << "\nTask 3: Animal shelter expenses\nEnter password: ";
    if (!(std::cin >> enteredPassword)) {
        std::cout << "Error: password must be an integer.\n";
        return;
    }
    if (enteredPassword != correctPassword) {
        std::cout << "Incorrect password.\n";
        return;
    }

    std::cout << "The shelter has " << cats << " cats and " << dogs << " dogs.\n"
              << "1 - Calculate daily food cost for cats\n"
              << "2 - Calculate daily food cost for dogs\n"
              << "3 - Calculate total daily food cost\nChoose an action: ";
    if (!(std::cin >> choice)) {
        std::cout << "Error: enter a menu number.\n";
        return;
    }

    switch (choice) {
        case 1:
            std::cout << "Enter food cost per cat per day: ";
            if (!(std::cin >> catCost) || catCost < 0.0) {
                std::cout << "Error: cost cannot be negative.\n";
                return;
            }
            if (catCost == 0.0) std::cout << "The entered food cost is zero.\n";
            else std::cout << std::fixed << std::setprecision(2) << "Daily food cost for cats: " << cats * catCost << '\n';
            break;
        case 2:
            std::cout << "Enter food cost per dog per day: ";
            if (!(std::cin >> dogCost) || dogCost < 0.0) {
                std::cout << "Error: cost cannot be negative.\n";
                return;
            }
            if (dogCost == 0.0) std::cout << "The entered food cost is zero.\n";
            else std::cout << std::fixed << std::setprecision(2) << "Daily food cost for dogs: " << dogs * dogCost << '\n';
            break;
        case 3:
            std::cout << "Enter food cost per cat per day: ";
            if (!(std::cin >> catCost) || catCost < 0.0) {
                std::cout << "Error: cost cannot be negative.\n";
                return;
            }
            std::cout << "Enter food cost per dog per day: ";
            if (!(std::cin >> dogCost) || dogCost < 0.0) {
                std::cout << "Error: cost cannot be negative.\n";
                return;
            }
            {
                const double total = cats * catCost + dogs * dogCost;
                std::cout << std::fixed << std::setprecision(2)
                          << "Cats: " << cats * catCost << '\n'
                          << "Dogs: " << dogs * dogCost << '\n'
                          << "Total daily food cost: " << total << '\n';
                if (total > 100.0) std::cout << "Notice: daily food costs exceed 100.\n";
                else std::cout << "Daily food costs are within 100.\n";
            }
            break;
        default:
            std::cout << "Unknown menu option.\n";
            break;
    }
}

void task4() {
    double x{};
    std::cout << "\nTask 4: Function calculation\nGiven f(x) = 3 * x + 2\nEnter x: ";
    if (!(std::cin >> x)) {
        std::cout << "Error: x must be a number.\n";
        return;
    }
    std::cout << std::fixed << std::setprecision(2) << "f(" << x << ") = " << 3.0 * x + 2.0 << '\n';
}

int main() {
    int choice{};
    std::cout << "Laboratory Work No. 5: Conditional Statements\n"
              << "1 - Bank deposit interest\n"
              << "2 - Bank account menu\n"
              << "3 - Animal shelter food expenses\n"
              << "4 - Calculate f(x) = 3*x + 2\nChoose a task (1-4): ";
    if (!(std::cin >> choice)) {
        std::cout << "Error: enter a number from 1 to 4.\n";
        return 1;
    }
    switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        default:
            std::cout << "Unknown task. Choose a number from 1 to 4.\n";
            return 1;
    }
    return 0;
}
