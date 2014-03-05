#include <stdio.h>
#include "runner.h"

int soma(int a, int b){
	return a+b;
}

int teste_soma_positivo(){
	_assert( soma(1,1) == 2 );
	_assert( soma(2,2) != 5 );
	
	return 0;
}

int teste_soma_negativo(){
	_assert( soma(-1, -1) == -2 );
	_assert( soma(-2, -2) != -4 );
	
	return 0;
}

int teste_soma_alternado(){
	_assert( soma(1, -1) == 0 );
	_assert( soma(1, -2) == -1 );
	
	return 0;
}

int todos_testes() {
	_verify(teste_soma_positivo);
	_verify(teste_soma_negativo);
	_verify(teste_soma_alternado);
	
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
