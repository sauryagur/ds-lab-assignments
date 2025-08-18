#include <iostream>
using namespace std;

void diagonalMatrix() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;
    int a[n];
    cout << "Enter diagonal elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << (i == j ? a[i] : 0) << " ";
        cout << endl;
    }
}

void triDiagonalMatrix() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;
    int a[3*n-2];
    cout << "Enter elements row-wise (lower, main, upper diagonals): ";
    for (int i = 0; i < 3*n-2; i++) cin >> a[i];
    cout << "Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i-1 && i>0) cout << a[k++] << " ";
            else if (j == i) cout << a[n-1 + i] << " ";
            else if (j == i+1 && i<n-1) cout << a[2*n-1 + i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

void lowerTriangularMatrix() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;
    int a[n*(n+1)/2], k = 0;
    cout << "Enter elements row-wise: ";
    for (int i = 0; i < n*(n+1)/2; i++) cin >> a[i];
    cout << "Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << (j <= i ? a[k++] : 0) << " ";
        cout << endl;
    }
}

void upperTriangularMatrix() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;
    int a[n*(n+1)/2], k = 0;
    cout << "Enter elements row-wise: ";
    for (int i = 0; i < n*(n+1)/2; i++) cin >> a[i];
    cout << "Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << (j >= i ? a[k++] : 0) << " ";
        cout << endl;
    }
}

void symmetricMatrix() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;
    int a[n*(n+1)/2], k = 0;
    cout << "Enter lower triangular elements row-wise: ";
    for (int i = 0; i < n*(n+1)/2; i++) cin >> a[i];
    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                int idx = i*(i+1)/2 + j;
                cout << a[idx] << " ";
            } else {
                int idx = j*(j+1)/2 + i;
                cout << a[idx] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n——MENU——-\n1.Diagonal Matrix\n2.Tri-diagonal Matrix\n3.Lower Triangular Matrix\n4.Upper Triangular Matrix\n5.Symmetric Matrix\n6.Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) diagonalMatrix();
        else if (choice == 2) triDiagonalMatrix();
        else if (choice == 3) lowerTriangularMatrix();
        else if (choice == 4) upperTriangularMatrix();
        else if (choice == 5) symmetricMatrix();
        else if (choice == 6) break;
        else cout << "Invalid choice\n";
    }
    return 0;
}
