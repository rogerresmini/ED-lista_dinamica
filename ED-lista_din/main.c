// LISTA DINÂMICA - PILHA

#include <stdio.h>
#include <stdlib.h>

typedef struct r{
    int val;
    struct r *prox;
}reg;

int menu();
void inserir(reg *);
void remover(reg *);
void mostrar(reg *);
void removerTudo(reg *);
void preencheLista(reg*);

int main(){
    reg lista;
    lista.prox = NULL;
	reg *ptrlista = &lista;
    int op;
    do{
        op = menu();
        switch (op) {
        case 0:
			// inserir vários elementos por chamada
			preencheLista(ptrlista);
            break;
        case 1:
			// inserir um elemento por chamada (PILHA)
			inserir(&lista);
            break;
        case 2:
			// remover um elemento (PILHA)
			remover(&lista);
            break;
        case 3:
			mostrar(&lista);
            break;
        case 4:
            break;
        default:
            printf("Opcao invalida! \nEscolha outra.");
            break;
        }
    }while(op < 4);
	return 0;
}

int menu(){
    int op;
    printf("***** MENU *****\n");
    printf("1........INSERIR\n");
    printf("2........REMOVER\n");
    printf("3........MOSTRAR\n");
    printf("4...........SAIR\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);
//	printf("\n");
    return(op);
}

void preencheLista(reg *lst){
    reg* lista = lst;
    // função de teste
    int op = 1, val;
    while(op != 0){
        printf("Informe o valor: ");
        scanf("%i", &val);
        reg* novo = (reg*) malloc(sizeof(reg*));
        novo->prox = NULL;
        novo->val = val;
        // encontrar o último da lista e encadear
        while(lista->prox != NULL)
            lista = lista->prox;
        lista->prox = novo;
        printf("Quer inserir mais um elemento? (0-N) (1-S)\n");
        scanf("%i", &op);
    }
    // faltam testes
}

void inserir(reg *cab){
	reg *pAtual;
	pAtual = cab;
    // receber o valor a ser inserido
	int val;
	printf("Informe um valor: ");
	scanf("%d", &val);
    // alocar memória
	reg *nova = (reg*) malloc(sizeof(reg*));
	// inserir o valor na nova posição alocada
	nova->val = val;
	nova->prox = NULL;
    // navegar até a última posição (topo) da pilha
	while(pAtual->prox != NULL){
		// anda na lista
		pAtual = pAtual->prox;
	}
    // ligar (encadear) a última posição da lista com a posição nova
	pAtual->prox = nova;
}

void remover(reg *cab){
	reg *pAtual = cab;
	reg *pAnt = NULL;
    // verificar se existem elementos na pilha
	if(pAtual->prox == NULL)
		printf("Lista vazia!");
	else{
		// navegar até o topo da pilha
		while(pAtual->prox->prox != NULL){
			// andar na lista
			pAtual = pAtual->prox;
		}
		// pAnt aponta para penúltima pos.
		pAnt = pAtual;
		// pAtual aponta para última pos.
		pAtual = pAtual->prox;
		// apontar a penúltima posição para NULL
		pAnt->prox = NULL;
		// liberar memória (apagar) da posição topo
		free(pAtual);
	}

    // penúltima pos.
    reg* anterior = lst;
    reg* topo = anterior->prox;
    // navegar até fim da lista
    // topo será a última pos.
    // anterior será a pos. anterior

    // situações:
    // 1. lista vazia
    // 2. lista com apenas 1 elemento
    // 3. lista com vários elementos
}

void mostrar(reg *cab){
    // verificar se a lista está vazia
    // navegar por toda a lista imprimindo
	reg *lst = cab->prox;
    while (lst != NULL) {
        printf("valor: %i\n", lst->val);
		// andar na lista
        lst = lst->prox;
    }
}


