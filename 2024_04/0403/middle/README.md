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