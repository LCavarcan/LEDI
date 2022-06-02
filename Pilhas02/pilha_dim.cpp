//Tipo registro
typedef struct {
	char nome[30];
	//... (preencher com outros atributos)
}tipo_dado;

//tipo elemento (unidade dinamica)
typedef struct elem {
	tipo_dado info;
	struct elem *lig;
}tipo_elem;

//Tipo pilha
typedef struct {
	tipo_elem *topo;	
}pilha; 

//Cria uma pilha vazia
void Define(pilha *P) {
	p->topo = NULL;
}

//Insere x no topo da pilha p (empilha): Push(x, p)
boolean Push(tipo_dado x, pilha *p) {
	tipo_elem *q = malloc(sizeof(tipo_elem));
	
	if(q == NULL) { //Não possui memória disponível
		return FALSE;
	}
	
	//Insere x e faz as ligações necessárias
	q->info = x;
	q->lig = p->topo;
	p->topo = q;
	
	return TRUE;
}

//Testa se a pilha p está vazia
boolean Vazia(pilha *p) {
	return(p->topo == NULL);
}

//Acessa o eleento do topo da pilha, mas sem remove-lo
tipo_elem *topo(pilha *p) {
	return p->topo;
}

//Remove o elmento no topo de p sem retornar valor
//(desempilhar(v.01)
void Pop_up(pilha *p) {
	tipo_elem *q = p->topo;
	p->topo = p->topo->lig;
	free(q);
}

//Remove o elemento do topo de p mas devolve o elmento
//(desempilha v.02)
tipo_elem *Pop(pilha *p) {
	tipo_elem *q = p->topo;
	p->topo = p->topo->lig;
	return q;
}
