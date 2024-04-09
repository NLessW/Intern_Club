class Solution {
public:
    int minimumSum(int num) {
    char num_str[5];
    sprintf(num_str, "%d", num);
    
    char num_list[4];
    for (int i = 0; i < 4; i++) {
        num_list[i] = num_str[i];
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (num_list[i] > num_list[j]) {
                char temp = num_list[i];
                num_list[i] = num_list[j];
                num_list[j] = temp;
            }
        }
    }
    
    int a = (num_list[0] - '0') * 10 + (num_list[2] - '0');
    int b = (num_list[1] - '0') * 10 + (num_list[3] - '0');
    
    return a + b;
    }
};
