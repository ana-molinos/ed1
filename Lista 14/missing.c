#include "utils.h"

/* */
//n = tamanho do vetor
//m = valor maximo que um elemento pode ter no vetor +1
//dúvida: qual a funcionalidade do parametro m na função???
int missing_number (int *A, int n, int m) {
  int left, right, middle;
  left = 0;
  right = n-1;

  while(left<=right)
  {
    middle = (right+left)/2;
    //se o elemento do meio corresponde com sua posição...
    if(A[middle]==middle)
      //...significa não falta nenhum numero antes (à esquerda) dele, portanto, analisa à direita
      left = middle + 1;
    else //caso contrario...
      right = middle - 1; //analisa à esquerda procurando o faltante
  }
  //retorna a posição da esquerda pq ela sempre vai estar alinhada com o elemento faltante
  return left;
} 

/* */
int main () {
  int i;
  //int n = 4, m = 4;
  //int A[] = {0,1,2,3};
  //int n = 4, m = 12;
  //int A[] = {4,5,10,11};
  //int n = 7, m = 16;
  //int A[] = {0,1,2,6,9,11,15};
  //int n = 8, m = 16;
  //int A[] = {1,2,3,4,6,9,11,15};
  //int n = 7, m = 7;
  //int A[] = {0,1,2,3,4,5,6};
  int n = 9, m = 11;
  int A[] = {0,1,2,3,4,5,6,7,10};
  print (A, n, "Input");
  printf("Missing number: %d\n", missing_number (A, n, m));
  return 0;
}
