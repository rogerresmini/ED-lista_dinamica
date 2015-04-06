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
            preencheLista(&lista);
            break;
        case 1:
            inserir(&lista);
            break;
        case 2:
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

void inserir(reg *lst){
    // receber o valor a ser inserido
    // alocar memória
    // inserir o valor na nova posição alocada
    // navegar até a última posição (topo) da pilha
    // ligar (encadear) a última posição da lista com a posição nova
}

void remover(reg *lst){
    // verificar se existem elementos na pilha
    // navegar até o topo da pilha
    // apontar a penúltima posição para NULL
    // liberar memória (apagar) da posição topo

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

void mostrar(reg *lst){
    // verificar se a lista está vazia
    // navegar por toda a lista imprimindo
    lst = lst->prox;
    while (lst != NULL) {
        printf("valor: %i\n", lst->val);
        lst = lst->prox;
    }
}


