#include "utils.h"

/*Efeito da otimização: o algoritmo aplicado aos valores ordenados em ordem crescente ou decrescente 
  respondeu em um tempo muito menor. No entanto, para os valores iguais, a aleatoriedade do pivot
  não surte efeito, uma vez que nenhuma comparação é descartada, independentemente do pivot.*/

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
int random_partition (int A[], int left, int right) {
  //Sorteia aleatoriamente um pivo que esteja entre left e right
  int rand_pivot_pos = (rand()%(right-left+1))+left;

  //Troca o elemento da direita com o elemento da posição do pivo sorteado
  swap(A, rand_pivot_pos, right);

  //Realiza a partição com o elemento da direita atualizado
  return partition (A, left, right);
}

/* */
void quick_sort (int *A, int left, int right) {
  int pivot_position;
  
  //enquanto a posição da esquerda for menor que a posição da direita
  //ou seja, enquanto houver elementos para ordenar
  if(left<right)
  {
    //realiza a partição "ordenando o meio" 
    pivot_position = random_partition(A, left, right);
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
  int n = 1000000; /*Altere para 100, 1000, 10 mil, 1 milhao elementos!*/
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

