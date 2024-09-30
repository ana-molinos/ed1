#include "queue.h"

int main () {
  int i = 0, n = 10, num;	
  /*Use somente as operações definidas em queue.h*/
  /*Não use para resolver esse exercício o operador -> aqui!*/
  /*Terminar*/

  Queue *par = create(n);
  Queue *impar = create(n);

  while(i<n){

      num = rand() % 100;

      if(num%2) // num%2 != 0 se for impar
        enqueue(impar, num);
      else
        enqueue(par, num);

      i++;
  }

  printf("Lista par:\n");
  print(par);
  printf("Lista impar:\n");
  print(impar);

  destroy(par);
  destroy(impar);

  return 0;
}

