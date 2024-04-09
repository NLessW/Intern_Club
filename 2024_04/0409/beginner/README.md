# LeetCode Two Sum

## 문제 설명
>Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.<br/>
You may assume that each input would have exactly one solution, and you may not use the same element twice.<br/>
You can return the answer in any order.<br/><br/>
정수 배열 nums와 target이 주어졌을 때, 두 숫자의 합이 target이 되도록 하는 두 숫자의 인덱스를 반환한다.<br/>
각 입력에 정확히 한 가지의 해결책이 있다고 가정하며, 동일한 요소를 두 번 사용할 수 없다.<br/>
결과는 어떤 순서로든 반환할 수 있다.<br/>

## 제한 조건
- 2 <= nums.length <= 10^4 <br/>
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9

## 1. C
``` C
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    for(int i = 0; i < numsSize; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
```

## 문제해결
returnSize 포인터로 반환할 배열의 크기를 설정하고, 결과를 저장할 동적 배열 result를 만든다. 반복문으로 배열을 순회하고, 두 숫자의 합이
target과 일치하는지 확인하고 조건 충족시 해당 인덱스를 result에 저장하고 반환한다.
만약 찾지 못했다면 returnSize를 0으로 설정한다.

## 2. C++
``` cpp
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        std::vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end()) {
                result.push_back(numMap[complement]);
                result.push_back(i);
                return result;
            }
            numMap[nums[i]] = i;
        }

        return result; // No solution found
    }
};
```

## 문제해결
C와 같은 방식, 배열을 vector로 변경

## 3. JAVA/JS
``` java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> numMap = new HashMap<>();
        
        for (int i = 0; i < nums.length; ++i) {
            int complement = target - nums[i];
            if (numMap.containsKey(complement)) {
                return new int[] {numMap.get(complement), i};
            }
            numMap.put(nums[i], i);
        }
        return new int[0];
    }
}
```

``` js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const numMap = new Map();
    
    for (let i = 0; i < nums.length; ++i) {
        const complement = target - nums[i];
        if (numMap.has(complement)) {
            return [numMap.get(complement), i];
        }
        numMap.set(nums[i], i);
    }
    
    // No solution found
    return [];
};
```

## 문제해결
c와 같은 방식, js는 한줄로 줄여볼려 했지만 실패했다.

줄여본 코드
``` js
const twoSum = (nums, target) => nums.reduce((acc, num, i) => acc[num] !== undefined ? [acc[num], i] : (acc[target - num] = i, acc), []);
```

## 4. Python
``` py
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        return next(([i, j] for i, num1 in enumerate(nums) for j, num2 in enumerate(nums[i+1:], start=i+1) if num1 + num2 == target), [])
```
enumerate(nums)를 사용해 배열의 각 요소와 인덱스를 반복하고 num1+num2==target을 사용하여 두 숫자의 합이 target과 같은지 확인하고
조건이 충족된다면 [i,j]를 반환한다. 조건이 안맞는다면 빈 리스트를 반환한다.


