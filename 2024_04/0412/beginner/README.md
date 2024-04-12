# LeetCode 2114. Maximum Number of Words Found in Sentences

## 문제 설명
>A sentence is a list of words that are separated by a single space with no leading or trailing spaces.<br/>
You ar given an array of strings sentences, where each sentences[i] represents a single sentence.<br/>
Return the maximum number of words that appear in a single sentence.<br/>
<br/>
문장은 앞뒤 공백없이 단일 공백으로 구분된 단어 목록이다.<br/>
sentences 각 문자열은 sentences[i]에 단일 문장을 나타내는 문자열 배열이 제공된다.<br/>
문장에 나타나는 최대 단어 수를 반환하라.<br/>

## 제한 조건
- 1 <= sentences.length <= 100
- 1 <= sentences[i].length <= 100
- senetnces[i] consists only of lowercase English letters and ' ' only
- sentences[i] does not have leading or trailing spaces.
- All the words in sentences[i] are separted by a single space

|Input Sentences|Output Result|
|---------------|-------------|
|["alice and bob love leetcode",<br/>"I think so too",<br/>"this is great thanks very much"]|6|
|["please wait",<br/>"continue to fight",<br/>"continue to win"]|3|

## 1. C
``` C
int mostWordsFound(char** sentences, int sentencesSize) {
    int maxWords = 0;

    for(int i = 0; i < sentencesSize; i++){
        int count = 0;
        char *sentence = sentences[i];

        for(int j=0; j<strlen(sentence); j++){
            if (sentence[j] == ' '){
                count++;
            }
        }
        count++;
        if(count>maxWords){
            maxWords = count;
        }
    }
    return maxWords;
}
```

## 문제해결
이 문제는 간단하다. 공백으로 단어를 나눈뒤 count로 숫자를 세어 최댓값을 찾아 해결하였다.<br/>

|Runtime|Memory|
|-------|------|
|9 ms|6.19 MB|


## 2. C++
``` cpp
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;
        for(const string& sentence : sentences){
            int count = 0;
            size_t pos = 0;

            while ((pos = sentence.find(' ',pos))!=string::npos){
                count++;
                pos++;
            }
            count++;
            maxWords = max(maxWords, count);
        }
        return maxWords;
    }
};
```

## 문제 해결
C와 동일하다.
|Runtime|Memory|
|-------|------|
|9 ms|12.62 MB|

## 3. Java / JavaScript

### Java
``` java
class Solution {
    public int mostWordsFound(String[] sentences) {
        int maxWords = 0;
        for(String sentence : sentences){
            maxWords = Math.max(maxWords, sentence.split(" ").length);
        }
        return maxWords;
    }
}
```

## 문제 해결
split으로 공백 단위로 끊어 Math 클래스로 최댓값을 구한다.

|Runtime|Memory|
|-------|------|
|3 ms|44.08 MB|

### JavaScript
``` js
const mostWordsFound = sentences => sentences.reduce((max, sentence) => Math.max(max, sentence.split(" ").length), 0);
```

## 문제 해결
Java와 동일한 방식이지만 화살표 함수와 reduce로 간단하게 한줄로 작성하였다.

|Runtime|Memory|
|-------|------|
|63 ms|51.28 MB|

## 4. Python
``` py
class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        return max(len(sentence.split()) for sentence in sentences)
```

## 문제 해결
split으로 나눠 max함수로 값을 구한다.

|Runtime|Memory|
|-------|------|
|46 ms|16.67 MB|
