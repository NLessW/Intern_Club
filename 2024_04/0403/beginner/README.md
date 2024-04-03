# 프로그래머스 Beginner 각도기

동아리 시작의 첫 날로 예제 2개를 받았다.<br/>
하나만 풀어도 상관 없었고, 자신 있는 언어로 풀라고 했었다.<br/>
일단 난 2개 다 풀어보기로 했었고, 할 줄 아는 언어로 전부 풀어보았다.<br/>
<br/>


문제는 다음과 같다

>각에서 0도 초과 90도 미만은 예각, 90도는 직각, 90도 초과 180도 미만은 둔각 180도는 평각으로 분류합니다. 각 angle이 매개변수로 주어질 때 예각일 때 1, 직각일 때 2, 둔각일 때 3, 평각일 때 4를 return하도록 solution 함수를 완성해주세요.<br/>
각도 기준
>예각 : 0 < angle < 90<br/>
직각 : angle = 90<br/>
둔각 : 90 < angle < 180<br/>
평각 : angle = 180<br/>
제한 조건
>0 < angle ≤ 180<br/>
angle은 정수입니다.<br/>
입출력 예

|angle|result|
|---|---|
|70|1|
|91|3|
|180|4|

## 1. C
``` C
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int angle) {
    int answer = 0;

    if(angle>0 && angle<90){
        return 1;
    }else if(angle==90){
        return 2;
    }else if(angle>90 && angle<180){
        return 3;
    }else if(angle==180){
        return 4;
    }
    return answer;
}
```
조건문 if와 else if로 간단하게 만들어보았다.<br/>
제일 무난한 방법이고 이 문제에서 사용한 언어는 거의 다 이 방식으로 해결하였다. <br/>
angle의 값을 입력받아 조건에 맞는 값을 반환하게 하는 방식이다.<br/>
다른 사람의 답
``` C
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int solution(int ang) {
    int ans = 1;    
    return ang<90?1:ang==90?2:ang<180?3:4;
}
``` 
이렇게 삼항연산으로 간단하게 해결하는법이 있었다는 것을 깨달았다..<br/>


## 2. C++
``` C
#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int answer = 0;
    if(angle>0 && angle<90){
        return 1;
    }else if(angle==90){
        return 2;
    }else if(angle>90 && angle<180){
        return 3;
    }else if(angle==180){
        return 4;
    }
    return answer;
}

``` 
C++도 다를건 없었다. 일단 손에 잡히는대로 풀었고,<br/>모든 문제가 끝난 뒤 답을 봤었기때문에 삼항연산은 없다.
<br/>
다른 사람의 답<br/>
``` C
int solution(int angle) {
    return angle % 90 == 0 ? angle / 90 * 2 : (angle / 90) * 2 + 1; 
}
``` 
이 사람 역시 삼항연산으로 간단하게 해결하였다..<br/>
단순히 문제만 보고 제일 쉬운 조건문 if로 처리할려고 했던 내가 작아지는 느낌이였고 다른 프로젝트에선 종종 사용하던 방식을 여기선 왜 생각하지 못했을까 란 생각이 컸다.

## 3. JAVA/JavaScript
``` JAVA
class Solution {
    public int solution(int angle) {
        int answer = 0;
        if(angle>0 && angle<90){
          return 1;
        }else if(angle==90){
          return 2;
        }else if(angle>90 && angle<180){
          return 3;
        }else if(angle==180){
          return 4;
        }
        return answer;
    }
}
``` 
이것 또한 난 if문으로 간단하게 처리하였지만 역시 삼항연산 방식이 존재한다.<br/>
이런 방식이 바로 떠오르지 않는다는 점을 계속 반성하고 보완해 나가겠다.<br/>

다른 사람의 답<br/>
``` JAVA
class Solution {
    public int solution(int angle) {
        return angle == 180 ? 4 : angle < 90 ? 1 : angle == 90 ? 2 : angle > 90 ? 3 : 0;
    }
}
``` 

JavaScript와 파이썬 모두 if문을 사용해 처리하였다.<br/>
이번 문제는 풀면서 딱히 어려움은 없었지만 당연하듯이 문제를 보고 if로 처리할 생각을 하고 다른 방식은 생각도 안한 오늘을 깊게 새기며 보완해 나가겠다.<br/>

사실 파이썬에서 좀 더 특이한 방법으로 풀어보고자 리스트에 반복문과 조건문을 섞어서 조합을 해보았다.

``` py
def solution(angle):
    classifications = [1, 2, 3, 4]
    angles = [90, 180]

    for i in range(len(angles)):
        if angle <= angles[i]:
            return classifications[i]

    return 4

```
실제로 짰던 코드인데... 실패했다.<br/>
예각만 작동되어 하나 하나 고치면 하나씩 고쳐지고 빠지고 반복이였다.<br/>
결국 제일 간단한 방법인 if elif를 사용하여 완성하였지만,
추후 재도전을 기약하면서 이번 과제를 마치겠다.<br/>