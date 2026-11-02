#include <iostream>
using namespace std;

void task2() {
    int arrTwoDim28[4][4] = {
        {4, 8, -2, 5},
        {7, 3, 9, 1},
        {6, 0, 2, 8},
        {5, 4, 7, 10}
    };

    cout << "Matrix:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arrTwoDim28[i][j] << " ";
        }
        cout << "\n";
    }

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += arrTwoDim28[i][i];
    }
    cout << "Main diagonal sum: " << sum << "\n";
}

void task3() {
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int transposed[4][4];

    cout << "Original matrix:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
            transposed[j][i] = arr[i][j];
        }
        cout << "\n";
    }

    cout << "Transposed matrix:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nLab 8 - Two-dimensional arrays\n";
        cout << "1. Sum of main diagonal (task 2)\n";
        cout << "2. Transpose 4x4 matrix (task 3)\n";
        cout << "0. Exit\nChoice: ";
        cin >> choice;
        if (!cin) {
            cout << "Invalid input.\n";
            return 0;
        }
        if (choice == 1) task2();
        else if (choice == 2) task3();
        else if (choice != 0) cout << "Unknown option.\n";
    } while (choice != 0);
    return 0;
}
