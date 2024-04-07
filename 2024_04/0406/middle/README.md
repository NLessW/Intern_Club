# 백준 1919번 애너그램 만들기
이번 문제는 생각보다 단순하다고 생각했었다. 보자마자 어떤 식으로 풀어야할지 바로 그려졌지만, 계속 답이 다르게 나와서 고생 좀 했지만 단순하게 생각하고 접근하면 쉽게 풀 수 있을 것이다.<br/>
이 문제는 C, C++, JAVA, Python으로 해결하였다.

## 문제 설명
>두 영어 단어가 철자의 순서를 뒤바꾸어 같아질 수 있을 때, 그러한 두 단어를 서로 애너그램 관계에 있다고 한다. 예를 들면 occurs 라는 영어 단어와 succor 는 서로 애너그램 관계에 있는데, occurs의 각 문자들의 순서를 잘 바꾸면 succor가 되기 때문이다.<br/>
한 편, dared와 bread는 서로 애너그램 관계에 있지 않다. 하지만 dared에서 맨 앞의 d를 제거하고, bread에서 제일 앞의 b를 제거하면, ared와 read라는 서로 애너그램 관계에 있는 단어가 남게 된다.<br/>
두 개의 영어 단어가 주어졌을 때, 두 단어가 서로 애너그램 관계에 있도록 만들기 위해서 제거해야 하는 최소 개수의 문자 수를 구하는 프로그램을 작성하시오. 문자를 제거할 때에는 아무 위치에 있는 문자든지 제거할 수 있다.

## 제한 조건
>첫째 줄과 둘째 줄에 영어 단어가 소문자로 주어진다. 각각의 길이는 1,000자를 넘지 않으며, 적어도 한 글자로 이루어진 단어가 주어진다.<br/>
첫째 줄에 답을 출력한다.
<br/>

|입력|출력|
|-----|-----|
|aabbcc<br/>xxyyzz|8|

## 1. C
### 코드
``` C
#include <stdio.h>
#include <string.h>

char a[1000], b[1000];
int main() {
    scanf("%s %s", &a, &b);

    int c = strlen(a) + strlen(b);
    for(int i=0; i < strlen(a); i++){
        for(int j = 0; j < strlen(b); j++){
            if(a[i] == b[j]){
                a[i] = -1;
                b[j] = -2;
                c -= 2;
            }
        }
    }
    printf("%d",c);
}
```

## 문제 해결
사용자로부터 두 개의 문자열을 입력받고, 각 문자열에서 공통으로 나타나는 문자의 수를 계산하기 위해 중첩 루프를 사용하였다.

### 코드 설명
1. 첫 번째 문자열과 두 번째 문자열의 길이를 더한 값을 'c'에 저장한다.
``` C
int c = strlen(a) + strlen(b);
```
2. 중첩된 루프를 사용하여 첫 번째 문자열의 각 문자와 두 번째 문자열의 각 문자를 비교한다.
``` C
for(int i=0; i < strlen(a); i++){
        for(int j = 0; j < strlen(b); j++){
```
3. 동일한 문자가 발견된다면, 해당 문자를 임시적으로 다른 값으로 변경 후, 변수 c에서 2를 뺀다.<br/>
c에서 2를 빼는 이유는 동일한 문자가 발견되었을 때, 같은 문자를 중복으로 세는 것을 방지하기 위함이다.<br/>
``` C
if(a[i] == b[j]){
                a[i] = -1;
                b[j] = -2;
                c -= 2;
```

4. 모든 문자열을 검사 후 변수 c에 남아있는 값이 두 문자열에서 공통으로 나오는 문자의 갯수이고 출력한다.
``` C
printf("%d",c);
```

## 발생한 문제들
1. NZEC 
   이 문제를 풀면서 2번이나 나왔던 오류이다. 처음에 문자열 길이를 잘못 설정하여 나왔던 오류로 추정된다.<br/>
   변경 후 NZEC오류는 사라졌었다.<br/>
2. BrokenPipe
   중복된 문자의 개수를 세는 부분에서 발생하였다.<br/>
   문자 열의 길이를 합산하여 문자의 개수를 세는 방식으로 변경 후 해결되었다.<br/>
   참조 : https://stackoverflow.com/questions/4584904/what-causes-the-broken-pipe-error<br/>

   
## 2. C++
### 코드
``` C++
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int count = 0;
    vector<int> a1(26, 0), b1(26, 0); 

    string a2, b2;
    cin >> a2 >> b2;

    for (char c : a2) {
        if (c >= 'a' && c <= 'z') {
            a1[c - 'a']++;
        }
    }

    for (char c : b2) {
        if (c >= 'a' && c <= 'z') {
            b1[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        count += abs(a1[i] - b1[i]);
    }

    cout << count;
    return 0;
}
```

## 문제 해결
각 알파벳의 횟수의 차이를 계산하여 두 문자열의 알파벳 등장 횟수의 차이를 출력하도록 하였다.

### 코드 설명
1. 각 문자열에서 알파벳 등장 횟수를 카운트 한다.
``` C++
for (char c : a2) {
    if (c >= 'a' && c <= 'z') {
        a1[c - 'a']++;
    }
}

for (char c : b2) {
    if (c >= 'a' && c <= 'z') {
        b1[c - 'a']++;
    }
}
```
2. 두 문자열의 알파벳 등장 횟수의 차이를 계산한다
``` C++
for (int i = 0; i < 26; i++) {
        count += abs(a1[i] - b1[i]);
}
```

3. 결과를 출력한다.
``` C++
cout << count;
```

## 발생한 문제들
이 부분은 C언어를 C++로 변환한 과정으로 발생한 문제는 없었다.

## 3. JAVA
``` JAVA
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = 0;
        int[] a1 = new int[26];
        int[] b1 = new int[26];

        String a2 = scanner.next();
        String b2 = scanner.next();

        for (char c : a2.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                a1[c - 'a']++;
            }
        }

        for (char c : b2.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                b1[c - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            count += Math.abs(a1[i] - b1[i]);
        }

        System.out.println(count);
        scanner.close();
    }
}
```

## 문제 해결
위 내용과 똑같다.

## 코드 설명
1. 입력 부분은 생략하고 첫 번째 문자열과 두 번째 문자열의 알파벳 등장 횟수를 카운트 한다.
``` JAVA
for (char c : a2.toCharArray()) {
    if (c >= 'a' && c <= 'z') {
        a1[c - 'a']++;
    }
}        
for (char c : b2.toCharArray()) {
    if (c >= 'a' && c <= 'z') {
        b1[c - 'a']++;
    }
}
```
2. 차이를 계산한다.
``` JAVA
for (int i = 0; i < 26; i++) {
    count += Math.abs(a1[i] - b1[i]);
}
```
3. 출력한 뒤 scanner를 닫는다.
``` JAVA
System.out.println(count);
scanner.close();
```

## 발생한 문제
C++을 Java로 변환한 과정으로 발생한 문제는 오타등의 에러말고는 없었다.<br/>

## 4. Python
### 코드
``` py
count = 0
a1 = [0] * 26
b1 = [0] * 26

a2 = input()
b2 = input()

for c in a2:
    if 'a' <= c <= 'z':
        a1[ord(c) - ord('a')] += 1

for c in b2:
    if 'a' <= c <= 'z':
        b1[ord(c) - ord('a')] += 1

for i in range(26):
    count += abs(a1[i] - b1[i])

print(count)
```
## 문제 해결
다른 언어와 같은 방식으로 해결하였다.

## 코드 설명
1. 입력부분은 생략한다. 똑같이 반복문을 이용해 문자열에서 알파벳의 등장 횟수를 카운트한다.
``` py
for c in a2:
    if 'a' <= c <= 'z':
        a1[ord(c) - ord('a')] += 1

for c in b2:
    if 'a' <= c <= 'z':
        b1[ord(c) - ord('a')] += 1
```
2. 차이를 계산해서 count변수에 누적시키면서 저장한다.
``` py
for i in range(26):
    count += abs(a1[i] - b1[i])
```
3. 출력한다.
``` py
print(count)
```

## 발생한 문제들
1. NZEC
   처음에 함수를 이용해 해결할려다 발생한 문제이다.<br/>

처음 작성한 코드
```py
def main():
    count = 0
    a1 = [0] * 26
    b1 = [0] * 26

    a2, b2 = input().split()

    for c in a2:
        if 'a' <= c <= 'z':
            a1[ord(c) - ord('a')] += 1

    for c in b2:
        if 'a' <= c <= 'z':
            b1[ord(c) - ord('a')] += 1

    for i in range(26):
        count += abs(a1[i] - b1[i])

    print(count)

if __name__ == "__main__":
    main()
```
아마 입력 방식이 한 줄로 입력한 것이 문제가 발생하였다고 생각이 든다.<br/>
추후에 입력 방식을 수정한 뒤 재시도를 하였을 땐 성공하였다.<br/>
![image](https://github.com/NLessW/Intern_Club/assets/63160418/45cfdc75-0740-4dcc-b48e-a5585af927c5)

## 마치며
이 문제는 단순하게 접근하고 단순한 사고력을 이용한 문제로 어렵게만 생각하지 않으면 쉽게 접근하여 풀 수 있다 생각한다.<br/>
이번엔 문제를 해결하면서 NZEC과 BrokenPipe 에러가 발생하였지만, 수정에 성공했으며 좀 더 신중하게 문제에 접근하고 코드를 작성하는 연습을 해야겠단 생각이 든 문제였다<br/>
