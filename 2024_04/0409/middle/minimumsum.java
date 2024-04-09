class Solution {
    public int minimumSum(int num) {
        String numStr = Integer.toString(num);
        char[] numArray = numStr.toCharArray();
        
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (numArray[i] > numArray[j]) {
                    char temp = numArray[i];
                    numArray[i] = numArray[j];
                    numArray[j] = temp;
                }
            }
        }
        
        int a = (numArray[0] - '0') * 10 + (numArray[2] - '0');
        int b = (numArray[1] - '0') * 10 + (numArray[3] - '0');
        
        return a + b;
    }
}
