#include <iostream>
using namespace std;

int main() {
    int a[10][10], r, c, i, j;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    cout << "Enter elements: ";
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) cin >> a[i][j];

    for (i = 0; i < r; i++) {
        int rowSum = 0;
        for (j = 0; j < c; j++) rowSum += a[i][j];
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }

    for (j = 0; j < c; j++) {
        int colSum = 0;
        for (i = 0; i < r; i++) colSum += a[i][j];
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }

    return 0;
}

