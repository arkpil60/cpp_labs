#include <iostream>
using namespace std;

void task1() {
    int arrOneDim28[10] = {12, -4, 7, 0, 19, 5, -8, 14, 3, 10};
    const int size = 10;

    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arrOneDim28[i] << " ";
    }
    cout << "\nEnter B: ";
    int B;
    cin >> B;
    if (!cin) {
        cout << "Invalid input.\n";
        return;
    }

    int count = 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arrOneDim28[i] < B) {
            count++;
            sum += arrOneDim28[i];
        }
    }

    if (count == 0) {
        cout << "No elements smaller than B.\n";
    } else {
        cout << "Count: " << count << "\n";
        cout << "Sum: " << sum << "\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nLab 7 - One-dimensional array\n";
        cout << "1. Count and sum elements smaller than B\n";
        cout << "0. Exit\nChoice: ";
        cin >> choice;
        if (!cin) {
            cout << "Invalid input.\n";
            return 0;
        }
        if (choice == 1) task1();
        else if (choice != 0) cout << "Unknown option.\n";
    } while (choice != 0);
    return 0;
}
