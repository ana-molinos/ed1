#include "stack.h"

Stack* create () {
  return NULL;
}

void destroy (Stack *s) {
  Stack* aux;
  while(!empty(s))
  {
    aux = s->next;
    free(s);
    s = aux;
  }
}

Stack* push (Stack *s, int elem) {
   Stack* node = (Stack*) malloc(sizeof(Stack)); //1. alocar espaço pro nó criado
  //2. preencher o no
  node->data = elem;
  node->next = s; //aponta para a cabeça atual

  return node; //3. atualizar a cabeça com o novo nó
}

Stack* pop (Stack *s) {
  
  Stack* aux;
  if(!empty(s))
  {
    aux = s->next;
    free(s);//1. remover 1º nó
    s = aux;//2. atualizar a cabeça
  }

  return s;
}

int get_peek (Stack *s) {
  if(!empty(s))
  {
    return s->data;
  }
}

//retorna 1 se a pilha estiver vazia, e 0 caso contrario
int empty (Stack *s) {
  return (s==NULL);
}

void print (Stack *s) {
  if(!empty(s)){
    printf("peek ");
    for(Stack* aux = s; aux!=NULL; aux=aux->next)
      printf("%d ", aux->data);
  }
  else
    printf("Lista vazia!");
}
