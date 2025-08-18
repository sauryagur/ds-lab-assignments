#include <iostream>
using namespace std;

int main() {
    int arr[100], n, i, j, count = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (i = 0; i < n; i++) cin >> arr[i];

    for (i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) count++;
    }

    cout << "Total distinct elements: " << count << endl;
    return 0;
}

