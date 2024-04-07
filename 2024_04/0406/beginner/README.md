# 백준 5585번 거스름돈 계산기

첫 날에 문제를 풀 때 여러방면에서 접근하지 못했던 점을 생각하여, 한 번의 시도가 아닌 여러번의 시도와 다른 방법을 찾으면서 작성하였다.<br/>

## 문제 설명
>타로는 자주 JOI잡화점에서 물건을 산다. JOI잡화점에는 잔돈으로 500엔, 100엔, 50엔, 10엔, 5엔, 1엔이 충분히 있고, 언제나 거스름돈 개수가 가장 적게 잔돈을 준다.<br/>
타로가 JOI잡화점에서 물건을 사고 카운터에서 1000엔 지폐를 한장 냈을 때, 받을 잔돈에 포함된 잔돈의 개수를 구하는 프로그램을 작성하시오.
<br/>

## 제한 조건
>입력은 한 줄로 이루어져 있고, 타로가 지불할 돈(1 이상 1000미만의 정수) 1개가 쓰여져 있다.<br/>
제출할 출력 파일은 1행으로만 되어 있다. 잔돈에 포함된 매수를 출력하시오.<br/>
<br/>

|입력|출력|
|---|---|
|380|4|
|1|15|

## 1. C
밑 코드들 전부는 사용자로부터 입력받은 값을 뺀 뒤 그 값을 거스름돈으로 바꾸었을 때, 거슬러주는 동전의 개수를 계산하는 프로그램이다.

``` C
#include<stdio.h>

int main(){
    int defaultMoney = 1000;
    int changesMoney = 0;
    int count = 0;
    int i = 0;
    int coin[6] = {500, 100, 50, 10, 5, 1};
    scanf("%d", &changesMoney);
    defaultMoney -= changesMoney;

    while(defaultMoney>0){
        if(defaultMoney >= coin[i]){
            defaultMoney-=coin[i]; count++;
        }else i++;
    }
    printf("%d", count);
    return 0;
}
```

## 문제 해결
배열로 지정된 잔돈을 저장하고 무한 루프를 돌려 0이 될때까지 반복시키면서 배열의 값과 비교해서 뺀 뒤 count를 이용해 1번씩 뺄때마다 횟수를 저장시켰다.<br/><br/>

## 2. C++
``` C++
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
        while (defaultMoney >= coin[i]) {
            defaultMoney -= coin[i];
            count++;
        }
    }

    cout << count;
    return 0;
}
```

## 문제 해결
C에서 배열 부분을 vector로 설정한 것 외엔 방식은 똑같다.<br/>
while처럼 무한루프를 안시킨다는 점 외엔 방식의 차이는 없다<br/>

## 3. Java
``` JAVA
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int defaultMoney = 1000;
        int changesMoney = 0;
        int count = 0;
        int i = 0;
        int[] coin = {500, 100, 50, 10, 5, 1};

        changesMoney = scanner.nextInt();
        defaultMoney -= changesMoney;

        while (defaultMoney > 0) {
            if (defaultMoney >= coin[i]) {
                defaultMoney -= coin[i];
                count++;
            } else {
                i++;
            }
        }

        System.out.println(count);
        scanner.close();
    }
}
```

## 4. Python
```py
default_money = 1000
changes_money = 0
count = 0
i = 0
coin = [500, 100, 50, 10, 5, 1]

changes_money = int(input())
default_money -= changes_money

while default_money > 0:
    if default_money >= coin[i]:
        default_money -= coin[i]
        count += 1
    else:
        i += 1

print(count)
```

## 마치며
위 두 개의 코드도 C와 전부 같은 방식이며 이 외엔 방법은 찾지 못하였다. 다른 사람의 해결 방식을 찾아보아도 전부 비슷한 방식이였다.<br/>
이미 예전에 풀어본 문제지만 다시 한 번 복습하고 다른 방법을 찾아볼려고 했었지만 못한게 아쉬울뿐이다.<br/>
