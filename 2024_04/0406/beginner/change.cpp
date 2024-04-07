#include <iostream>
#include <vector>

using namespace std;

int main() {
    int defaultMoney = 1000;
    int changesMoney = 0;
    int count = 0;
    vector<int> coin = {500, 100, 50, 10, 5, 1};
    cin >> changesMoney;
    defaultMoney -= changesMoney;

    for (int i = 0; defaultMoney > 0 && i < coin.size(); ++i) {
        count += defaultMoney / coin[i];
        defaultMoney %= coin[i];
    }

    cout << count;
    return 0;
}
