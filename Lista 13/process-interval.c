#include "utils.h"

/* */
//Complexidade O(n+k) k=range
//função que faz o pré processamento
int* process_interval (int *A, int n, int range) {
  int i, j;
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/
  
  //1. contar as ocorrências de todos os elementos no range dado
  for(i=0; i<n; i++)
    C[A[i]]++;

  //2. determinar o acumulado para cada elemento
  for(j=1; j<=range; j++)
    C[j] += C[j-1];

  return C;
}

//Complexidade O(1)
int query (int *C, int n, int i, int j) {
  if(!i)
    return C[j];

  return C[j] - C[i-1];
}

/* */
int main () {
  int a, b, n = 15;
  int range = 10;
  int A[] = {9,2,0,8,7,9,3,2,0,7,5,0,2,6,0};
  print (A, n, "Input");
  int *C = process_interval (A, n, range);
  a = 0, b = 3;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 4, b = 8;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 0, b = 0;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 6, b = 6;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 2, b = 4;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 9, b = 9;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  return 0;
}

