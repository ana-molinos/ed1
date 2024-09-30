#include "list.h"

/**/
List* create () {
  return NULL;	
}

/**/
List* insert_front (List *l, int elem) {
  List *node = (List *)malloc(sizeof(List));
  node->data = elem;
  node->next = l;
  node->prev = NULL;
  if (l != NULL) 
    l->prev = node;
  return node;
}

/**/
List* insert_back (List *l, int elem) {
  //aloca memoria para o nó
  List* node = (List*) malloc(sizeof(List));

  //organiza o nó
  node->data = elem;
  node->next = NULL;
  
  //se a lista não estiver vazia...
  if(l!=NULL)
  {
    //percorre ate encontrar o ultimo elemento
    List* aux = l;
    while(aux->next != NULL)
      aux = aux->next;

    //conecta o ultimo elemento com o elemento adicionado e vice-versa
    aux->next = node;
    node->prev = aux;
  }
  //se a lista estiver vazia...
  else
  {
    //transforma o no na cabeça da lista
    node->prev = NULL;
    l = node;
  }

  return l;
  
}

/**/
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

/**/
List* remove_queue (List *l, int elem) {
  List *node = search (l, elem);
  if (node == NULL) { return l; }
  List *a = node->prev;
  List *s = node->next;
  if (l == node) { l = s; }
  if (s != NULL) { s->prev = a; }
  if (a != NULL) { a->next = s; }
  free(node);
  return l;
}

/**/
void print (List *l) {
  List *t, *last;
  printf ("List (front-to-back): {");
  for (t = l; t != NULL; t = t->next) {
    if (t->next != NULL)	  
       printf ("%d, ", t->data);
    else
       printf ("%d", t->data);
    last = t;
  }  
  printf("}\n");
  printf ("List (back-to-front): {");
  for (t = last; t != NULL; t = t->prev) {
    if (t->prev != NULL)	  
       printf ("%d, ", t->data);
    else
       printf ("%d", t->data);
  }  
  printf("}\n");
}

/**/
void destroy (List *l) {
  if (l != NULL) {	
    List *t = l->next; 
    free (l); 
    l = t;    
  }  
}
