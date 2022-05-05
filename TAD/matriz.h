//TAD: matriz real m x n 

//tipo exportado
typedef struct matriz Matriz;

//fun��es exportadas

//fun��o cria: aloca uma matriz m x n 
Matriz *cria(int m, int n);

//fun��o libera: libera a mem�ria de uma matriz
void libera(Matriz *mat);

//fun��o acessa: retorna o valor do elemento [i][j]
float acessa(Matriz *mat, int i, int j);

//fun��o atribui: atribui valor ao elemento [i][j]
void atribui(Matriz *mat, int i, int j, float v);

//fun��o linhas: retorna o n�mero de linhas da matriz
int linhas(Matriz *mat);

//fun��o colunas: retorna o n�mero de colunas da matriz
int colunas(Matriz *mat);
