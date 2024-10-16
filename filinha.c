#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fila{
    char nome[10];
    struct Fila *next;
};
typedef struct Fila fila;

//funcao inserir
void inserir(fila **f, char *no){
    fila *novo=malloc(sizeof(fila));
    if(novo){//verifica se o alocacao feito
        strcpy(novo->nome ,no); //copia o nome para o novo no
        novo->next=NULL;

        //verifica se lista esta vazia
        if(*f==NULL){
            *f=novo; // o novo no e o primeiro se a fila estiver vazia
        }else{
            fila *aux=*f;
            while(aux->next!=NULL){
                aux=aux->next; //ate encontra o ultimo no na fila
            }
            aux->next=novo; // adiciona o novo no na final da lista
        }

    }else{
        printf("erro ao aloca memoria");
    }
}

//funcao para imprimir na lista
void imprimir(fila *f){
    fila *aux=f;
    while(aux != NULL){
        printf("%s",aux->nome);
        aux=aux->next;
    }
}
 //funcao para libera memoria

 void liberar(fila *f){
    fila* aux=f;
    while(aux!=NULL){
        fila *temp =aux->next;
        free(aux);
        aux=temp;
    }
 }

int main(){
    fila *minhafila=NULL;
    char let[10];
    int num;
    printf("quantas letras quer digitar : ");
    scanf("%d",&num);

    //inserir letras
    for(int i=0; i<num; i++){
        scanf("%s",&let);
        inserir(&minhafila,let);
    }
    imprimir(minhafila);

    liberar(minhafila);

    return 0;

}