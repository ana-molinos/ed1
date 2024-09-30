#include "list.h"

/* */
int sum (List *l) {
  List *t; //ponteiro temporario
  int sum = 0;

  /*como a lista não é organizada de maneira contígua na memória, não é possível utilizar aritmética
    de ponteiros, por isso, não se utiliza t++, e sim t = t-> next (o ponteiro temporário passa a
    apontar para o endereço de memória do próximo nó da lista)*/
  for(t = l; t != NULL; t = t->next)
  {
    sum += t->data;
  }

  return sum;
}

/* */
int main () {
  int k;
  List *l = NULL;
  for (k = 0; k <= 4; k++) 
    l = insert_back (l, k);
  for (k = 9; k >= 5; k--) 
    l = insert_back (l, k);
  print (l);
  printf("Sum = %d\n", sum(l));
  destroy (l);

  return 0;
}
