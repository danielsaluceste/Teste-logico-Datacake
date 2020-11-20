#include <stdio.h>
#include <stdlib.h>

int vetor[9] = {1, 15, 2, 7, 2, 5, 7, 1, 4};

int calculo(int x){
	int i, j, k, a;
	int p = x;
	
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			k = vetor[i] + vetor[j];
			
			if(k == p){
				if(j != i)
					return 1;
			}
		}
		a++;
	}
	
	return 0;
}

int main(){
	
	int i, x;
	
	printf("Array: \n");
	
	printf("[ ");
	for(i = 0; i<9; i++){
		printf("%i ", vetor[i]);
	}
	printf("]");
	
	printf("\n\nDigite um valor para procurar uma possivel soma no vetor: ");
	scanf("%d", &x);
	int r = calculo(x);
	printf("\n%i ", r);
	if (r == 1){
		printf("(True)");
	} else
		printf("(False)");
}
