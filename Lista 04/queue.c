#include "queue.h"

Queue* create () {
  return NULL; //n tem elementos, logo, a cabeça é aterrada (não precisa alocar aqui!)
}

void destroy (Queue *q) {
  while(q!=NULL){
    Queue* aux = q->next;
    free(q);
    q = aux;
  }
}

int empty (Queue *q) {
  return (q==NULL);
}

//entra no final da lista
Queue* enqueue (Queue *q, int elem) {
  Queue* node = (Queue*)malloc(sizeof(Queue)); //cria o nó
  node->data = elem;//passa o conteudo para o no
  node->next = NULL;//aterra o ponteiro para prox pois ele será o ultimo nó da fila/lista

  if(empty(q))
    return node; //se a fila está vazia, a fila se torna o próprio nó

  Queue* aux = q;
  while(aux->next!=NULL)
  {
    aux = aux->next; //assim o t percorre a fila
  }
  aux->next = node;
  return q;
}

Queue* dequeue (Queue *q) {
   Queue* aux;
   if(!empty(q)) 
   {
    aux = q->next;
    free(q);
    q = aux;
   }

  return q;
}

int get_front (Queue *q) {
  if(!empty(q))
    return q->data;

}

void print (Queue *q) {
  for(Queue* aux = q; aux!=NULL; aux = aux->next)
  {
    printf("%d ", aux->data);
  }

  printf("(fim)\n");

}

