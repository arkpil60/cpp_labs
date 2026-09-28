#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <print>

int first();
int second();
int third();

int main() {
    int choice = 0;

    std::println("=== Laboratory Work Management System ===");
    std::println("1. Task 1 (Variant 14 - Math Formula)");
    std::println("2. Task 2 (Fuel Consumption Calculator - Interactive)");
    std::println("3. Task 3 (Data Type Sizes & Math Ops - C++23)");
    std::println("4. Exit");
    std::print("Choose a task to run (1-4): ");
    
    std::cin >> choice;
    std::println("");

    switch (choice) {
        case 1:
            first();
            break;
        case 2:
            second();
            break;
        case 3:
            third();
            break;
        case 4:
            std::println("Exiting the program. Goodbye!");
            break;
        default:
            std::println("Invalid choice! Please restart and enter a number between 1 and 4.");
            break;
    }

    return 0;
}

int first() {

    std::cout << "--- Laboratory Work No.3. Task 1. Variant 14 ---\n";

    double x = 2.444;
    double y = 0.869e-2;  // 0.00869
    double z = -0.13e3;   // -130.0

    double diff = fabs(y - x); 
    double numerator = pow(x, y + 1) + exp(y - 1);
    double denominator = 1 + x * fabs(y - tan(z));

    double h = (numerator / denominator) * (1 + diff) + (pow(diff, 2) / 2.0) - (pow(diff, 3) / 3.0);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Calculation Result h = " << h << "\n\n";

    return 0;
}

int second() {

    std::cout << "--- Laboratory Work No.3. Task 2. Fuel Consumption Calculator ---\n\n";

    double distance{};
    double consumption{};
    double pricePerLiter{};
    std::string currency = "USD";

    std::cout << "Enter trip distance (km): ";
    std::cin >> distance;

    std::cout << "Enter fuel consumption (l / 100 km): ";
    std::cin >> consumption;

    std::cout << "Enter fuel price per liter: ";
    std::cin >> pricePerLiter;

    double requiredFuelQuantity = (consumption / 100.0) * distance;
    double totalFuelCost = pricePerLiter * requiredFuelQuantity;

    std::cout << "\n--- CALCULATION RESULTS ---" << std::endl;
    std::cout << std::fixed << std::setprecision(1); 
    std::cout << "Required fuel quantity: " << requiredFuelQuantity << " liters" << std::endl;

    std::cout << std::fixed << std::setprecision(2); 
    std::cout << "Total fuel cost for the trip: " << totalFuelCost << " " << currency << "\n\n";

    return 0;
}

int third() {

    std::println("--- Laboratory Work No.3. Task 3. Data Type Sizes ---");

    std::println("int size: {} bytes", sizeof(int));
    std::println("double size: {} bytes", sizeof(double));
    std::println("bool size: {} bytes", sizeof(bool));
    std::println("char size: {} bytes", sizeof(char));

    double distance = 250.0;
    double consumption = 8.0;
    double price = 2.0;
    bool isEuro = true;

    distance++;
    consumption /= 100.0;
    
    double fuel = distance; 
    fuel *= consumption;

    double cost = fuel;
    cost *= price;
    cost += 5.0;

    std::string currency = isEuro ? "EUR" : "USD";

    std::println("\n--- Results ---");
    std::println("Distance: {} km", distance);
    std::println("Required fuel: {:.2f} liters", fuel);
    std::println("Total cost: {:.2f} {}", cost, currency);

    return 0;

}