#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Fila: Insere no final e remove do in�cio.

/*Fa�a um programa em C para simular um controlador de voo de um aeroporto. Neste programa o
usu�rio deve ser capaz de realizar as seguintes tarefas:
� Listar o n�mero de avi�es esperando para decolar; -> Percorrer a fila de decolagem e fazer um count.
� Listar o n�mero de avi�es esperando para pousar; -> Percorrer a fila de pouso e fazer um count.
� Autorizar a decolagem do primeiro avi�o na fila de decolagem; -> Remove in�cio fila decolagem.
� Autorizar o pouso do primeiro avi�o na fila de pouso; -> Remove in�cio fila pouso.
� Adicionar um avi�o na fila de espera para decolagem; -> Inserir final decolagem.
� Adicionar um avi�o na fila de espera para pouso; -> Inserir final pouso.
� Listar todos os avi�es que est�o na fila de espera para decolagem, por ordem de chegada;  -> Percorrer toda a fila de decolagem.
� Listar todos os avi�es que est�o na fila de espera para pouso, por ordem de chegada; -> Percorrer toda a fila de pouso.
� Listar as caracter�sticas do primeiro avi�o da fila, antes de autorizar a sua decolagem; -> Dar um print nos dados armazenados no primeiro nodo da fila.
� Listar as caracter�sticas do primeiro avi�o da fila, antes de autorizar o seu pouso; -> Dar um print nos dados armazenados no primeiro nodo da fila. */

/* Cada avi�o possui um nome, um identificador, uma origem e um destino. Se quiser coloque
mais informa��es, n�mero de passageiros, capacidade, modelo, etc. */

/*int eita;*/

typedef struct Aviao{
    int identificador;
    char nome[30];
    char origem[40];
    char destino[40];
    struct Aviao *prox;
} Nodo;

void inicializa_fila(Nodo **N){//inicializa a lista
    *N = NULL;
}

Nodo * Cria_Aviao(){//aloca mem�ria para o nodo
    Nodo *p;
    p = (Nodo *) malloc(sizeof(Nodo));
    if(!p){
        printf("Problema de aloca��o");
        exit(0);
    }
    return p;
}

void insere_fim_fila(Nodo **N, int id){ //Passar os par�metros de texto com CHAR NOME[30]
    Nodo *novo, *aux;
    novo = Cria_Aviao( );
    novo->dado = dado;
    novo->prox = NULL;
    if(*N == NULL)
        *N = novo;
    else{
        aux = *N;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}


int remove_inicio_fila(Nodo **N, int *dado){
    Nodo *aux;
    if(*N == NULL) //verifica se a lista est� vazia
        return 0;
    else{
        *dado = (*N)->dado;
        aux = (*N)->prox;
        free(*N);
        *N = aux;
    }
    return 1;
}


void imprime_fila(Nodo *N){
    Nodo *aux;
    if(N == NULL)
        printf("\n A lista est� vazia!!");
    else{
        for(aux = N; aux != NULL; aux = aux->prox)
            printf("\n%d", aux->dado);
    }
}

int conta_aviao(Nodo *N){
    Nodo *aux;
    int cont=0;
    if(N == NULL) //A fila est� vazia.
        return 0;
    else{//Se a fila possui NODOS
        for(aux = N; aux->prox != NULL; aux = aux->prox) //Come�a do primeiro endere�o enquanto prox diferente de NULL (fim da fila), indo sempre para posicao armazenada no prox
            cont++; //Contador para saber quantos elementos tem.
    }
    return cont;
}

int main(){
    Nodo *Decolagem;
    Nodo *Pouso;
    int menu, id, resul;
    inicializa_fila(&Decolagem);
    inicializa_fila(&Pouso);
    do{
        printf("\n1. Adicionar aviao na fila para decolagem");
        printf("\n2. Adicionar aviao na fila para pouso");
        printf("\n3. Ver os avioes esperando para decolar");
        printf("\n4. Ver os avioes esperando para pousar");
        printf("\n5. Quantidade de avioes esperando para decolar");
        printf("\n6. Quantidade de avioes esperando para pousar");
        printf("\n7. Autorizar a decolagem"); //MOSTRAR AS INFORMA��ES ANTES DE DECOLAR
        printf("\n8. Autorizar o pouso"); //MOSTRAR AS INFORMA��ES ANTES DE POUSAR
        printf("\n7. Sair\n");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                printf("\nInforme as seguintes caracteristicas do aviao que ira decolar:");
                printf("\nNumero identificador:");
                scanf("%d", &id);
                printf("\nNome:");
                scanf("%s", nome); //Nome j� � endere�o porque � um vetor.
                printf("\nOrigem:");
                scanf("%s", origem);
                printf("\nDestino:");
                scanf("%s", destino);
                insere_fim_fila(&Decolagem, id, nome, origem, destino);
                break;
            case 2:
                printf("\nInforme o valor a ser inserido no inicio da lista:");
                scanf("%d", &valor);
                insere_inicio_lista(&MyList, valor);
                break;
            case 3:
                if(remove_inicio_lista(&MyList,&valor) == 0)
                    printf("\nA lista est� vazia!!");
                else
                    printf("\nO valor excluido do inicio da lista foi: %d", valor);
                break;
            case 4:
                if(remove_fim_lista(&MyList,&valor) == 0)
                    printf("\nA lista est� vazia!!");
                else
                    printf("\nO valor excluido do fim da lista foi: %d", valor);
                break;
            case 5:
                printf("\nInforme o valor a ser excluido da lista:");
                scanf("%d", &valor);
                resul= remove_elem_lista(&MyList,valor);
                if(resul==0)
                    printf("\nA lista est� vazia!!");
                else if (resul == 1 )
                    printf("\nO valor %d foi excluido da lista!!",valor);
                else
                    printf("\n O valor %d nao foi encontrado",valor);
                break;
            case 6:
                imprime_lista_ecandeada(MyList);
                break;
            case 7:
                printf("\n\n\nSaindo do programa!");
                break;
            default:
                printf("\nOpcao Invalida!!!");
        }
    }while(menu != 7);
    return 0;
}
