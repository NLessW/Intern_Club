class Solution:
    def minimumSum(self, num: int) -> int:
        num = str(num)
        num_list = []
        
        for i in range(4):
            num_list.append(num[i])        
            num_list.sort()

        a = int(num_list[0] + num_list[2])
        b = int(num_list[1] + num_list[3])
        answer = a+b

        return answer
