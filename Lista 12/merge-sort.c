#include "utils.h"

/*Função para intercalar dois subvetores em um conjunto ordenado. 
 *{A} é o vetor de entrada, {l} é a esquerda (de left), 
 {m} é o meio (ou middle), {r} é a direita (de right),
 {O} é o vetor auxilar (de output). */
void merge (int A[], int l, int m, int r, int O[]) {
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
}

/*Complexidade para melhor, médio e pior caso: O(n*logn) (com relação a tempo)
  P.S.: esse log é na base 2
  No entanto, com relação a espaço, ele gasta o dobro de memória (2x o numero de amostras), 
  pois necessitade de um vetor auxiliar.*/

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort (int A[], int l, int r, int O[]) {
  int middle;

  //se a esquerda for menor que a direita(ou seja, se o vetor tiver mais de um elemento)...
  if(l<r)
  {
    middle = (r+l)/2;
    
    /*-------------- DIVISÃO -----------------*/
    //recursão para a esquerda
    merge_sort(A, l, middle, O);
    //recursão para a direita
    merge_sort(A, middle+1, r, O);
    
    /*-------------- CONQUISTA ----------------*/
    //ordenção do vetor (na volta da recursão)
    merge(A, l, middle, r, O);
  }	
}

/*TEMPO DE EXECUÇÃO:
valores aleatórios:
1mi: 0.18s
10mi: 2.08

valores em ordem crescente:
1mi: 0.10s
10mi: 1.16s

valores em ordem descrescente:
1mi: 0.10s
10mi: 1.13

valores iguais:
1mi: 0.10s
10mi: 1.15
*/
/*CONCLUSÃO: é mais rápido para valores já ordenados*/

/* */
int main (int argc, char *argv[]) {
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  /*if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }*/
  int i;
  //int n = atoi(argv[1]);
  int n = 10000000; /*teste com 100, 1K, 10K, 1M, 10M*/
  int *A = (int *)malloc(n * sizeof(int));
  int *O = (int *)malloc(n * sizeof(int)); /*array auxiliar*/
  for (i = 0; i < n; i++) {
    //A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i;   /*valores em ordem crescente*/
    //A[i] = n-i; /*valores em ordem descrescente*/
    A[i] = 0;   /*valores iguais*/
  }
  start = clock();
  //print (A, n, "Input");
  merge_sort (A, 0, n-1, O);
  //print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  free (O);
  return 0;
}

