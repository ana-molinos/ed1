#include "list.h"

/* */
List* create () {
  return NULL;	
}

/* */
List* insert (List *l, int elem) {
  List *node = (List *)malloc(sizeof(List));
  node->data = elem;
  node->next = l;
  return node;
}

/* */
List* insert_back (List *l, int elem) {
  List *t;
  t = l;

  //aloca espaço de memória para o próx. 
  List *node = (List*)malloc(sizeof(List));

  //inicia o nó com o elemento passado por parametro e o próximo como NULL pois é a cauda
  node->data = elem;
  node->next = NULL;

  //testa se a lista esta vazia, caso esteja, é retornado node, ou seja a cabeça recebe o nó criado
  if(l == NULL)
  {
    return node;
  }
  
  //procura o elemento cujo proximo é nulo
  while(t->next != NULL)
  {
    t = t->next;
  }
  //(só é possível fazer isso porque me certifiquei que o 1o elem existe com o if!)

  //faz o último elemento da fila apontar para o novo último elemento
  t->next = node;

  return l; //retorna a cabeça da lista
}

/* */
List* search (List *l, int elem) {
  if (l != NULL) {
    List *t = l;	   
    while (t != NULL) {
      if (t->data == elem) 
        return t;
      t = t->next;
    }  
  }
  return NULL;  
}

/* */
List* removek (List *l, int elem) {
  List *t = l, *p = NULL;
  while ((t != NULL) && (t->data != elem)) {
    p = t;
    t = t->next;    
  } 
  if (t == NULL) { return l; }
  if (p == NULL) { l = t->next; }
  else { p->next = t->next; }
  free (t);
  return l;
}

/* */
void print (List *l) {
  List *t;
  printf ("List: ");
  for (t = l; t != NULL; t = t->next)
    printf ("%d ", t->data);
  printf("\n");
}

/* */
void destroy (List *l) {
  if (l != NULL) {	
    List *t = l->next; 
    free (l); 
    l = t;    
  }  
}
