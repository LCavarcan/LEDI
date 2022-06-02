#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define boolean int
#define MAX 101

char pilha[100];
int topo;

//Funções simples para manusear pilha
//------------------------------------
void Define() {
    topo = -1;
}

void Push(char x) {
    topo++;
    pilha[topo] = x;
}

char Pop() {
    char c = pilha[topo];
    topo--;
    return c;
}

boolean Vazia() {
	return (topo == -1);
}

//--------------------------

//Retorna TRUE, s a string comtém uma seq. válida (parenteses + colchetes), false c.c
boolean SequenciaValida(char s[]) {
	int i;
	Define();
	char c;
	for(i=0;s[i]!='\0';i++) {
		switch(s[i]) {
			case ')': 
				if(Vazia()) {
					return FALSE;
				}
				c=Pop(); //Desempilha o correspondente parenteses a esquerda
				if(c!='(') {
					return FALSE;
				}
				break; //Novo parenteses entrando
			case ']':
				if(Vazia()) {
					return FALSE;
				}
				c = Pop(); //Desempilha o correspondente colchetes a esquerda
				if(c != '[') {
					return FALSE;
				}
				break; //Novo colchetes entrando
			default: Push(s[i]);
		}
	}
	return Vazia();
}

//Rotina principal
int main() {
    char sequencia[MAX];
    
    printf("Digite uma sequencia de parenteses e colchetes: ");
    scanf("%s", sequencia);
    
    if(SequenciaValida(sequencia)) {
    	printf("Sequencia valida");
	}
	else {
		printf("Sequencia invalida");
	}
	
	return 0;
}
