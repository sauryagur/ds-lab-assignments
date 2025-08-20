#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100], temp[200];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int k = 0;
    for (int i = 0; i < n && k < n; i++) {
        temp[k++] = arr[i];
        if (arr[i] == 2 && k < n) temp[k++] = 2;
    }
    for (int i = 0; i < n; i++) arr[i] = temp[i];
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
