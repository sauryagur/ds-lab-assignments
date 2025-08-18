#include <iostream>
using namespace std;

// part a
void missingLinear() {
    int n, arr[100];
    cout << "Enter size of array (n-1 elements, array from 1 to n): ";
    cin >> n;
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n - 1; i++) cin >> arr[i];

    int missing = n; 
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            missing = i + 1;
            break;
        }
    }
    cout << "Missing number (linear search): " << missing << endl;
}

// part b
void missingBinary() {
    int n, arr[100];
    cout << "Enter size of array (n-1 elements, array from 1 to n): ";
    cin >> n;
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n - 1; i++) cin >> arr[i];

    int low = 0, high = n - 2, missing = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) low = mid + 1;
        else {
            missing = mid + 1;
            high = mid - 1;
        }
    }
    cout << "Missing number (binary search): " << missing << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n——MENU——-\n1.Find Missing Number (Linear)\n2.Find Missing Number (Binary)\n3.Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) missingLinear();
        else if (choice == 2) missingBinary();
        else if (choice == 3) break;
        else cout << "Invalid choice\n";
    }
    return 0;
}

