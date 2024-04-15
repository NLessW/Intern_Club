#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int a = 0;
    int length = 0;
    
    cin >> a;
    
    vector<string> b(a);
    string c;
    
    for (int i = 0; i < a; i++) {
        cin >> b[i];
    }
    
    length = b[0].size();
    c = b[0];
    
    for (int i = 1; i < a; i++) {
        for (int j = 0; j < length; j++) {
            if (c[j] != '?' && c[j] != b[i][j]) {
                c[j] = '?';
            }
        }
    }
    
    cout << c;

    return 0;
}
