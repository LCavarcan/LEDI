#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//Tamanho da matriz de conexões e vetor de distancias
#define N 5

//Programa principal
//Matriz A: representa as ligações entre as cidade 0,..., N-1
//Vetor dist: dist[i] é a distancia da cidade c até a cidade i
int main(int argc, char** argv) {
	//Inicialização da matriz das cidades
	int A[N][N] = {{0,1,0,0,0}, {0,0,1,0,0}, {0,0,0,0,1}, {0,0,1,0,1}, {0,1,0,0,0}};
	int dist[N];
	int i, j, c=1;
	fila F;
	
	for(j=0;j<N;j++) {
		dist[i] = N; //Seta a dist[i] = infinito, para todo i
	}
	
	dist[c] = 0;
	Definir(&F); //Cria uma fila vazia
	Inserir(&F, c); //Insere a cidade c na fila
	
	//Roda até que todos os nós tenham sido checados, tira da fila uma cidade i, e coloca na fila as cidades vizinhas j com distancia não computadas
	while(!Vazia(&F)) {
		Remover(&F, &i);
		for(j=0;j<N;j++) {
			if(A[i][j] == 1 && dist[j] >= N) {
				dist[j] = dist[i] + 1;
				Inserir(&F, j);
			}
		}
	}
	
	//Imprime o vetor distancia de c para as cidades i
	for(i=0;i<N;i++) {
		printf("dist[%d]: %d\n", i, dist[i]);
	}
	
	return 0;
}
