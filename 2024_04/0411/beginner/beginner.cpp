#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> li(M);
    for (int i = 0; i < M; ++i) {
        cin >> li[i];
    }
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i % li[j] == 0) {
                res += i;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
