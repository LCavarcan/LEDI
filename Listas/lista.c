#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define MAX 100 //Estimativa do tamanho da lista
#define TRUE 1 //define um tipo booleano
#define FALSE 0
#define boolean int

//Implementação: lista sequencial

//Estruturas e tipos
//------------------------------
//Tipo chave
typedef int tipo_chave;

//Tipo registro
typedef struct {
	char nome[30];
	//... caso tenham mais campos
}tipo_dado;

//Tipo elemento (registro + chave)
typedef struct {
	tipo_chave chave;
	tipo_dado info;
}tipo_elem;

//Tipo lista (sequencial)
typedef struct {
	int nelem; //Número de elementos 
	tipo_elem A[MAX+1];
}lista;

//Operações
//-----------------------------
boolean Vazia(lista *L) {
	//Retorna true(1): se vazia, e false(0), caso contrário
	return(L->nelem == 0);
}

boolean Cheia(lista *L) {
	//Retorna true, se cheia, false, caso contrário
	return(L->nelem == MAX);
}

void Definir(lista *L) {
	//Cria uma lista vazia. Este procedimento deve ser chamado para cada nova lista antes de qualquer outra operação
	L->nelem = 0;
	L->A[0].chave = 0;
}

void Apagar(lista *L) {
	//Apaga "Logicamente" uma lista 
	L->nelem = 0;
}

boolean Inserir_posic(tipo_elem x, int p, lista *L) {
	//Insere x, que é um novo elemento na posição p da Lista. Se L = a_1, a_2, ..., a_n, então temos a_1, a_2, ..., a_{p-1}, x, a_{p+1}, ..., a_n. Devolve true se sucesso e false caso contrário (isto é: L não tem nenhuma posição p ou Litsa cheia)
	//Obs: Operação para lista não-oredenada
	int q;
	
	if(Cheia(L) || p > L->nelem+1 || p < 1) {
		//Lista cheia ou posição inexistente
		return FALSE;
	}
	else {
		//Copia vizinha pra direita
		for(q = L->nelem; q >= p; q--) {
			L->A[q+1] = L->A[q];
		}
		
		L->A[p] = x;
		L->nelem++;
		
		return TRUE; //Inserção realizada com sucesso
	}
}

boolean Buscar(tipo_chave x, lista *L, int *p) {
	//Retorna true, se x ocorre na posição p. Se x ocorre mais de uma vez, retorna a posição da primeira ocorrência. Se x não ocorre, retorna false
	//OBS: Lista não-ordenada
	if(!Vazia(L)) {
		int i = 1;
		while(i <= L->nelem) {
			if(L->A[i].chave == x) {
				*p = i;
				return TRUE;
			}
			else {
				i++;
			}
		}
		
		return FALSE; // Retorna falso, se não encontrou
	}
}

void Remover_posic(int *p, lista *L) {
	//Só é ativada após a busca ter retornado a posição p do elemento a ser removido
	int i;
	
	for(i = *p+1; i < L->nelem; i++) {
		L->A[i-1] = L->A[i];
	}
	
	L->nelem--;
}

void Impr_elem(tipo_elem x) {
	printf("chave: %d", x.chave);
	printf("nome: %s", x.info.nome);
}

void Imprimir(lista *L) {
	//Imprime os elementos na sua ordem de precedencia
	int i;
	
	if(!Vazia(L)) {
		for(i=1;i<L->nelem;i++) {
			Impr_elem(L->A[i]);
		}
	}
}

int Tamanho(Lista *L) {
	//Retorna o tamanho da lista. Se L é vazia, retorna 0
	return L->nelem;
}

boolean Inserir_ord(tipo_elem x, lista *L) {
	//Insere no elemento de forma a manter a lista ordenada (crescente). Devolve true se sucesso, e false caso contrário
	if(Vazia(L)) {
		return Inserir_posic(x, i, L);
	}
	else {
		while(i<=L->nelem) { //Encontra a posicao de inserção
			if(x.chave < L->A[i].chave) {
				return Inserir_posic(x, i, L);
			}
			else {
				i++;
			}
		}
		
		return Inserir_posic(x, i, L); //i=nelem
	}
}

int main() {
	return 0;
}
