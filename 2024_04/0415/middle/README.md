# 백준 1032번 명령 프롬프트

## 문제 설명
>시작 -> 실행 -> cmd를 쳐보자. 검정 화면이 눈에 보인다. 여기서 dir이라고 치면 그 디렉토리에 있는 서브디렉토리와 파일이 모두 나온다. 이때 원하는 파일을 찾으려면 다음과 같이 하면 된다.
dir *.exe라고 치면 확장자가 exe인 파일이 다 나온다. "dir 패턴"과 같이 치면 그 패턴에 맞는 파일만 검색 결과로 나온다. 예를 들어, dir a?b.exe라고 검색하면 파일명의 첫 번째 글자가 a이고, 세 번째 글자가 b이고, 확장자가 exe인 것이 모두 나온다. 이때 두 번째 문자는 아무거나 나와도 된다. 예를 들어, acb.exe, aab.exe, apb.exe가 나온다.
이 문제는 검색 결과가 먼저 주어졌을 때, 패턴으로 뭘 쳐야 그 결과가 나오는지를 출력하는 문제이다. 패턴에는 알파벳과 "." 그리고 "?"만 넣을 수 있다. 가능하면 ?을 적게 써야 한다. 그 디렉토리에는 검색 결과에 나온 파일만 있다고 가정하고, 파일 이름의 길이는 모두 같다.

|입력|출력|
|----|----|
|3<br/>config.sys<br/>config.inf<br/>configures|config???|
|2<br/>contest.txt<br/>context.txt|conte?t.txt|
|3<br/>c.user.mike.programs<br/>c.user.nike.programs<br/>c.user.rice.programs|c.user.?i?e.programs|
|4<br/>a<br/>a<br/>b<br/>b|?|
|1<br/>onlyonefile|onlyonefile|

## 1. C
``` c
#include <stdio.h>
#include <string.h>

int main(){
    int a = 0;
    int length = 0;
    int i=0;
    char b[50][51];
    char c[51];
    
    scanf("%d", &a);
    for(i = 0; i < a; i++){
        scanf("%s", b[i]);
    }
    length = strlen(b[0]);
    strcpy(c,b[0]);
    for(int i = 1; i < a; i++){
        for(int j=0; j<length; j++){
            if(c[j]!='?' && c[j] != b[i][j]){
                c[j]='?';
            }
        }
    }
    printf("%s", c);
    return 0;
}
```

## 문제 해결
문자열을 입력 받아서 첫 번째 문자열과 나머지 문자열들 간 공통된 문자를 찾아 ?로 바꾸도록 하였다.

|Runtime|Memory|
|-------|------|
|0 ms|1.116 mb|

## 2. C++

``` cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int a = 0;
    int length = 0;
    
    cin >> a;
    
    vector<string> b(a);
    string c;
    
    for (int i = 0; i < a; i++) {
        cin >> b[i];
    }
    
    length = b[0].size();
    c = b[0];
    
    for (int i = 1; i < a; i++) {
        for (int j = 0; j < length; j++) {
            if (c[j] != '?' && c[j] != b[i][j]) {
                c[j] = '?';
            }
        }
    }
    
    cout << c;

    return 0;
}
```
## 문제 해결
C와 방식은 동일하다.

|Runtime|Memory|
|-------|------|
|0 ms|2.02 mb|

## 3. Java
``` java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        scanner.nextLine(); // 개행 문자 소비

        String[] b = new String[a];
        String c = "";

        for (int i = 0; i < a; i++) {
            b[i] = scanner.nextLine();
        }

        int length = b[0].length();
        c = b[0];

        for (int i = 1; i < a; i++) {
            for (int j = 0; j < length; j++) {
                if (c.charAt(j) != '?' && c.charAt(j) != b[i].charAt(j)) {
                    char[] cArr = c.toCharArray();
                    cArr[j] = '?';
                    c = String.valueOf(cArr);
                }
            }
        }

        System.out.println(c);
        scanner.close();
    }
}
```

## 문제 해결
동일하다

|Runtime|Memory|
|-------|------|
|212 ms|17.89 mb|

## 4. Python
``` py
a = int(input())
b = [input() for _ in range(a)]
c = b[0]

for i in range(1, a):
    for j in range(len(c)):
        if c[j] != '?' and c[j] != b[i][j]:
            c = c[:j] + '?' + c[j + 1:]

print(c)

```

## 문제 해결
방식은 동일하다.


|Runtime|Memory|
|-------|------|
|44 ms|31.12 mb|
