#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr(9);
    int sum = 0;
  
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int height = sum - 100;
    int notD1 = 0;
    int notD2 = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if ((arr[i] + arr[j]) == height) {
                notD1 = i;
                notD2 = j;
                break;
            }
        }
    }

    vector<int> realDwarf;
    for (int i = 0; i < 9; i++) {
        if (i != notD1 && i != notD2) {
            realDwarf.push_back(arr[i]);
        }
    }

    sort(realDwarf.begin(), realDwarf.end());
  
    for (int i = 0; i < 7; i++) {
        cout << realDwarf[i] << endl;
    }

    return 0;
}
