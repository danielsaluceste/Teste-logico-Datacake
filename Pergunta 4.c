#include <stdio.h>
#include <stdlib.h>

int main(){
	
	//n - numero maximo
	int max = 10;
	
	//quantidade de itens no vetor por padrao
	int padrao = 5;
	
	int vetor[1000] = {9, 2, 3, 1, 4};
	
	int i, h, p, aux, j = 0;
	
	printf("Array antes: \n");
	
	printf("[ ");
	for(i = 0; i<=max; i++){
		printf("%i ", vetor[i]);
	}
	printf("]");
	
	padrao++;

	//valor
	for (i=0; i<=max; i++) {
		//posicao
		for (h=0; h<max; h++) {
			if (vetor[h] == i){
				aux = 2;
			}
			j++;
		}
		if(aux != 2){
			vetor[padrao] = i;
			padrao++;
		}
		aux = 0;
	}
	
	
	printf("\n\nArray depois: \n");
	
	printf("[ ");
	for(i = 0; i<=max; i++){
		printf("%i ", vetor[i]);
	}
	printf("]");
	
	
}
