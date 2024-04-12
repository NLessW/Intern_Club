#include <stdio.h>
#include <stdlib.h>

int main(){
	int arr[9];
	int sum=0;
	int i,j;
	for(i = 0; i<9; i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	
	int height = sum - 100;
	int notD1 = 0;
    	int notD2 = 0;
	
	for(i = 0; i<9; i++){
		for(j = i+1; j<9; j++){
			if((arr[i]+arr[j])==height){
				notD1 = i;
				notD2 = j;
				break;
			}
		}
	}
	int temp;
	int realDwarf[7];
	j = 0;
	for(i = 0; i<9; i++){
		if(i != notD1 && i != notD2){
			realDwarf[j] = arr[i];
			j++;
		}
	}
	for(int i=0; i<7; i++){
		for(j=i+1; j<7;j++){
			if(realDwarf[i] > realDwarf[j]){
				temp = realDwarf[i];
				realDwarf[i] = realDwarf[j];
				realDwarf[j] = temp;
			}
		}
	}
	for(int i = 0; i<7; i++){
		printf("%d\n", realDwarf[i]);
	}
}
