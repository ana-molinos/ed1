#include "utils.h"

/*O algoritmo é mais rápido para ordenar valores inicialmente ordenados aleatoriamente.
  Valores que já respeitam uma ordem crescente ou descrescente tornam a execução do algoritmo mais
  ineficiente uma vez que é necessário percorrer a array n² vezes.*/

/* */
int partition (int A[], int left, int right) {
  int pivot = A[right]; //pivot=direita
  int i = left-1;

  //percorre da esquerda até antes da direita (--->)
  for(int j=left; j<=right-1; j++)
  {
    //se o elemento da posição atual é menor que o pivo...
    if(A[j]<=pivot)
    {
      //troca o elemento mais a esquerda dos maiores pelo elemento da posiçao atual
      i++;
      swap(A, i, j);
    }
  }
  
  swap(A, i+1, right);//coloca o pivot na posição no meio 	
  return i+1; //retorna a posição do pivot
}

/* */
void quick_sort (int *A, int left, int right) {
  int pivot_position;
  
  //enquanto a posição da esquerda for menor que a posição da direita
  //ou seja, enquanto houver elementos para ordenar
  if(left<right)
  {
    //realiza a partição "ordenando o meio" 
    pivot_position = partition(A, left, right);
    //abre a ordenação para a esquerda e para a direita recursivamente
    quick_sort(A, left, pivot_position-1);
    quick_sort(A, pivot_position+1, right);
  }	
}

/* */
int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i;
  int n = 100000; /*Altere para 100, 1000, 10 mil, 1 milhao elementos!*/
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    //A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i; /*ordem crescente*/
    //A[i] = n-i; /*ordem descrente*/
    A[i] = 0; /*iguais*/
  }  

  start = clock();
  //print (A, n, "Input");
  quick_sort (A, 0, n-1);
  //print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

