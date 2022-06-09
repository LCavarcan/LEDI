#define TRUE 1
#define FALSE 0
#define boolean int //Tipo booleano
#define tam_fila 100 //Tamanho maximo da fila
#define indice int //Tipo indice

//Estruturas
//---------------------------------
typedef struct {
	int A[tam_fila];
	indice inicio, fim;
}fila;

//Declaração das operações
//---------------------------------
//Cria fila vazia
void Definir(fila *q);

//Chheca se esta vazia
boolean Vazia(fila *q);

//Checa se a fila esta cheia
boolean Cheia(fila *q);

//Adiciona um elmento no fim da fila
boolean Inserir(fila *q, int elem);

//Remove um elemento
boolean Remover(fila *q, int *elem);

//Retorna o tamanho da fila
int Tamanho(fila *q);

//Mostra o começo da fila sem remover o elmento
boolean Inicio_fila(fila *q, int elem);
