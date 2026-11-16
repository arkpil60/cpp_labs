#include <cmath>
#include <iomanip>
#include <iostream>
#include <print>

// Function 1: print the sizes of the basic types used in this program.
// sizeof returns the size in bytes.
void printTypeSizes() {
    std::println("=== Sizes of basic data types ===");
    std::println("sizeof(int)    = {} byte(s)", sizeof(int));
    std::println("sizeof(double) = {} byte(s)", sizeof(double));
    std::println("sizeof(bool)   = {} byte(s)", sizeof(bool));
    std::println("sizeof(char)   = {} byte(s)", sizeof(char));
    std::println("");
}

// Function 2: calculate the cost of a trip (the independent task from Lab 3).
void calculateTripCost() {
    double distanceKm{};
    double fuelConsumption{};
    double fuelPrice{};
    double additionalCosts{};
    int currencyChoice{};

    // ++ increments the number of successfully entered values.
    int valuesEntered = 0;

    // -- decreases the number of input values still expected.
    int valuesRemaining = 5;

    std::println("=== Trip cost calculator ===");

    std::print("Enter trip distance (km): ");
    if (!(std::cin >> distanceKm) || distanceKm < 0.0) {
        std::println(stderr, "Error: distance must be a non-negative number.");
        return;
    }
    ++valuesEntered;
    --valuesRemaining;

    std::print("Enter fuel consumption (litres per 100 km): ");
    if (!(std::cin >> fuelConsumption) || fuelConsumption < 0.0) {
        std::println(stderr, "Error: fuel consumption must be non-negative.");
        return;
    }
    ++valuesEntered;
    --valuesRemaining;

    std::print("Enter fuel price per litre: ");
    if (!(std::cin >> fuelPrice) || fuelPrice < 0.0) {
        std::println(stderr, "Error: fuel price must be non-negative.");
        return;
    }
    ++valuesEntered;
    --valuesRemaining;

    std::print("Enter additional costs: ");
    if (!(std::cin >> additionalCosts) || additionalCosts < 0.0) {
        std::println(stderr, "Error: additional costs must be non-negative.");
        return;
    }
    ++valuesEntered;
    --valuesRemaining;

    std::println("Choose currency: 1 - BYN, 2 - USD, 3 - EUR");
    std::print("Your choice: ");
    if (!(std::cin >> currencyChoice) ||
        currencyChoice < 1 || currencyChoice > 3) {
        std::println(stderr, "Error: choose 1, 2, or 3.");
        return;
    }
    ++valuesEntered;
    --valuesRemaining;

    // Ternary operator selects the currency symbol.
    const char* currencySymbol =
        (currencyChoice == 1) ? "BYN" :
        (currencyChoice == 2) ? "USD" : "EUR";

    // Compound assignments: *=, /=, *= and +=.
    double fuelNeeded = distanceKm;
    fuelNeeded *= fuelConsumption;
    fuelNeeded /= 100.0;
    double fuelCost = fuelNeeded;
    fuelCost *= fuelPrice;
    double totalCost = fuelCost;
    totalCost += additionalCosts;

    // A calculation-step counter uses prefix increment.
    int calculationSteps = 0;
    ++calculationSteps; // Fuel quantity calculated.
    ++calculationSteps; // Fuel cost calculated.
    ++calculationSteps; // Total cost calculated.

    if (!std::isfinite(fuelNeeded) || !std::isfinite(totalCost)) {
        std::println(stderr, "Error: result is outside the supported numeric range.");
        return;
    }

    std::println("");
    std::println("=== Calculation result ===");
    std::println("Distance: {:.2f} km", distanceKm);
    std::println("Fuel needed: {:.2f} litres", fuelNeeded);
    std::println("Fuel cost: {:.2f} {}", fuelCost, currencySymbol);
    std::println("Additional costs: {:.2f} {}", additionalCosts, currencySymbol);
    std::println("Total trip cost: {:.2f} {}", totalCost, currencySymbol);
    std::println("Input values entered: {}", valuesEntered);
    std::println("Input values remaining: {}", valuesRemaining);
    std::println("Calculation steps: {}", calculationSteps);
}

int main() {
    // Lab 4 requires displaying type sizes first and then running the Lab 3 Task 2 program.
    printTypeSizes();
    calculateTripCost();
    return 0;
}
