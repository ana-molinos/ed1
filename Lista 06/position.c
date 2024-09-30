#include "list.h"
#include <limits.h>

/* */
int position (List *l, int k) {
  int pos; //rever
  
  //enquanto a lista nao acabar...
  if(l!=NULL)
  {
    //se é diferente do k procurado, continua procurando:recursividade....
    if(l-> data != k)
    {
      pos = position(l->next, k);
      
      //depois de voltar da recursivida, testa: se é -1, eu sei que não encontrei o k e quero manter
      //esse retorno até o voltar todas as chamadas
      if(pos == -1)
        return -1;

      //caso contrario: o incremento da posição se relaciona com o retorno da funçao (um inteiro)
      return (pos + 1);
    }
    //se encontrou o k, retorna a "posição atual" 
    else
    {
      return 0;
      //retorna a "posição zero" e ai cada próximo retorno irá equivaler a +1 posição
    }

  }
  else 
    return -1;
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
  printf("Position of %d = %d\n", 9, position(l, 9));
  printf("Position of %d = %d\n", 10, position(l, 10));
  destroy (l);
  return 0;
}
