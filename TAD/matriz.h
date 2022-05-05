//TAD: matriz real m x n 

//tipo exportado
typedef struct matriz Matriz;

//funções exportadas

//função cria: aloca uma matriz m x n 
Matriz *cria(int m, int n);

//função libera: libera a memória de uma matriz
void libera(Matriz *mat);

//função acessa: retorna o valor do elemento [i][j]
float acessa(Matriz *mat, int i, int j);

//função atribui: atribui valor ao elemento [i][j]
void atribui(Matriz *mat, int i, int j, float v);

//função linhas: retorna o número de linhas da matriz
int linhas(Matriz *mat);

//função colunas: retorna o número de colunas da matriz
int colunas(Matriz *mat);
