#include<stdio.h>

int main(){
    int defaultMoney = 1000;
    int changesMoney = 0;
    int count = 0;
    int i = 0;
    int coin[6] = {500, 100, 50, 10, 5, 1};
    scanf("%d", &changesMoney);
    defaultMoney -= changesMoney;

    while(defaultMoney>0){
        if(defaultMoney >= coin[i]){
            defaultMoney-=coin[i]; count++;
        }else i++;
    }
    printf("%d", count);
    return 0;
}

