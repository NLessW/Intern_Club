#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int count = 0;
    vector<int> a1(26, 0), b1(26, 0); 

    string a2, b2;
    cin >> a2 >> b2;

    for (char c : a2) {
        if (c >= 'a' && c <= 'z') {
            a1[c - 'a']++;
        }
    }

    for (char c : b2) {
        if (c >= 'a' && c <= 'z') {
            b1[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        count += abs(a1[i] - b1[i]);
    }

    cout << count;
    return 0;
}
