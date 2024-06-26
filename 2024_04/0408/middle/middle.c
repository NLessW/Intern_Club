#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*numbers_len*(numbers_len-1));
    int count = 0;
    
    for(int i = 0; i<numbers_len; i++){
        for(int j = i+1; j<numbers_len; j++){
            int result = numbers[i] + numbers[j];
            bool sort = false;
            for(int k=0; k<count; k++){
                if(answer[k] == result) {
                    sort = true;
                    break;
                }
            }
            if(sort == false)
                answer[count++] = result;
            
        }
    }
    for(int i=0; i<count; i++){
        for(int j=i+1; j<count; j++){
            int temp;
            if(answer[i]>=answer[j]){
                temp=answer[i];
                answer[i]=answer[j];
                answer[j]=temp;
            }
        }
    }
    return answer;
}
