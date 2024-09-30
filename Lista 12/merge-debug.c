#include "utils.h"

/*Função intercala*/
int merge (int A[], int l, int m, int r, int O[], int rlevel) {
  int i, j, k;
  i = l; //iterador que vai navegar na parte esquerda do vetor de origem
  j = m+1; //iterador que vai navegar na parte direita do vetor de origem
  k = l; //iterador que vai navegar no vetor auxiliar

  //percorre a direita e a esquerda do vetor A, comparando e ordenando seus valores no vetor O
  while(i<=m && j<=r)
  {
    //se o valor da esquerda é menor...
    if(A[i] <= A[j])
      O[k++] = A[i++];
      //...copia ele para o vetor O e atualiza os iteradores
    //se o valor da direita é menor
    else
      O[k++] = A[j++];
      //copia ele para o vetor O e atualiza os iteradores
  }

  //laços responsáveis por copiarem para o vetor O o restante do lado que "sobrou" sem ser comparado
  while(i<=m)
  {
    O[k++] = A[i++];
  }
    

  while(j<=r)
  {
    O[k++] = A[j++];
  }

  //copia os valores ordenados do vetor O para o vetor A
  for(i = l; i<=r; i++)
    A[i] = O[i];

  //parte que imprime o subvetor que foi ordenado
  for(int p=0; p<rlevel; p++)
    printf("  ");

  printf("Intercalando = {");
  for(int p=l; p<=r; p++)
    printf("%d, ", A[p]);

  printf("}\n");
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort (int A[], int l, int r, int O[], int rlevel) {
  int middle;

  middle = (r+l)/2;

  //parte que imprime a recursão (chamada da função)
  for(int i=0; i<rlevel; i++)
    printf("  ");

  printf("Merge-sort(%d, %d, %d)\n", l, middle, r);
  
  //se a esquerda for menor que a direita(ou seja, se o vetor tiver mais de um elemento)...
  if(l<r)
  {
    /*-------------- DIVISÃO -----------------*/
    //recursão para a esquerda
    merge_sort(A, l, middle, O, rlevel+1);
    //recursão para a direita
    merge_sort(A, middle+1, r, O, rlevel+1);
    
    /*-------------- CONQUISTA ----------------*/
    //ordenção do vetor (na volta da recursão)
    merge(A, l, middle, r, O, rlevel+1);
  }
  
}

/* */
int main ( ) {
  clock_t start, end;
  double elapsed_time;
  int n = 8; /*quantidade de elementos*/
  int A[] = {5, 2, 7, 4, 8, 1, 9, 8};
  int O[n];  /*vetor auxiliar*/
  start = clock();
  //print (A, n, "Input");
  merge_sort (A, 0, n-1, O, 0);
  //print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}

