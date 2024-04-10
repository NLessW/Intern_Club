#include <stdio.h>

int main() {
    int fact=1;
    int a=0;
    scanf("%d",&a);
    for(int i=1; i<=a; i++){
        fact*=i;
    }
    printf("%d",fact);
    return 0;
}
