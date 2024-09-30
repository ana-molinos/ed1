#include "list.h"

List* split (List *l, List *x, List *y) {
  List* l2 = NULL;
  if(x!=NULL && y!=NULL)
  {
    //conecta as partes que sobram da lista original
    x->prev->next = y->next;
    y->next->prev = x->prev;

    //desconecta o trecho cortado da lista original
    x->prev = NULL;
    y->next = NULL;

    //define a cabeça da nova lista
    l2 = x;
  }

  return l2;
}

int main () {
  int i;	
  int n = 9;	
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  List *x = search (l, 3);
  List *y = search (l, 7);
  List *ls = split (l, x, y);
  print (l);
  print (ls);
  destroy (l);
  destroy (ls);
  return 0;
} 
