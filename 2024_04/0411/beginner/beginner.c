#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int li[M];
    int i;
    for (i = 0; i < M; ++i) {
        scanf("%d", &li[i]);
    }
    int res = 0;
    int j;
    for (i = 1; i <= N; ++i) {
        for (j = 0; j < M; ++j) {
            if (i % li[j] == 0) {
                res += i;
                break;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
