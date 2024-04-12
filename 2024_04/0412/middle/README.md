# 백준 2309번 일곱 난쟁이

## 문제 설명
>왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다. 일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.<br/>
아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다.<br/>
수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이 키의 합이 100이 됨을 기억해 냈다.<br/>
아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.

|입력|출력|
|----|----|
|20 7 23 19 10 15 25 8 13|7 8 10 13 19 20 23|

## 1. C
``` c
#include <stdio.h>
#include <stdlib.h>

int main(){
	int arr[9];
	int sum=0;
	int i,j;
	for(i = 0; i<9; i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	
	int height = sum - 100;
	int notD1 = 0;
  int notD2 = 0;
	
	for(i = 0; i<9; i++){
		for(j = i+1; j<9; j++){
			if((arr[i]+arr[j])==height){
				notD1 = i;
				notD2 = j;
				break;
			}
		}
	}
	int temp;
	int realDwarf[7];
	j = 0;
	for(i = 0; i<9; i++){
		if(i != notD1 && i != notD2){
			realDwarf[j] = arr[i];
			j++;
		}
	}
	for(int i=0; i<7; i++){
		for(j=i+1; j<7;j++){
			if(realDwarf[i] > realDwarf[j]){
				temp = realDwarf[i];
				realDwarf[i] = realDwarf[j];
				realDwarf[j] = temp;
			}
		}
	}
	for(int i = 0; i<7; i++){
		printf("%d\n", realDwarf[i]);
	}
}
```

## 문제 해결
9명의 키를 입력 받아 배열에 저장 후, 9명의 키의 합을 구한다.<br/>
그 다음 키의 합에서 100을 뺀 값을 구하면, 이 값이 100을 초과하는 난쟁이들의 키의 합이다.<br/>
가능한 난쟁이의 키를 조합하여 키의 합을 구하고 구한 값과 같은 경우의 수를 찾는다.<br/>

## 코드 설명
``` c
for(i = 0; i < 9; i++){
  for(j = i+1; j < 9; j++){
    if((arr[i]+arr[j])==height){
      notD1 = i;
      notD2 = j;
      break;
    }
  }
}
```
키의 합에서 100을 넘는 키를 찾는 부분이다. 이중for문으로 가능한 조합을 찾는다.


``` c
for(i = 0; i < 9; i++){
  if(i != notD1 && i != notD2){
    realDwarf[j] = arr[i];
    j++;
  }
}
```
위 이중 반복문에서 나온 결과로 두 난쟁이를 제외한 나머지 난쟁이의 키를 저장한다.

``` c
for(int i=0; i<7; i++){
  for(j=i+1; j<7;j++){
    if(realDwarf[i] > realDwarf[j]){
      temp = realDwarf[i];
      realDwarf[i] = realDwarf[j];
      realDwarf[j] = temp;
    }
  }
}
```
버블정렬을 이용해 오름차 순으로 정렬한다.

## 2. C++
``` cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr(9);
    int sum = 0;
  
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int height = sum - 100;
    int notD1 = 0;
    int notD2 = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if ((arr[i] + arr[j]) == height) {
                notD1 = i;
                notD2 = j;
                break;
            }
        }
    }

    vector<int> realDwarf;
    for (int i = 0; i < 9; i++) {
        if (i != notD1 && i != notD2) {
            realDwarf.push_back(arr[i]);
        }
    }

    sort(realDwarf.begin(), realDwarf.end());
  
    for (int i = 0; i < 7; i++) {
        cout << realDwarf[i] << endl;
    }

    return 0;
}
```

## 문제 해결
C와 방식은 동일하다. 배열을 vector로 바꾸고, 버블정렬대신 sort를 사용하여 정렬하였다.

## 3. Java

``` java
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] arr = new int[9];
        int sum = 0;
        
        for (int i = 0; i < 9; i++) {
            arr[i] = scanner.nextInt();
            sum += arr[i];
        }

        int height = sum - 100;
        int notD1 = 0;
        int notD2 = 0;

        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 9; j++) {
                if ((arr[i] + arr[j]) == height) {
                    notD1 = i;
                    notD2 = j;
                    break;
                }
            }
        }

        List<Integer> realDwarf = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            if (i != notD1 && i != notD2) {
                realDwarf.add(arr[i]);
            }
        }
        realDwarf.sort(null);

        for (int i = 0; i < 7; i++) {
            System.out.println(realDwarf.get(i));
        }

        scanner.close();
    }
}
```

## 문제 해결
c와 cpp을 섞은 방식으로 생각하면 쉽다. 

## 4. Python
``` py
def main():
    arr = [0] * 9
    sum = 0
    for i in range(9):
        arr[i] = int(input())
        sum += arr[i]

    # 높이 계산
    height = sum - 100
    notD1 = 0
    notD2 = 0

    for i in range(9):
        for j in range(i + 1, 9):
            if (arr[i] + arr[j]) == height:
                notD1 = i
                notD2 = j
                break

    real_dwarf = [arr[i] for i in range(9) if i != notD1 and i != notD2]

    real_dwarf.sort()

    for i in range(7):
        print(real_dwarf[i])

if __name__ == "__main__":
    main()
```

## 문제 해결
방식은 동일하다.
