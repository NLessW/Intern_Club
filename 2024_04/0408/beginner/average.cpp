#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int sum = 0;
    double answer = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
    answer = (double)sum/arr.size();
    return answer;
}
