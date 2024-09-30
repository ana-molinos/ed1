#include "utils.h"

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

int random_partition (int A[], int left, int right) {
  //Sorteia aleatoriamente um pivo que esteja entre left e right
  int rand_pivot_pos = (rand()%(right-left+1))+left;

  //Troca o elemento da direita com o elemento da posição do pivo sorteado
  swap(A, rand_pivot_pos, right);

  //Realiza a partição com o elemento da direita atualizado
  return partition (A, left, right);
}

/* */
void quick_find (int *A, int left, int right, int k) {
  int pivot_position;
  
  //enquanto a posição da esquerda for menor que a posição da direita
  //ou seja, enquanto houver elementos para ordenar
  if(left<right)
  {
    //realiza a partição "ordenando o meio" 
    pivot_position = random_partition(A, left, right);
    
    //abre a ordenação recursivamente na direção em que k se encontra
    //ou seja, se k está na metade direita, recursão p/ direita, caso contrário, p/ esquerda
    if(k < pivot_position)
      quick_find(A, left, pivot_position-1, k);
    else if(k > pivot_position)
      quick_find(A, pivot_position+1, right, k);

  }		
}

/* */
int main () {
  int n = 9, k=4;
  int A[] = {7, 1, 3, 10, 17, 2, 21, 9, 3};
  print (A, n, "Input");
  quick_find (A, 0, n-1, k);
  print (A, n, "Partial sorted");
  printf("para k = %d, k-esimo elemento = %d\n", k, A[k]);
  return 0;
}
