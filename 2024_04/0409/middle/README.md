# LeetCode Minimum Sum of Four Digit Number After Splitting Digits

## 문제 설명
>You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num. Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.<br/>
> - For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].<br/>
> Return the minimum possible sum of new1 and new2.<br/>
>주어진 정수 num은 정확히 4자리로 구성된 정수이다. num을 사용하여 두 개의 새로운 정수 new1과 new2로 분할한다. new1과 new2에는 선행 0이 있어도 되며, num에 있는 모든 숫자를 사용해야 한다.<br/>
예를 들면, num = 2932가 주어지면 다음과 같은 숫자가 있다. 2개의 2, 1개의 9, 그리고 1개의 3. 가능한 몇 가지 쌍은 [new1,new2]에 [22,93],[22,92],[223,9],[2,329] 등이 있다.<br/>
new1과 new2의 최소 가능한 합을 반환해라.<br/>


## 제한 조건
- 1000 <= num 9999

# 1. C
``` C
int minimumSum(int num) {
    char num_str[5];
    sprintf(num_str, "%d", num);
    
    char num_list[4];
    for (int i = 0; i < 4; i++) {
        num_list[i] = num_str[i];
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (num_list[i] > num_list[j]) {
                char temp = num_list[i];
                num_list[i] = num_list[j];
                num_list[j] = temp;
            }
        }
    }
    
    int a = (num_list[0] - '0') * 10 + (num_list[2] - '0');
    int b = (num_list[1] - '0') * 10 + (num_list[3] - '0');
    
    return a + b;
}
```
## 문제 해결
1. 정수 `num`을 문자열 `num_str`로 변환한다. 이를 위해 `sprintf()` 함수를 사용한다.<br/>
2. 변환된 문자열을 네 자리 숫자로 분할할 배열 `num_list`를 생성하고 초기화한다.<br/>
3. 오름차순으로 정렬하여 최소 합을 얻기 위해 분할된 숫자를 정렬한다.<br/>
4. 정렬된 `num_list`를 사용하여 두 개의 새로운 정수 `a`와 `b`를 계산한다.<br/>
5. `a`와 `b`의 합을 반환한다.<br/>

## 코드 설명
- `num_str`: 입력 정수 `num`의 문자열 표현을 저장한다.
- `num_list`: `num_str`에서 추출한 분할된 숫자를 저장한다.
- `num_list`를 정렬하여 숫자를 오름차순으로 배치하여 최소 합을 얻는다.
- 문자에서 정수로의 ASCII 변환은 문자에서 `'0'`을 뺌으로써 수행된다.


## 2. C++
``` cpp
class Solution {
public:
    int minimumSum(int num) {
    char num_str[5];
    sprintf(num_str, "%d", num);
    
    char num_list[4];
    for (int i = 0; i < 4; i++) {
        num_list[i] = num_str[i];
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (num_list[i] > num_list[j]) {
                char temp = num_list[i];
                num_list[i] = num_list[j];
                num_list[j] = temp;
            }
        }
    }
    
    int a = (num_list[0] - '0') * 10 + (num_list[2] - '0');
    int b = (num_list[1] - '0') * 10 + (num_list[3] - '0');
    
    return a + b;
    }
};
```

## 문제해결
1. 정수 `num`을 문자열 `num_str`로 변환한다. 이를 위해 `sprintf()` 함수를 사용한다.<br/>
2. 변환된 문자열을 네 자리 숫자로 분할할 배열 `num_list`를 생성하고 초기화한다.<br/>
3. 분할된 숫자를 정렬하여 최소 합을 얻기 위해 이중 반복문을 사용한다.<br/>
   - 외부 반복문은 배열의 요소를 하나씩 탐색한다.<br/>
   - 내부 반복문은 현재 요소 이후의 요소들과 비교하여 정렬한다.<br/>
4. 정렬된 `num_list`를 사용하여 두 개의 새로운 정수 `a`와 `b`를 계산한다.<br/>
   - `a`와 `b`는 각각 `num_list`의 첫 번째와 세 번째, 두 번째와 네 번째 요소로 구성된다.<br/>
5. `a`와 `b`의 합을 반환한다.<br/>

## 코드 설명
- `num_str`: 입력 정수 `num`의 문자열 표현을 저장한다.<br/>
- `num_list`: `num_str`에서 추출한 분할된 숫자를 저장하는 배열이다.<br/>
- 배열을 정렬하여 숫자를 오름차순으로 배치하여 최소 합을 얻는다.<br/>
- 문자에서 정수로의 ASCII 변환은 문자에서 `'0'`을 빼주어 수행된다.<br/>


## 3. Java
``` java
class Solution {
    public int minimumSum(int num) {
        String numStr = Integer.toString(num);
        char[] numArray = numStr.toCharArray();
        
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (numArray[i] > numArray[j]) {
                    char temp = numArray[i];
                    numArray[i] = numArray[j];
                    numArray[j] = temp;
                }
            }
        }
        
        int a = (numArray[0] - '0') * 10 + (numArray[2] - '0');
        int b = (numArray[1] - '0') * 10 + (numArray[3] - '0');
        
        return a + b;
    }
}
```
## 문제 해결
1. 입력된 정수 `num`을 문자열로 변환한다.<br/>
2. 문자열을 문자 배열로 변환하여 각 자리의 숫자를 처리할 수 있도록 한다.<br/>
3. 이중 반복문을 사용하여 숫자를 정렬한다.<br/>
   - 외부 반복문은 배열의 요소를 하나씩 탐색한다.<br/>
   - 내부 반복문은 현재 요소 이후의 요소들과 비교하여 정렬한다.<br/>
4. 정렬된 숫자를 이용하여 두 개의 새로운 정수 `a`와 `b`를 계산한다.<br/>
5. `a`와 `b`의 합을 반환한다.<br/>

## 코드 설명
- `numStr`: 입력된 정수 `num`을 문자열로 변환한 값이다.<br/>
- `numArray`: 문자열을 문자 배열로 변환하여 각 자리의 숫자를 처리하기 위한 배열이다.<br/>
- 배열을 정렬하여 숫자를 오름차순으로 배치하여 최소 합을 얻는다.<br/>
- 문자에서 정수로의 변환은 ASCII 값을 활용하여 수행한다.<br/>

## 4. JavaScript
``` js
var minimumSum = num => {
    var numArray = num.toString().split('').sort();
    return (parseInt(numArray[0]) * 10 + parseInt(numArray[2])) + (parseInt(numArray[1]) * 10 + parseInt(numArray[3]));
};
```

## 문제 해결
1. 입력된 정수 `num`을 문자열로 변환하고, 각 자리의 숫자를 처리하기 위해 문자 배열로 변환한다.<br/>
2. 배열을 정렬하여 숫자를 오름차순으로 배치한다.<br/>
3. 정렬된 숫자를 이용하여 두 개의 새로운 정수 `a`와 `b`를 계산한다.<br/>
4. `a`와 `b`의 합을 반환한다.<br/>

## 코드 설명
- `numArray`: 입력된 정수 `num`을 문자열로 변환한 후, 각 자리의 숫자를 처리하기 위해 문자 배열로 변환한 값이다.<br/>
- 정렬된 배열을 사용하여 최소 합을 구한다.<br/>
- 문자열을 숫자로 변환하는 과정은 `parseInt()` 함수를 사용하여 수행된다.<br/>

## 5. Python
``` py
class Solution:
    def minimumSum(self, num: int) -> int:
        num = str(num)
        num_list = []
        
        for i in range(4):
            num_list.append(num[i])        
            num_list.sort()

        a = int(num_list[0] + num_list[2])
        b = int(num_list[1] + num_list[3])
        answer = a+b

        return answer
```

## 문제 해결
1. 입력된 정수 `num`을 문자열로 변환한다.<br/>
2. 네 자리 숫자로 분할할 배열 `num_list`를 생성하고 초기화한다.<br/>
3. 분할된 숫자를 정렬하여 최소 합을 얻기 위해 이중 반복문을 사용한다.<br/>
   - 외부 반복문은 배열의 요소를 하나씩 탐색한다.<br/>
   - 내부 반복문은 현재 요소 이후의 요소들과 비교하여 정렬한다.<br/>
4. 정렬된 `num_list`를 사용하여 두 개의 새로운 정수 `a`와 `b`를 계산한다.<br/>
5. `a`와 `b`의 합을 반환한다.<br/>


## 코드 설명
- `num_list`: 입력된 정수 `num`을 문자열로 변환한 후, 각 자리의 숫자를 처리하기 위해 사용하는 배열이다.<br/>
- 배열을 정렬하여 숫자를 오름차순으로 배치하여 최소 합을 얻는다.<br/>
- 문자열을 정수로 변환하여 합을 계산한다.<br/>
