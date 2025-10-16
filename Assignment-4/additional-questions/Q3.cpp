#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool canBeSorted(queue<int> q, int n) {
    stack<int> s;
    int expected = 1;

    while (!q.empty() || !s.empty()) {
        if (!q.empty() && q.front() == expected) {
            q.pop();
            expected++;
        } else if (!s.empty() && s.top() == expected) {
            s.pop();
            expected++;
        } else if (!q.empty()) {
            s.push(q.front());
            q.pop();
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    queue<int> q;
    int val;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    if (canBeSorted(q, n)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}

