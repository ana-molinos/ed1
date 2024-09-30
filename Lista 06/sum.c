#include "list.h"

/* */
int sum (List *l) {
  //eh necessario zerar s, pois na ultima chamada recursiva, a função n entrara no if, portanto
  //vai retornar o valor de s como lixo se ele n tiver sido inicializado como 0!
  int s = 0;

  if(l != NULL)
  {
    s = l->data + sum(l->next);
  }

  return s;
}

/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 5; k <= 9; k++) {
    l = insert_back (l, k);
  }
  for (k = 4; k >= 0; k--) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("Sum = %d\n", sum(l));
  destroy (l);
  return 0;
}
