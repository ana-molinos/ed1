#include "list.h"
#include <limits.h>

/* */
int in (List *l, int k) {
  
  //se não está no final da fila...
  if(l!=NULL)
  {
    if(l->data == k) //se encontrei o k, retorno 1
      return 1;
    else
      in(l->next, k); //se não encontrei, recursividade
  } 
  else //se está no final da lista, o elemento n faz parte da lista
    return 0;
}

/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 0; k <= 5; k++) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("In = %d\n", in(l,3));
  printf("In = %d\n", in(l,6));
  destroy (l);
  return 0;
}
