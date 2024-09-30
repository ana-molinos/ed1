#include "list.h"

int meio (List *l) {
  List* aux1 = l;
  List* aux2 = l;

  //aux1 percorre a lista elemento a elemento
  //aux2 percorre a lista de 2 em 2 elementos (quando chega no final, aux1 chega no meio)
  while(aux2 != NULL && aux2->next != NULL)
  {
    aux2 = aux2->next->next;
    aux1 = aux1->next;
  }

  return aux1->data;
}

int main () {
  int i;	
 
  List *l0 = create();
  for (i = 0; i < 3; i++)
    l0 = insert (l0, i);	
  print (l0); 
  printf("Elemento no meio da lista: %d\n", meio(l0));
  destroy (l0);

  List *l1 = create();
  for (i = 0; i < 10; i++)
    l1 = insert (l1, i);	
  print (l1); 
  printf("Elemento no meio da lista: %d\n", meio(l1));
  destroy (l1);

  List *l2 = create();
  for (i = 0; i < 19; i++)
    l2 = insert (l2, i);	 
  print (l2); 
  printf("Elemento no meio da lista: %d\n", meio(l2));
  destroy (l2);

  return 0;
}
