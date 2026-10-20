#include <cmath>
#include <iomanip>
#include <iostream>

void task1() {
    double x{}, y{}, z{};

    std::cout << "\nTask 1: Variant 28\n";
    std::cout << "Enter x: ";
    if (!(std::cin >> x)) {
        std::cerr << "Error: x must be a number.\n";
        return;
    }

    std::cout << "Enter y: ";
    if (!(std::cin >> y)) {
        std::cerr << "Error: y must be a number.\n";
        return;
    }

    std::cout << "Enter z (radians): ";
    if (!(std::cin >> z)) {
        std::cerr << "Error: z must be a number.\n";
        return;
    }

    // g = y^(x+1) / (cbrt(|y - 2|) + 3)
    //   + (x + y/2) / (2*|x + y|) * (x + 1)^(-1/sin(z))
    const double denominator1 = std::cbrt(std::abs(y - 2.0)) + 3.0;
    const double denominator2 = 2.0 * std::abs(x + y);
    const double sinZ = std::sin(z);
    const double base = x + 1.0;

    if (std::abs(denominator2) < 1e-12) {
        std::cerr << "Error: x + y must not be zero.\n";
        return;
    }
    if (std::abs(sinZ) < 1e-12) {
        std::cerr << "Error: sin(z) is zero; the exponent is undefined.\n";
        return;
    }
    if (base <= 0.0) {
        std::cerr << "Error: x + 1 must be positive for a real-valued result.\n";
        return;
    }

    const double firstTerm = std::pow(y, x + 1.0) / denominator1;
    const double exponent = -1.0 / sinZ;
    const double secondTerm =
        ((x + y / 2.0) / denominator2) * std::pow(base, exponent);
    const double g = firstTerm + secondTerm;

    if (!std::isfinite(g)) {
        std::cerr << "Error: result is outside the supported numeric range.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Result: g = " << g << '\n';
}

void task2() {
    double distanceKm{}, fuelConsumption{}, fuelPrice{}, additionalCosts{};

    std::cout << "\n=== Task 2: Trip cost calculator ===\n";

    std::cout << "Enter trip distance (km): ";
    if (!(std::cin >> distanceKm) || distanceKm < 0.0) {
        std::cerr << "Error: distance must be a non-negative number.\n";
        return;
    }

    std::cout << "Enter fuel consumption (litres per 100 km): ";
    if (!(std::cin >> fuelConsumption) || fuelConsumption < 0.0) {
        std::cerr << "Error: fuel consumption must be non-negative.\n";
        return;
    }

    std::cout << "Enter fuel price per litre: ";
    if (!(std::cin >> fuelPrice) || fuelPrice < 0.0) {
        std::cerr << "Error: fuel price must be non-negative.\n";
        return;
    }

    std::cout << "Enter additional costs: ";
    if (!(std::cin >> additionalCosts) || additionalCosts < 0.0) {
        std::cerr << "Error: additional costs must be non-negative.\n";
        return;
    }

    const double fuelNeeded = distanceKm * fuelConsumption / 100.0;
    const double fuelCost = fuelNeeded * fuelPrice;
    const double totalCost = fuelCost + additionalCosts;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nTrip cost calculation\n";
    std::cout << "Fuel needed: " << fuelNeeded << " litres\n";
    std::cout << "Fuel cost: " << fuelCost << '\n';
    std::cout << "Additional costs: " << additionalCosts << '\n';
    std::cout << "Total trip cost: " << totalCost << '\n';
}

int main() {
    std::cout << "Laboratory work 3\n"
              << "1 - Calculate function (variant 28)\n"
              << "2 - Calculate trip cost\n"
              << "Choose task (1 or 2): ";

    int choice{};
    if (!(std::cin >> choice)) {
        std::cerr << "Error: enter 1 or 2.\n";
        return 1;
    }

    switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        default:
            std::cerr << "Error: choose 1 or 2.\n";
            return 1;
    }

    return 0;
}
