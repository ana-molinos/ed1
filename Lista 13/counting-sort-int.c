#include "utils.h"

/* */
void counting_sort (int *A, int n, int range) {
  int i, j;
  
  /*Alocando vetores auxiliares: */
  int *T = (int *)malloc(n * sizeof(int)); /*temporário*/
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/

  //zera o vetor contador
  for(i=0; i<=range; i++)
    C[i]=0;

  //conta o numero de ocorrencias de cada numero no vetor A
  for(j=0; j<n; j++)
    C[A[j]]++;

  //atualiza o vetor contador com a posição de cada numero
  //(se baseia em quantos numeros "vem antes" do numero observado, o acumulado)
  for(i=1; i<=range; i++)
    C[i] += C[i-1];

  //ordena os valores no vetor auxiliar com base em suas posições
  for(j=n-1; j>=0; j--)
  {
    //1: olha para o conteúdo de A[j]
    //2: procura esse numero no vetor contador (como indice)
    //3: define a posição ordenada dele como o conteudo presente no vetor contador -1
    T[C[A[j]]-1] = A[j]; 
    //atualiza o vetor contador
    C[A[j]]--;
  }

  for(i=0; i<n; i++)
    A[i] = T[i];
  
  /*Desalocando vetores auxiliares: */
  free (T);
  free (C);
}

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
  int n = 10000000; /*Teste com 10, 100K, 1M, ... (n)*/
  int range = 1000000; /*intervalo de valores sorteados (k)*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % range; /*valores aleatórios*/
  }  

  start = clock();
  //print (A, n, "Input");
  counting_sort (A, n, range);
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

