//Operações 
//------------------------------------------
//Define (P): Cria uma pilha P vazia
void Define(pilha *P) {
	p->topo = 0;
}

//Insere x no topo P (empilhar): Push (x, P)
boolean Push(tipo_dado x, pilha *P) {
	if(P->topo == MAX) {
		return FALSE;
	}
	
	P->topo++;
	P->A[P->topo].info = x;
	
	return TRUE;
}

//tESTA SE p É VAZIA
boolean Vazia(pilha *P) {
	return (P->topo == 0);
}

//Acessa o elemento topo da pilha (sem remover)
//OBS: Testar antes se a pilha não está vazia
tipo_elem Top(pilha *P) {
	return P->A[P->topo];
}

//Remove o elemento no topo de P sem retornar valor
//(Desempilha, v.1)
//Obs: Testar antes se a pilha não está vazia
void Pop_up(pilha *P) {
	P->topo--;
}

//Remove e retorna o elemento (todo o registro) eliminado
//(desempilha, v.2)
//Obs: testar antes se a pilha não está vazia
tipo_elem Pop(pilha *P) {
	tipo_elem x = P->A[P->topo];
	P->topo--;
	return x;
}
