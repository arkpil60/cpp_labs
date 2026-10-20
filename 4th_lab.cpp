#include <cmath>
#include <iomanip>
#include <iostream>
#include <print>

void printTypeSizes() {
    std::println("Sizes of basic data types");
    std::println("sizeof(int)    = {} byte(s)", sizeof(int));
    std::println("sizeof(double) = {} byte(s)", sizeof(double));
    std::println("sizeof(bool)   = {} byte(s)", sizeof(bool));
    std::println("sizeof(char)   = {} byte(s)", sizeof(char));
    std::println("");
}

void calculateTripCost() {
    double distanceKm{};
    double fuelConsumption{};
    double fuelPrice{};
    double additionalCosts{};
    int currencyChoice{};

    int valuesEntered = 0;

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

    const char* currencySymbol =
        (currencyChoice == 1) ? "BYN" :
        (currencyChoice == 2) ? "USD" : "EUR";

    double fuelNeeded = distanceKm * fuelConsumption / 100.0;
    double fuelCost = fuelNeeded;
    fuelCost *= fuelPrice;
    double totalCost = fuelCost;
    totalCost += additionalCosts;

    int calculationSteps = 0;
    ++calculationSteps;
    ++calculationSteps;
    ++calculationSteps;

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
    printTypeSizes();
    calculateTripCost();
    return 0;
}
