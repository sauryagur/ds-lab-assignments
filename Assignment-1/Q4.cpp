#include <iostream>
using namespace std;

int main() {
    int choice;
    while (true) {
        cout << "\n——MENU——-\n1.Reverse Array\n2.Matrix Multiplication\n3.Transpose of Matrix\n4.Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int arr[100], n, i, temp;
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements: ";
            for (i = 0; i < n; i++) cin >> arr[i];
            for (i = 0; i < n / 2; i++) {
                temp = arr[i];
                arr[i] = arr[n - i - 1];
                arr[n - i - 1] = temp;
            }
            cout << "Reversed array: ";
            for (i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
        } else if (choice == 2) {
            int r1, c1, r2, c2, i, j, k;
            cout << "Enter rows and columns of first matrix: ";
            cin >> r1 >> c1;
            cout << "Enter rows and columns of second matrix: ";
            cin >> r2 >> c2;
            if (c1 != r2) {
                cout << "Matrix multiplication not possible\n";
                continue;
            }
            int a[10][10], b[10][10], result[10][10] = {0};
            cout << "Enter first matrix: ";
            for (i = 0; i < r1; i++) for (j = 0; j < c1; j++) cin >> a[i][j];
            cout << "Enter second matrix: ";
            for (i = 0; i < r2; i++) for (j = 0; j < c2; j++) cin >> b[i][j];
            for (i = 0; i < r1; i++) for (j = 0; j < c2; j++) for (k = 0; k < c1; k++) result[i][j] += a[i][k] * b[k][j];
            cout << "Resultant matrix:\n";
            for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++) cout << result[i][j] << " ";
                cout << endl;
            }
        } else if (choice == 3) {
            int r, c, i, j;
            cout << "Enter rows and columns of matrix: ";
            cin >> r >> c;
            int a[10][10], t[10][10];
            cout << "Enter matrix elements: ";
            for (i = 0; i < r; i++) for (j = 0; j < c; j++) cin >> a[i][j];
            for (i = 0; i < r; i++) for (j = 0; j < c; j++) t[j][i] = a[i][j];
            cout << "Transpose matrix:\n";
            for (i = 0; i < c; i++) {
                for (j = 0; j < r; j++) cout << t[i][j] << " ";
                cout << endl;
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
