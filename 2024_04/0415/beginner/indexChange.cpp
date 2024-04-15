#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    vector<char> char_vector(my_string.begin(), my_string.end());

    char temp = char_vector[num1];
    char_vector[num1] = char_vector[num2];
    char_vector[num2] = temp;
    return string(char_vector.begin(), char_vector.end());
}
