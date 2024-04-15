#include <stdio.h>
#include <string.h>

int main(){
    int a = 0;
    int length = 0;
    int i=0;
    char b[50][51];
    char c[51];
    
    scanf("%d", &a);
    for(i = 0; i < a; i++){
        scanf("%s", b[i]);
    }
    length = strlen(b[0]);
    strcpy(c,b[0]);
    for(int i = 1; i < a; i++){
        for(int j=0; j<length; j++){
            if(c[j]!='?' && c[j] != b[i][j]){
                c[j]='?';
            }
        }
    }
    printf("%s", c);
    return 0;
}
