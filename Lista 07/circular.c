#include "list.h"

List* create_circular (List *head) {
  if(head != NULL)
  {
    //encontra o ultimo elemento
    List* aux = head;
    while(aux->next != NULL)
      aux = aux->next;

    //a cabeça conecta na cauda
    head->prev = aux;

    //a cauda conecta na cabeça
    aux->next = head;
  }

  return head;
}

int main () {
  int i;	
  int n = 4;	
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  l = create_circular(l);
  print (l);
  destroy (l);
  return 0;
} 
