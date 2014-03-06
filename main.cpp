#include <stdio.h>
#include "runner.h"

#define N 100


int getIndiceEquilibrio(int* v, int n){

	for(int i = 0; i < n; i++ ){
		int soma_infeior = 0;
		for(int j = 0; j < i; j++){
			//SOMA INFERIOR
			soma_infeior += v[j];
		}
		int soma_superior = 0;
		for(int j = 0; j < i; j++){
			//SOMA SUPERIOR
			soma_superior += v[j];
		}
		if(soma_superior == soma_infeior){
			return i;
		}
		return -1;
	}


	if(n == 3){
		if(v[0] == v[2]){
			return 1;
		} else {
			if (v[0]+v[1] == 0)
			{
				return 2;
			}
			else
			{
				if (v[1]+v[2]== 0)
				{
					return 0;
				}
				else
				{
					return -1;
				}
			}
		}
	}



	return 0;
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


	return 0;
}

int todos_testes() {
	_verify(teste_basico);
	_verify(teste_tres_elementos);
	
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
