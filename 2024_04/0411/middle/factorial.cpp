#include <iostream>

using namespace std;
int main() {
    int fact = 1;
    int a = 0;
    cin >> a;
    for(int i=1; i<=a; i++){
        fact*=i;
    }
    cout<<fact;
    return 0;
}
