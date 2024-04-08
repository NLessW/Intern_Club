# 프로그래머스 두 개 뽑아서 더하기

## 문제 설명
>정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.

## 제한사항
>numbers의 길이는 2 이상 100 이하입니다.
numbers의 모든 수는 0 이상 100 이하입니다.

## 입출력 예
|numbers|result|
|------|------|
|[2,1,3,4,1]|[2,3,4,5,6,7]|
|[5,0,2,7]|[2,5,7,9,12]|

## 1. C
``` C
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*numbers_len*(numbers_len-1));
    int count = 0;
    
    for(int i = 0; i<numbers_len; i++){
        for(int j = i+1; j<numbers_len; j++){
            int result = numbers[i] + numbers[j];
            bool sort = false;
            for(int k=0; k<count; k++){
                if(answer[k] == result) {
                    sort = true;
                    break;
                }
            }
            if(sort == false)
                answer[count++] = result;
            
        }
    }
    for(int i=0; i<count; i++){
        for(int j=i+1; j<count; j++){
            int temp;
            if(answer[i]>=answer[j]){
                temp=answer[i];
                answer[i]=answer[j];
                answer[j]=temp;
            }
        }
    }
    return answer;
}
```

## 문제 해결
이 문제는 평균구하기의 응용이라 생각되어 어렵지않게 해결했고, 버블 정렬을 이용하여 오름차순으로 정리하였다.

## 코드 설명

``` C
for(int i = 0; i<numbers_len; i++){
```
이 부분은 배열 numbers의 모든 값에 대한 반복문이다.<br/>

``` C
for(int j = i + 1; j < numbers_len; j++){
```
이 부분은 외부 i를 이용한 반복문의 현재 i+1만큼부터 시작하는 반복문이다.
``` C
int result = numbers[i] + numbers[j];
```
numbers[i]에서 나온 값과 numbers[j]에서 나온 값을 더하여 int result에 result변수에 저장한.
``` C
bool sort = false;
```
중복 체크를 하기 위해 sort 변수를 사용한다. sort는 정렬인데 sort를 변수명으로 사용한 이유는
중복 제거를 하여 정렬하기 위한 뜻으로 사용했다.

``` C
for(int k=0; k<count; k++){
  if(answer[k] == result) {
    sort = true;
    break;
  }
}
```
반복문으로 배열의 모든 요소를 가져오며, count는 현재 answer배열에 저장된 값의 개수를 나타낸다.<br/>
result로 이미 answer에 값이 있는지 확인하고 있으면 sort를 true로 바꾸고 종료한다.<br/>
```C
if(sort == false)
  answer[count++] = result;
```
값이 중복이 없으면 reuslt를 answer배열에 추가하고 count를 1증가시킨다.

``` C
for(int i=0; i<count; i++){
  for(int j=i+1; j<count; j++){
    int temp;
    if(answer[i]>=answer[j]){
      temp=answer[i];
      answer[i]=answer[j];
      answer[j]=temp;
    }
  }
}
```
버블 정렬로 오름차순으로 정렬하고 종료한다.

## 2. C++

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int numbers_len = numbers.size();
    int* result = (int*)malloc(sizeof(int)*numbers_len*(numbers_len-1));
    int count = 0;
    
    for(int i = 0; i<numbers_len; i++){
        for(int j = i+1; j<numbers_len; j++){
            int sum = numbers[i] + numbers[j];
            bool sort = false;
            for(int k=0; k<count; k++){
                if(result[k] == sum) {
                    sort = true;
                    break;
                }
            }
            if(!sort)
                result[count++] = sum;
        }
    }
    for(int i=0; i<count; i++){
        for(int j=i+1; j<count; j++){
            if(result[i]>=result[j]){
                int temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        answer.push_back(result[i]);
    }
    free(result);
    return answer;
}

```

## 코드 설명
C와 같은 방법이다. 배열을 vector로 바뀐게 전부이다.

## 3. Java/Java Script

### JAVA
``` JAVA
class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = {};
        int numbers_len = numbers.length;
        int[] result = new int[numbers_len*(numbers_len-1)];
        int count = 0;
        
        for(int i = 0; i<numbers_len; i++){
            for(int j = i+1; j<numbers_len; j++){
                int sum = numbers[i] + numbers[j];
                boolean sort = false;
                for(int k=0; k<cou명
java도 같은 방식이다.

### JavaScript
``` js
function solution(numbers) {
    return numbers.reduce((answer, num, idx) => {
        numbers.slice(idx + 1).forEach((n) => {
            const sum = num + n;
            if (!answer.includes(sum)) answer.push(sum);
        });
        return answer;
    }, []).sort((a, b) => a - b);
}
```

## 코드 설명
reduce()를 이용해 합을 계산하고 forEach()로 모든 요소를 조합하여 합을 구한 뒤 중복을 확인한 뒤 중복이 없으면 answer배열에 추가하고 sort()로 정렬시킨다.


## 4. Python
```py
def solution(numbers):
    return sorted({numbers[i] + numbers[j] for i in range(len(numbers)) for j in range(i + 1, len(numbers))})
```

## 코드 설명
numbers[i]와 number[j]를 더하여 합을 구하는데 j는 i와 곂치지않게 값을 설정한 뒤 sort로 정렬한다.


## 마치며
이번에도 평균 구하기를 풀고 정렬만 할 줄 안다면 어렵지 않게 풀 수 있던 문제인거 같다.<br/>
파이썬과 JS에서 최적화로 코드를 짧게 구현하는데 시간이 좀 많이 들긴하였다.<br/>
그래도 성공해서 만족스러운 문제이다.
