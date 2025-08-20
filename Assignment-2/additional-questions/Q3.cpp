#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {
        cout << "NO" << endl;
        return 0;
    }
    int count[26] = {0};
    for (char c : a) count[c - 'a']++;
    for (char c : b) count[c - 'a']--;
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
