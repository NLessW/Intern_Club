# 행렬의 덧셈

2번째로 받은 예제 문제이다.<br/>
이것 역시 할 줄 아는 언어 전부 사용하였다.<br/>
C는 문제에 없어 C++부터 시작했다.<br/>
<br/>
문제는 다음과 같다.<br/>
>행렬의 덧셈은 행과 열의 크기가 같은 두 행렬의 같은 행, 같은 열의 값을 서로 더한 결과가 됩니다. 2개의 행렬 arr1과 arr2를 입력받아, 행렬 덧셈의 결과를 반환하는 함수, solution을 완성해주세요.

제한 조건
>행렬 arr1, arr2의 행과 열의 길이는 500을 넘지 않습니다.

입출력 예
|arr1|arr2|return|
|-----|-----|-----|
|[[1,2],[2,3]]|[[3,4],[5,6]]|[[4,6],[7,9]]|
|[[1],[2]]	|[[3],[4]]|[[4],[6]]|		

<br/><br/>

## 1. C++

우선 이 문제는 생각보다 간단했다.<br/>
2개의 배열에서 각 위치에 있는 요소들을 더하고, 새 2차원 배열로 반환하는 문제이다.<br/><br/>
내가 사용한 방법은 2중 for문으로 2차원 배열에서 각 위치에 있는 요소를 꺼낸 뒤 새 배열을 만들어 저장했다.<br/>

``` C
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i=0; i<arr1.size(); i++){
        vector<int> arr3;
        for(int j=0; j<arr1[i].size();j++){
            arr3.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(arr3);
}
    return answer;
}
```
간단하게 주요 부위만 설명을 적어보겠다

``` C
for(int i=0; i<arr1.size(); i++)
```
- 첫 번째 배열 arr1에 접근하는 반복문이다. 
``` C
vector<int> arr3;
```
- 값이 임시로 저장될 배열 arr3를 만든다.
``` C
for(int j = 0; j < arr1[i].size(); j++)
```
- 각 행의 요소에 접근하는 반복문이다.

``` C
arr3.push_back(arr1[i][j] + arr2[i][j]);
```
- 위에서 만든 임시 배열에 같은 위치에 있는 요소를 더한 뒤 저장한다.

``` C
answer.push_back(arr3);
```
- 임시로 만든 배열의 값을 결과 배열에 추가한다.

임시 배열을 만드는 방법이 제일 대중적인것 같다.<br/>
이 문제를 풀고 다른 사람의 답을 보니 나와 똑같은 방식이였다...<br/><br/>

## 2. Java

Java도 C++와 비슷한 방식인데 살짝 바꿔서 풀어보았다.
``` JAVA
class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int[][] answer = {};
        answer=arr1;
        for(int i=0; i<arr1.length; i++){
            for(int j=0; j<arr1[i].length; j++){
                answer[i][j]+=arr2[i][j];
            }
        }
        return answer;
    }
}
```
여기서 C++가 바뀐 방식은 딱 하나다.<br/>
answer의 배열 크기와 arr1의 배열 크기가 똑같다는걸 이용했다.<br/>
answer에 arr1을 할당한 뒤 나머지는 C++과 방식은 동일하다.<br/>
근데 이것도 어째 풀고 나와보니 나와 같은 방법으로 푼 사람이 많았다...<br/>

## 3. JavaScript

C++과 방식은 동일하다.<br/>
임시 배열을 하나 만들고 저장 후 다시 결과 배열에 저장한다.
<br/>

``` JS
function solution(arr1, arr2) {
    var answer = [];
    for(var i=0; i<arr1.length;i++){
        var result=[];
        for(var j=0; j<arr1[i].length;j++){
            result.push(arr1[i][j]+arr2[i][j]);
        }
        answer.push(result);
    }
    return answer;
}
```
JavaScript가 단순하게 사용가능한 언어라 생각해 다른 방법은 없겠지. 라는 생각을 했었다.<br/>
하지만 머리 좋은 사람들은 널렸다.<br/><br/>
다른 사람의 답
``` JS
function sumMatrix(A,B){
    return A.map((arr1, idx1) => arr1.map((val, idx2) => val+B[idx1][idx2]));
}
```
이거보고 한동안 머리를 맞은 느낌이였다.<br/>
화살표 함수와 map을 이용하여 이렇게 간략하게 줄일 수 있다는걸 보고 JavaScript를 더 깊게 알아보고 싶어졌다.<br/>
어짜피 내가 제작중인 카카오톡 봇 프로젝트도 JavaScript를 사용하니까 더 깊게 공부해볼 예정이다.<br/>
처음엔 이해가 안되는 코드였다. 그러다 댓글에 원종건 님의 설명을 보고 이해하고 머리가 멍해졌었다.
저 코드는 경우엔 arr1 = [[1,2],[2,3]]이고, arr2 = [[3,4],[5,6]]일 때 arr1을 맵핑을 한다.<br/>
arr1을 맵핑을 하면 첫 번째 인자로 v = [1,2]가 오고, 인덱스는 0이다.<br/>
이 상태에서 [1,2]를 다시 매핑한다.<br/>
[1,2]의 인덱스 값을 써야하기 때문에 매핑을 한다.<br/>
[1,2]를 맵핑하면 v= [1,2], i = 0인 상태에 새로운 v2= 1, 인덱스 j = 0이 추가되며, j는 [1,2]의 인덱스만큼 반복하기 때문에 j = 1까지 커진다.<br/><br/>


