# 백준 10872번 팩토리얼

## 문제 설명
>0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

|입력|출력|
|---|---|
|10|328800|
|0|1|

## 1. C
``` C
#include <stdio.h>

int main() {
    int fact=1;
    int a=0;
    scanf("%d",&a);
    for(int i=1; i<=a; i++){
        fact*=i;
    }
    printf("%d",fact);
    return 0;
}
```

## 문제 해결
scanf로 입력받고 반복문으로 1씩 빼며 fact 변수에 곱한값을 누적시킨다.

## 2. C++
``` cpp
#include <iostream>

using namespace std;
int main() {
    int fact = 1;
    int a = 0;
    cin >> a;
    for(int i=1; i<=a; i++){
        fact*=i;
    }
    cout<<fact;
    return 0;
}
```
## 문제 해결
C와 동일하다

## 3. JAVA
``` java
import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        int fact=1;
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();

        for(int i=1;i<=a;i++)
            fact*=i;
        System.out.print(fact);
    }
}
```
## 문제 해결
이도 역시 동일하다.

## 4. Python
``` py
import math
a=int(input())
print(math.factorial(a))
```

## 문제 해결
파이썬의 math 모듈을 이용해 자체 내장 함수인 factorial로 단순하게 구하였다.

## 마치며
beginner와 middle의 난이도가 바뀐 것 같다.
반복문만 알고 있으면 어려움 없이 풀 수 있는 문제다.
