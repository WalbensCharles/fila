//encadeada silple 
#include <stdio.h>
#include <stdlib.h>
//criar um tipo de item isso facilitar a mudar o tipo de item
typedef int Item;

//criar a estrutura de uitem
typedef struct TQueue{
    Item item;
    struct TQueue *next;
}EQueue;

typedef struct{
    EQueue *head;
    EQueue *tail;
}Queue;

void initQueue(Queue *queue){
    queue->head=NULL;
    queue->tail=NULL;
}

int isEmpty(Queue *queue){
    return (queue ->head==NULL);
}

int deQueue(Queue *queue ){
    if(isEmpty(queue)) return -1;
    int i=queue ->head->item;
    EQueue *aux=queue->head;
    //desencadeia o no
    if(queue->head==queue->tail){
        queue->head=queue->tail=NULL;
    }else{
        queue->head=queue->head->next;

    }
    free(aux);
    return(i);                                                                   
}
//retorna uma copia de um nodo dequeueReturnNodo
EQueue *deQueueRN(Queue *queue){
    //EQueue *aux;
    EQueue *aux = (EQueue*)malloc(sizeof(EQueue));

    if(isEmpty(queue)){
        aux->next=NULL;
        aux->item=-1;
        return aux;
    }
    
    EQueue *nodeToFree=queue->head;
    aux->item=queue->head->item;
    
    //remove primeiro elemneto da lista
    if(queue->head==queue->tail){
        initQueue(queue);
    }else{
        queue->head=queue->head->next;

    }
    free(nodeToFree);
    return aux;

}

