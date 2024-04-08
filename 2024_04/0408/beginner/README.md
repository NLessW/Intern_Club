# 프로그래머스 평균구하기
이번엔 너무 기초적인 문제라 따로 설명은 적지 않겠다.<br/>

## 문제 설명
>정수를 담고 있는 배열 arr의 평균값을 return하는 함수, solution을 완성해보세요.<br/>

## 제한 조건
>arr은 길이 1 이상, 100 이하인 배열입니다.<br/>
arr의 원소는 -10,000 이상 10,000 이하인 정수입니다.<br/>
<br/>

## 입출력 예
|arr|return|
|---|---|
|[1,2,3,4]|2,5|
|[5,5]|5|

## 1. C

``` C
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
double solution(int arr[], size_t arr_len) {
    int sum = 0;
    double answer = 0;
    for(int i = 0; i<arr_len; i++){
        sum += arr[i];
    }
    return (double)sum / arr_len;
}
```

## 문제 해결
단순히 배열의 값을 sum이라는 변수에 저장 후 배열의 길이만큼 나누어 평균을 구하면 끝이다.

## 2. C++
```cpp
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int sum = 0;
    double answer = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
    answer = (double)sum/arr.size();
    return answer;
}
```

## 문제 해결
C에서 배열 부분이 vector 바뀐것 외에 다른 점은 없다

## 3. JAVA/JavaScript

### JAVA
```JAVA
class Solution {
    public double solution(int[] arr) {
        int sum = 0;
        double answer = 0;
        for(int i = 0; i<arr.length; i++)
            sum += arr[i];        
        return (double)sum/arr.length;
    }
}
```

## 문제 해결
C와 방식은 같다.

### JavaScript
function solution(arr) {
    return arr.reduce((a,b) => a+b) / arr.length;
}

## 코드 설명
reduce()를 사용해 배열의 각 요소를 순회를 시키며 (a,b) => a+b로 각 배열의 요소인 b를 a에 더하는 것이다.

## 문제 해결
처음엔 java나 c와 같은 방식으로 코드를 작성했지만 reduce와 화살표함수가 생각나 줄여보았다.


## 4. Python
```py
def solution(arr):
    return sum(arr)/len(arr)
```

## 문제 해결
파이썬의 sum()함수가 생각나 바로 적용시켜 해결하였다.

## 마치며
이번 문제는 lv.1이라곤 하지만 lv.0이라고 봐도 될 정도로 기본적인 문제였다고 생각하고, 접근 방식을 바꿔 접근해본 첫 문제인거 같다.
