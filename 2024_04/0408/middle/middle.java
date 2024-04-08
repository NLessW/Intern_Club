class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = {};
        int numbers_len = numbers.length;
        int[] result = new int[numbers_len*(numbers_len-1)];
        int count = 0;
        
        for(int i = 0; i<numbers_len; i++){
            for(int j = i+1; j<numbers_len; j++){
                int sum = numbers[i] + numbers[j];
                boolean sort = false;
                for(int k=0; k<count; k++){
                    if(result[k] == sum) {
                        sort = true;
                        break;
                    }
                }
                if(!sort)
                    result[count++] = sum;
            }
        }
        
        for(int i=0; i<count; i++){
            for(int j=i+1; j<count; j++){
                if(result[i]>=result[j]){
                    int temp = result[i];
                    result[i] = result[j];
                    result[j] = temp;
                }
            }
        }
        answer = new int[count];
        for (int i = 0; i < count; i++) {
            answer[i] = result[i];
        }
        
        return answer;
    }
}
