#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Fila: Insere no final e remove do início.

/*Faça um programa em C para simular um controlador de voo de um aeroporto. Neste programa o
usuário deve ser capaz de realizar as seguintes tarefas:
• Listar o número de aviões esperando para decolar; -> Percorrer a fila de decolagem e fazer um count.
• Listar o número de aviões esperando para pousar; -> Percorrer a fila de pouso e fazer um count.
• Autorizar a decolagem do primeiro avião na fila de decolagem; -> Remove início fila decolagem.
• Autorizar o pouso do primeiro avião na fila de pouso; -> Remove início fila pouso.
• Adicionar um avião na fila de espera para decolagem; -> Inserir final decolagem.
• Adicionar um avião na fila de espera para pouso; -> Inserir final pouso.
• Listar todos os aviões que estão na fila de espera para decolagem, por ordem de chegada;  -> Percorrer toda a fila de decolagem.
• Listar todos os aviões que estão na fila de espera para pouso, por ordem de chegada; -> Percorrer toda a fila de pouso.
• Listar as características do primeiro avião da fila, antes de autorizar a sua decolagem; -> Dar um print nos dados armazenados no primeiro nodo da fila.
• Listar as características do primeiro avião da fila, antes de autorizar o seu pouso; -> Dar um print nos dados armazenados no primeiro nodo da fila. */

/* Cada avião possui um nome, um identificador, uma origem e um destino. Se quiser coloque
mais informações, número de passageiros, capacidade, modelo, etc. */


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

Nodo * Cria_Aviao(){//aloca memória para o nodo
    Nodo *p;
    p = (Nodo *) malloc(sizeof(Nodo));
    if(!p){
        printf("Problema de alocação");
        exit(0);
    }
    return p;
}

void insere_fim_fila(Nodo **N, int id, char nome[30], char origem[40], char destino[40]){
    Nodo *novo_aviao, *aux;
    novo_aviao = Cria_Aviao( );
    novo_aviao->identificador = id;
    strcpy(novo_aviao->nome, nome); //Primeiro parametro é onde vai armazenar e o segundo é o dado a ser inserido.
    strcpy(novo_aviao->origem, origem);
    strcpy(novo_aviao->destino, destino);
    novo_aviao->prox = NULL;
    if(*N == NULL) //Se a lista estiver vazia.
        *N = novo_aviao; //Esse vai ser o primeiro endereço.
    else{
        aux = *N;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo_aviao;
    } //Não precisa mudar o N porque ele sempre aponta para o PRIMEIRO endereço e aqui ta sendo inserido o último.
}


int remove_inicio_fila(Nodo **N, int *id){
    Nodo *aux;
    if(*N == NULL) //verifica se a lista está vazia
        return 0;
    else{
        *id = (*N)->identificador;
        aux = (*N)->prox;
        free(*N);
        *N = aux; //Tem o novo aviao a decolr/pousar
    }
    return 1;
}


void imprime_fila(Nodo *N){
    Nodo *aux;
    if(N == NULL)
        printf("\n\nNao ha nenhum aviao na fila!");
    else{
        for(aux = N; aux != NULL; aux = aux->prox)
            printf("\n\n   AVIAO %d:\n\nIdentificador: %d \nNome: %s \nOrigem: %s \nDestino: %s", aux->identificador, aux->identificador, aux->nome, aux->origem, aux->destino);
    }
}

int conta_aviao(Nodo *N){
    Nodo *aux;
    int cont=0;
    if(N == NULL) //A fila está vazia.
        return 0;
    else{//Se a fila possui NODOS
        for(aux = N; aux != NULL; aux = aux->prox) //Começa do primeiro endereço enquanto prox diferente de NULL (fim da fila), indo sempre para posicao armazenada no prox
            cont++; //Contador para saber quantos elementos tem.
    }
    return cont;
}

void imprime_aviao(Nodo *N){
    Nodo *aviao;
    aviao = N;
    if(N == NULL)
        printf("\n");
    else
        printf("\n\nIdentificador: %d \nNome: %s \nOrigem: %s \nDestino: %s", aviao->identificador, aviao->nome, aviao->origem, aviao->destino);
}

void desenha_decolagem(){
              printf("\n\n   __|__              __|__ ");
                printf("\n*---oOo---*        *---oOo---*  ");
                printf("\n_____________________________________*_*_*_*___");
				printf("\n\n"); 	
}

void desenha_pouso(){
	          printf("\n\n                   _ .");                  
                printf("\n                 (  _ )_");
                printf("\n                (_  _(_ ,)"); 
                printf("\n        __|__");   
                printf("\n     *---oOo---*");    
                printf("\n"); 
                printf("\n     _ ."); 
                printf("\n   (  _ )_");
                printf("\n (_  _(_ ,)"); 
                printf("\n\n");
}

void desenha_nuvem(){
	printf("\n                   _ .");                  
    printf("\n                 (  _ )_");
    printf("\n                (_  _(_ ,)"); 
    printf("\n");
    printf("\n"); 
    printf("\n     _ ."); 
    printf("\n   (  _ )_");
    printf("\n (_  _(_ ,)");
    printf("\n\n\n\n\n____*_*_*_*__________*_*_*_*_________*_*_*_*___");
}

int main(){
    Nodo *Decolagem;
    Nodo *Pouso;
    int menu, id, cont, resp;
    char nome[30], origem[40], destino[40];
    inicializa_fila(&Decolagem);
    inicializa_fila(&Pouso);
    do{
    	system("cls");
    	printf("\n                     __|__");
printf("\n            __|__ *---oOo---*"); 
printf("\n   __|__ *---oOo---*");
printf("\n*---oOo---*"); 
printf("\n\n\n");
    	printf("               CONTROLADOR DE VOO");
        printf("\n\n1. Adicionar aviao na fila para decolagem");
        printf("\n2. Adicionar aviao na fila para pouso");
        printf("\n3. Ver os avioes esperando para decolar");
        printf("\n4. Ver os avioes esperando para pousar");
        printf("\n5. Quantidade de avioes esperando para decolar");
        printf("\n6. Quantidade de avioes esperando para pousar");
        printf("\n7. Autorizar a decolagem"); //MOSTRAR AS INFORMAÇÕES ANTES DE DECOLAR
        printf("\n8. Autorizar o pouso"); //MOSTRAR AS INFORMAÇÕES ANTES DE POUSAR
        printf("\n9. Sair\n");
        printf("\n\nNumero: ");
        scanf("%d", &menu);
        switch(menu){
            case 1: //Insere no FIM Decolagem
                system("cls");
                printf("\n   AVIAO ESPERANDO PARA DECOLAR:");
                desenha_decolagem();
                printf("\nNumero identificador: ");
                scanf(" %d", &id);
                getchar(); //Limpa o buffer do scanf
                printf("\nNome: ");
                gets(nome); //Nome já é endereço porque é um vetor.
                printf("\nOrigem: ");
                gets(origem);
                printf("\nDestino: ");
                gets(destino);
                insere_fim_fila(&Decolagem, id, nome, origem, destino);
                printf("\n\n\n\n"); 
                system("pause");
                break;
            case 2: //Insere no FIM Pouso
                system("cls");
                printf("\n   AVIAO ESPERANDO PARA POUSAR:");
                desenha_pouso();
                printf("\n\nNumero identificador: ");
                scanf("%d", &id);
                getchar();
                printf("\nNome: ");
                gets(nome); //Nome já é endereço porque é um vetor.
                printf("\nOrigem: ");
                gets(origem);
                printf("\nDestino: ");
                gets(destino);
                insere_fim_fila(&Pouso, id, nome, origem, destino);
                printf("\n\n\n\n"); 
                system("pause");
                break;
            case 3: //Imprime fila Decolagem
                system("cls");
                printf("   FILA PARA DECOLAGEM:");
                imprime_fila(Decolagem);
                printf("\n\n\n\n"); 
                system("pause");
                break;
            case 4: //Imprime fila Pouso
                system("cls");
                printf("   FILA PARA POUSO:");
                imprime_fila(Pouso);
                printf("\n\n\n\n"); 
                system("pause");
                break;
            case 5: //Conta aviao Decolagem
                system("cls");
                printf("     DECOLAGEM");
                cont = conta_aviao(Decolagem);
                if (cont == 0){
                    desenha_nuvem();
                    printf("\n\nNao ha avioes esperando para decolar!");
                }else{
                    desenha_decolagem();
                    printf("\n\nO numero de avioes esperando para decolar eh de: %d", cont);
                }
				printf("\n\n\n\n"); 
                system("pause");
                break;
            case 6: //Conta avião pouso
                system("cls"); 
				printf("     POUSO");            
                cont = conta_aviao(Pouso);
                if (cont == 0){
                    desenha_nuvem();
                    printf("\n\nNao ha avioes esperando para pousar!");
                }else{
                    desenha_pouso();
                    printf("\n\nO numero de avioes esperando para pousar eh de: %d", cont);
			    }
				printf("\n\n\n\n"); 
                system("pause");
                break;
            case 7: //Imprimir primeiro NODO Decolagem e remove inicio fila Decolagem
                system("cls");
                printf("   INICIAR DECOLAGEM");
				imprime_aviao(Decolagem);
                if(remove_inicio_fila(&Decolagem,&id) == 0){
                    desenha_nuvem();
                    printf("\n\nNao ha ninguem na fila para decolar!");
                }else{
                    desenha_decolagem();
                    printf("\n\nO aviao %d esta decolando ", id);
                }
				printf("\n\n\n\n"); 
                system("pause");
                break;
            case 8: //Imprimir primeiro NODO Pouso e remove inicio fila Pouso.
                system("cls");
                printf("   INICIAR POUSO");
				imprime_aviao(Pouso);
                if(remove_inicio_fila(&Pouso,&id) == 0){
                    desenha_nuvem();
					printf("\n\nNao ha ninguem na fila para pousar!");
                }else{
                    desenha_pouso();
                    printf("\n\nO aviao %d esta pousando", id);
                }
				printf("\n\n\n\n"); 
                system("pause");
                break;
            case 9: //Sair
                printf("\n\n\nSaindo do controlador de voo!");
                break;
            default:
                printf("\nOpcao Invalida!!");
        }
    }while(menu != 9);
    return 0;
}
