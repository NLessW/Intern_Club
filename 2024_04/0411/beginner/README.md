# 백준 17173번 배수들의 합

## 문제 설명
>신원이는 백준에서 배수에 관한 문제를 풀다가 감명을 받아 새로운 문제를 만들어보았다.
자연수 N과  M개의 자연수 Ki가 주어진다. Ki중 적어도 하나의 배수이면서 1 이상 N 이하인 수의 합을 구하여라.

## 제한 조건
> 첫 번째 줄에 N과 M가 주어진다. (2 <= N <= 1000, 1 <= M < N)
그 다음 줄에 M개의 정수 Ki가 주어진다. (2 <= Ki <= 1000)
동일한 Ki는 주어지지 않으며, 오름차순으로 정렬되어있다.

|입력|출력|
|---|---|
|10 2<br/>2 3|42|
|1000 3<br/>3 5 7|272066|

## 1. C

``` C
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int li[M];
    for (int i = 0; i < M; ++i) {
        scanf("%d", &li[i]);
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
    printf("%d\n", res);
    return 0;
}
```

## 문제 해결
N과 M을 입력받고 M개의 정수를 입력받아 li에 저장한다.

## 코드 설명
``` C
for(int i=0; i<m; ++i)
```
반복문을 통해 M개의 정수를 입력받고 li 배열에 저장한다.

``` C
for(int i = 1; i <= N; ++i){
  for(int j = 0; j < M; ++j){
    if(i % li[j] == 0){
      res += i;
      break;
    }
  }
}
```
1부터 N까지의 모든 수에 대해 반복하고 li의 각 요소에 대해 반복한다.<br/>
현재의 수가 배열 li의 요소로 나누어 떨어지는지 확인한다.<br/>
만약 나누어 떨이잔다면 해당 수를 결과에 더하고 반복문을 종료한다.<br/>

## 2. C++

``` cpp
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
```

## 문제 해결
C와 동일하다. 배열을 vector로 바꾼게 끝

## 3. JAVA

``` java
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        ArrayList<Integer> li = new ArrayList<>();

        for (int i = 0; i < M; ++i) {
            li.add(scanner.nextInt());
        }

        int res = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (i % li.get(j) == 0) {
                    res += i;
                    break;
                }
            }
        }

        System.out.println(res);
        scanner.close();
    }
}
```

## 문제 해결
C와 같은 방식

## 4. Python
``` py
N, M = map(int, input().split())
li = list(map(int, input().split()))
res = 0
for i in range(1, N+1):
    for n in li:
        if i%n == 0:
            res += i
            break
print(res)
```

## 문제 해결
배열대신 리스트로 저장하여 해결하였다.
