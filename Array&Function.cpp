#include <iostream>
using namespace std;

// Function to display elements of an array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to modify elements of an array
void modifyArray(int arr[], int size) {
    cout << "Enter new values for the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Enter value for element " << i << ": ";
        cin >> arr[i];
    }
}

// Function to calculate the sum of elements in an array
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to search for a value in an array
int searchArray(int arr[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i; // Value found, return index
        }
    }
    return -1; // Value not found
}

// Function to sort elements of an array in ascending order
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the maximum and minimum values in an array
void findMinMax(int arr[], int size, int& max, int& min) {
    max = min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }
}

int main() {
    const int size = 5;
    int numbers[size] = {10, 20, 30, 40, 50};

    int choice;
    int searchValue, index, max, min; // Declare variables here

    // Display the original array
    cout << "Original Array: ";
    displayArray(numbers, 5);

    do {
        cout << "\nMenu:\n";
        cout << "1. Modify array\n";
        cout << "2. Sum of array elements\n";
        cout << "3. Search for a value in the array\n";
        cout << "4. Sort the array\n";
        cout << "5. Find maximum and minimum values\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                modifyArray(numbers, size);
                cout << "Modified Array: ";
                displayArray(numbers, size);
                break;
            case 2:
                cout << "Sum of Array Elements: " << sumArray(numbers, size) << endl;
                break;
            case 3:
                cout << "Enter a value to search in the array: ";
                cin >> searchValue;
                index = searchArray(numbers, size, searchValue);
                if (index != -1) {
                    cout << "Value found at index " << index << endl;
                } else {
                    cout << "Value not found in the array" << endl;
                }
                break;
            case 4:
                sortArray(numbers, size);
                cout << "Sorted Array: ";
                displayArray(numbers, size);
                break;
            case 5:
                findMinMax(numbers, size, max, min);
                cout << "Maximum Value: " << max << endl;
                cout << "Minimum Value: " << min << endl;
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
