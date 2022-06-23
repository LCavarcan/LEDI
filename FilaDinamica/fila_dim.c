//Estrutursa e tipos
//Tipo registro
typedef struct {
	char nome[30];
	//...
}tipo_dado;

//Tipo elemento (Unidade de elemento pra implementação dinâmica
typedef struct elem {
	tipo_dado info;
	struct elem *lig;
}tipo_elem;

//Tipo fila
typedef struct {
	tipo_elem *inicio;
	tipo_elem *fim;
}fila;

//Operações
//-------------------------------
//Cria uma fila vazia
void Definir(fila *q) {
	q->inicio = NULL;
	q->fim = NULL;
}

//Verifica se a lista está vazia ou não
boolean Vazia(fila *q) {
	return (q->inicio == NULL);
}

//Reinicializa uma fila ecistente q como uma fila vazia, removendo todos os seus elementos
void Tornar_vazia(fila *q) {
	tipo_elem *ndel, *nextno;
	
	if(!Vazia(q)) {
		nextno = q->inicio;
		
		while(nextno != NULL) {
			ndel = nextno;
			nextno = nextno->lig;
			free(ndel);
		}
	}
	
	Definir(q);
}

//Adicionar um elemento no fim da fila q
boolean Inserir(fila *q, tipo_dado info) {
	tipo_elem *p;
	p = malloc(sizeof(tipo_elem));
	
	if(p == NULL) {
		return FALSE;
	}
	
	p->info = info;
	p->lig = NULL;
	
	if(Vazia(q)) {
		q->inicio = p;
	}
	else {
		q->fim->lig = p;
	}
	
	q->fim = p;
	
	return TRUE;
}

//Remover um elemento do inicio da fila q
boolean Remover(fila *q, tipo_dado *info) {
	tipo_elem *p;
	
	if(Vazia(q)) {
		return FALSE;
	}
	
	p = q->inicio;
	*info = p->info;
	q->inicio = p->lig;
	
	if(q->inicio == NULL) {
		q->fim = NULL;
	}
	
	free(p);
	
	return TRUE;
}

//Retorna o tamanho da fila
int Tamanho(fila *q) {
	tipo_elem *p;
	int cout = 0;
	p = q->inicio;
	
	while(p != NULL) {
		count ++;
		p = p->lig;
	}
	
	return cout;
}

//Mostra o comeco da fila sem remover o elemento
boolena Inicio_fila(fila *q, tipo_dado *elem) {
	if(Vazia(q)) {
		return FALSE;
	}
	
	*elem = q->inicio->info;
	
	return TRUE;
}
