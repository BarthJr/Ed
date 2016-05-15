// Autores: João Moacir Barth Junior
//          Cynthia Rocha de Oliveira

#include<stdio.h>
#include<stdlib.h>
#include <dos.h>
#include <windows.h>
#define M 30 //Dimensão Máxima da matriz
#define ML 4 //Quantidade de movimentos possiveis
#define livre ' '
#define parede 219
#define beco '-'
#define rato 1
#define visitada '.'

typedef struct Bloco{
    int dado;
    struct Bloco *prox;
} Nodo;

Nodo *Stack;
char w[M][M];
int vlin[4]={1,0,-1,0};
int vcol[4]={0,1,0,-1};

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){y-1,x-1});
}

void inicializa_pilha(Nodo **N){//inicializa a pilha
    *N = NULL;
}
Nodo * Cria_Nodo(){//aloca memoria para o nodo
    Nodo *p;
    p = (Nodo *) malloc(sizeof(Nodo));
    if(!p){
        printf("Problema de alocacao");
        exit(0);
    }
    return p;
}
void push(Nodo **N, int dado) {
    Nodo *novo;
    novo = Cria_Nodo();
    novo->dado = dado;
    novo->prox = *N;
    *N = novo;
}
int pop(Nodo **N){
    Nodo *aux;
    if(*N == NULL) //verifica se a lista esta vazia
        return 0;
    else{
        aux = (*N)->prox;
        free(*N);
        *N = aux;
    }
    return 1;
}
void preenche_borda(){
    int i,j;
    for(j=1; j<=M; j++) //Preenche a primeira linha
        w[1][j]=parede;
    for(j=1; j<=M; j++) //Preenche a ultima linha
        w[M][j]=parede;
    for(i=2;i<M; i++) // Preenche a primeira coluna
        w[i][1]=parede;
    for(i=2;i<M;i++) // Preenche a ultima coluna
        w[i][M]=parede;
}
void inicializa_matriz(){
    int i,j,random;
    preenche_borda();
    for(i=2; i<M; i++) //Preenche conteudo da matriz
        for(j=2; j<M; j++){
            random = rand()%900;
            if(random>200)
                w[i][j]=livre;
            else
                w[i][j]=parede;
        }
    w[2][2]=rato;
    w[M-1][M]=livre;
    //w[4][2]=parede;
    //w[4][3]=parede;
    //w[2][4]=parede;
    //w[3][4]=parede;
}
int tem_caminho(Nodo **Stack,int i){
    int lin,col,aux;
    lin=((*Stack)->dado)/100;
    col=((*Stack)->dado)%100;
    lin+=vlin[i];
    col+=vcol[i];
    if(w[lin][col]==livre){
        aux=lin*100+col;
        return aux;
    }else
        return 0;
}
void procura_saida(Nodo **Stack){
    int i,j,lin,col,ok,acaba=0,cont=0,coord,x1,y1,x2,y2;
    Nodo *aux;
        lin=((*Stack)->dado)/100;
        col=((*Stack)->dado)%100;
        //printf("Coordenada recebida: %d\n\n",coord);
        for(i=0;i<ML;i++){
            ok=tem_caminho(Stack,i);
            if(ok)
               break;
        }
        //printf("Coordenadassss: %d %d\n",ok,i);
        if(ok){
            w[lin][col]=visitada;
            w[ok/100][ok%100]=rato;
            push(Stack,ok);
            if(Stack){
                x1=((*Stack)->dado)/100;
                y1=((*Stack)->dado)%100;
                gotoxy(x1,y1);
                printf("%c",rato);
            }
            aux=(*Stack)->prox;
            x2=((aux)->dado)/100;
            y2=((aux)->dado)%100;
            gotoxy(x2,y2);
            printf("%c",visitada);
        }
        else{
            w[lin][col]=beco;
            gotoxy(lin,col);
            printf("%c",beco);
            aux=(*Stack)->prox;
            if(aux){
                x1=((aux)->dado)/100;
                y1=((aux)->dado)%100;
                gotoxy(x1,y1);
                printf("%c",visitada);
            }
            pop(Stack);
            if(*Stack){
                x1=((*Stack)->dado)/100;
                y1=((*Stack)->dado)%100;
                w[x1][y1]=rato;
                gotoxy(x1,y1);
                printf("%c",rato);

            }
        }
}
void imprime_matriz(){
    int i,j;
    for(i=1; i<=M; i++){
        for(j=1; j<=M; j++)
            printf("%c",w[i][j]);
        printf("\n");
    }
    printf("\n");
}
void main(){
    int lin,col,aux,i,x1,y1,x2,y2;
    Nodo *aux1;
    srand( (unsigned)time(NULL) ); //Responsável por gerar uma matriz nova a cada vez
    inicializa_matriz();
    imprime_matriz();
    inicializa_pilha(&Stack);
    push(&Stack,202);
    do{
        procura_saida(&Stack);
        Sleep(20);
    }while(Stack!=NULL && Stack->dado != (M-1)*100+M);
    if(!Stack){
        gotoxy(2,2);
        printf("%c",rato);
        w[2][2]=rato;
    }
    system("cls");
    imprime_matriz();
    if(!Stack){
        printf("Labirinto sem saida!!\n");
    }else
        printf("Parabens conseguiu sair do labirinto!!\n");
}
