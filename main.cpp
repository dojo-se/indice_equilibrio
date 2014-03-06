#include <stdio.h>
#include "runner.h"

#define N 100

int somaVetor(int* v, int limite_inferior, int limite_superior){
	int soma = 0;
	for(int j = limite_inferior; j < limite_superior; j++){
		soma += v[j];
	}

	return soma;
}

int isIndiceEquilibrio(int* v, int n, int indice){

	int soma_infeior = somaVetor(v, 0, indice);
	int soma_superior = somaVetor(v, indice+1, n);

	return soma_superior == soma_infeior;

}

int getIndiceEquilibrio(int* v, int n){

	for(int i = 0; i < n; i++ ){
		if(isIndiceEquilibrio(v, n, i)){
			return i;
		}
	}
	return -1;

}

int teste_basico(){
	int vetor1[N] = {0};
	_assert( getIndiceEquilibrio(vetor1, 1) == 0 );

	return 0;
}

int teste_tres_elementos(){
	int vetor1[N] = {1, 2, 1};
	_assert( getIndiceEquilibrio(vetor1, 3) == 1);

	int vetor2[N] = {1, 2, 2};
	_assert( getIndiceEquilibrio(vetor2, 3) == -1);

	int vetor3[N] = {-1, 1, 2};
	_assert( getIndiceEquilibrio(vetor3, 3) == 2);

	int vetor4[N] = {-1, -2, 2};
	_assert( getIndiceEquilibrio(vetor4, 3) == 0);

	int vetor5[N] = {1, 10, 1};
	_assert( getIndiceEquilibrio(vetor5, 3) == 1);

	int vetor6[N] = {1, 10, 1, 10};
	_assert( getIndiceEquilibrio(vetor6, 4) == -1);

	return 0;
}

int teste_dojo_puzzle(){
	// A[0] = -7 A[1] = 1 A[2] = 5 A[3] = 2 A[4] = -4 A[5] = 3 A[6] = 0
	int vetor1[N] = {-7, 1, 5, 2, -4, 3, 0};
	_assert( getIndiceEquilibrio(vetor1, 7) == 3);
}

int todos_testes() {
	_verify(teste_basico);
	_verify(teste_tres_elementos);
	_verify(teste_dojo_puzzle);
	
	return 0;
}

int main(){
	int resultado = todos_testes();
	
	if(resultado == 0){
		printf("TODOS OS TESTES PASSARAM\n");
	} else {
		printf("%d\n", resultado);
	}
	
	printf("Testes rodados: %d\n", tests_run);
	
	return 0;
}
