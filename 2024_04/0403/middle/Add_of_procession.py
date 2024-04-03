def solution(arr1, arr2):
    answer = []
    
    for i in range(len(arr1)):
        arr3=[]
        for j in range(len(arr1[i])):
            arr3.append(arr1[i][j]+arr2[i][j])
        answer.append(arr3)
    return answer
