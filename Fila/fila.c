#include "fila.h"

//Operações da fila
//-----------------------------
//Cria fila vazia
void Definir(fila *q) {
	q->inicio = 0;
	q->fim = 0;
}

//Chheca se esta vazia
boolean Vazia(fila *q) {
	return (q->inicio == q->fim);
}

//Checa se a fila esta cheia
boolean Cheia(fila *q) {
	return (q->inicio == ((q->fim + 1)%tam_fila));
	//Obs: os 2 ponteiros diferem de uma posição
}

//Adiciona um elmento no fim da fila
boolean Inserir(fila *q, int elem) {
	if(Cheia(q)) {
		return FALSE;
	}
	
	q->fim = (q->fim + 1)%tam_fila;
	q->A[q->fim] = elem;
	return TRUE;
}

//Remove um elemento
boolean Remover(fila *q, int *elem) {
	if(Vazia(q)) {
		return FALSE;
	}
	
	q->inicio = (q->inicio + 1)%tam_fila;
	*elem = q->A[q->inicio];
	return TRUE;
}

//Retorna o tamanho da fila
int Tamanho(fila *q) {
	if(q->inicio <= q->fim) {
		return (q->fim - q->inicio);
	}
	
	return(tam_fila - (q->inicio - q->fim)); /* AQUI ELE COLOCOU INICIO - FIM */
}

//Mostra o começo da fila sem remover o elmento
boolean Inicio_fila(fila *q, int elem) {
	if(Vazia(q)) {
		return FALSE;
	}
	
	elem = q->A[(q->inicio + 1)%tam_fila];
	return TRUE;
}


