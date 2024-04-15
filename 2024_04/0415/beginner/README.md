# 프로그래머스 인덱스 바꾸기

## 문제 설명
>문자열 my_string과 정수 num1, num2가 매개변수로 주어질 때, my_string에서 인덱스 num1과 인덱스 num2에 해당하는 문자를 바꾼 문자열을 return 하도록 solution 함수를 완성해보세요.

## 제한 조건
>1 < my_string의 길이 < 100 <br/>
0 <= num1, num2 < my_string<br/>
my_string은 소문자로 이루어져 있습니다.<br/>
num1 != num2<br/>

|my_string|num1|num2|result|
|---------|----|----|------|
|"hello"|1|2|"hlelo"|
|"I love you"|3|6|"I l veoyou"|

## 1. C
``` c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int num1, int num2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(my_string);
    char arr[2];
    
    arr[0] = my_string[num1];
    arr[1] = my_string[num2];
    answer = my_string;
    answer[num1] = arr[1];
    answer[num2] = arr[0];
    
    return answer;
}
```

## 문제 해결
교환할 문자열을 배열에 저장하고 문자를 서로 교환 후 반환한다.

## 코드 설명
``` c
arr[0] = my_string[num1];
arr[1] = my_string[num2];
```
교환할 문자를 저장하는 배열이다.

``` c
answer[num1] = arr[1];
answer[num2] = arr[0];
```
문자열을 교환한다.

|count|Runtime|memory|
|-----|-------|------|
|test 1|0.01 ms|4.15 mb|
|test 2|0.01 ms|4.2 mb|
|test 3|0.01 ms|4.21 mb|
|test 4|0.01 ms|4.13 mb|


## 2. C++
``` cpp
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    vector<char> char_vector(my_string.begin(), my_string.end());
    char temp = char_vector[num1];
    char_vector[num1] = char_vector[num2];
    char_vector[num2] = temp;
    return string(char_vector.begin(), char_vector.end());
}
```

## 문제 해결
C와 방식은 같은데 vector로만 바꿨다.

|count|Runtime|memory|
|-----|-------|------|
|test 1|0.01 ms|4.12 mb|
|test 2|0.01 ms|4.14 mb|
|test 3|0.02 ms|3.67 mb|
|test 4|0.01 ms|4.2 mb|

## 3. Java
``` java
class Solution {
    public String solution(String my_string, int num1, int num2) {
        String answer = "";
        char[] charArray = my_string.toCharArray();
        
        char temp = charArray[num1];
        charArray[num1] = charArray[num2];
        charArray[num2] = temp;
        
        answer = new String(charArray);
        
        return answer;
    }
}
```
## 문제 해결
같은 방식이다.

|count|Runtime|memory|
|-----|-------|------|
|test 1|0.04 ms|75.3 mb|
|test 2|0.02 ms|71.2 mb|
|test 3|0.04 ms|76.1 mb|
|test 4|0.04 ms|69.7 mb|


## 4. JavaScript

``` js
function solution(my_string, num1, num2) {
    return my_string.substring(0,num1) + my_string.charAt(num2) + my_string.substring(num1 + 1, num2) + my_string.charAt(num1) + my_string.substring(num2+1);
}
```

## 문제 해결
같은 방식이다.

|count|Runtime|memory|
|-----|-------|------|
|test 1|0.03 ms|33.5 mb|
|test 2|0.06 ms|33.4 mb|
|test 3|0.03 ms|33.4 mb|
|test 4|0.03 ms|33.4 mb|

## 5. Python
``` py
def solution(my_string, num1, num2):
    return my_string[:num1] + my_string[num2] + my_string[num1 + 1:num2] + my_string[num1] + my_string[num2 + 1:]
```

|count|Runtime|memory|
|-----|-------|------|
|test 1|0.00 ms|10 mb|
|test 2|0.00 ms|10.2 mb|
|test 3|0.00 ms|10.1 mb|
|test 4|0.00 ms|10.2 mb|
