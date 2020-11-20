#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int vetor[12] = {2, 1, 5, 2, 1, 1, 1, 7, 9, 13, 127, 21};
	
	int tamanho = 12;
	int i, aux, j = 0;
	
	printf("Array antes: \n");
	
	printf("[ ");
	for(i = 0; i<tamanho; i++){
		printf("%i ", vetor[i]);
	}
	printf("]");

	for (i=0; i<tamanho; i++) {
		if (vetor[i] == 1) {
			aux = vetor[j];
			vetor[i] = aux;
			vetor[j] = 1;
			j++;
		}
		
	}
	
	
	printf("\n\nArray depois: \n");
	
	printf("[ ");
	for(i = 0; i<tamanho; i++){
		printf("%i ", vetor[i]);
	}
	printf("]");
	
	
}
