#include <iostream>
#include <queue>
using namespace std;

void sortQueue(queue<int> &q) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int minIndex = -1;
        int minValue = INT_MAX;
        int sz = q.size();

        for (int j = 0; j < sz; j++) {
            int curr = q.front();
            q.pop();

            if (curr < minValue && j <= sz - i - 1) {
                minValue = curr;
                minIndex = j;
            }
            q.push(curr);
        }

        for (int j = 0; j < sz; j++) {
            int curr = q.front();
            q.pop();
            if (j != minIndex) q.push(curr);
        }

        q.push(minValue);
    }
}

int main() {
    queue<int> q;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    sortQueue(q);

    cout << "Sorted queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
